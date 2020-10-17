/*******************************************************************************
* File Name: Start_Switch.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Start_Switch.h"

static Start_Switch_BACKUP_STRUCT  Start_Switch_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Start_Switch_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Start_Switch_SUT.c usage_Start_Switch_Sleep_Wakeup
*******************************************************************************/
void Start_Switch_Sleep(void)
{
    #if defined(Start_Switch__PC)
        Start_Switch_backup.pcState = Start_Switch_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Start_Switch_backup.usbState = Start_Switch_CR1_REG;
            Start_Switch_USB_POWER_REG |= Start_Switch_USBIO_ENTER_SLEEP;
            Start_Switch_CR1_REG &= Start_Switch_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Start_Switch__SIO)
        Start_Switch_backup.sioState = Start_Switch_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Start_Switch_SIO_REG &= (uint32)(~Start_Switch_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Start_Switch_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Start_Switch_Sleep() for an example usage.
*******************************************************************************/
void Start_Switch_Wakeup(void)
{
    #if defined(Start_Switch__PC)
        Start_Switch_PC = Start_Switch_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Start_Switch_USB_POWER_REG &= Start_Switch_USBIO_EXIT_SLEEP_PH1;
            Start_Switch_CR1_REG = Start_Switch_backup.usbState;
            Start_Switch_USB_POWER_REG &= Start_Switch_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Start_Switch__SIO)
        Start_Switch_SIO_REG = Start_Switch_backup.sioState;
    #endif
}


/* [] END OF FILE */
