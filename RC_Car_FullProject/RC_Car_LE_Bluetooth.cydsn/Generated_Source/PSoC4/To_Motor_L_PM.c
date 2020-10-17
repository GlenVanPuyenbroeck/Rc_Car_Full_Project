/*******************************************************************************
* File Name: To_Motor_L.c  
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
#include "To_Motor_L.h"

static To_Motor_L_BACKUP_STRUCT  To_Motor_L_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: To_Motor_L_Sleep
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
*  \snippet To_Motor_L_SUT.c usage_To_Motor_L_Sleep_Wakeup
*******************************************************************************/
void To_Motor_L_Sleep(void)
{
    #if defined(To_Motor_L__PC)
        To_Motor_L_backup.pcState = To_Motor_L_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            To_Motor_L_backup.usbState = To_Motor_L_CR1_REG;
            To_Motor_L_USB_POWER_REG |= To_Motor_L_USBIO_ENTER_SLEEP;
            To_Motor_L_CR1_REG &= To_Motor_L_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(To_Motor_L__SIO)
        To_Motor_L_backup.sioState = To_Motor_L_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        To_Motor_L_SIO_REG &= (uint32)(~To_Motor_L_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: To_Motor_L_Wakeup
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
*  Refer to To_Motor_L_Sleep() for an example usage.
*******************************************************************************/
void To_Motor_L_Wakeup(void)
{
    #if defined(To_Motor_L__PC)
        To_Motor_L_PC = To_Motor_L_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            To_Motor_L_USB_POWER_REG &= To_Motor_L_USBIO_EXIT_SLEEP_PH1;
            To_Motor_L_CR1_REG = To_Motor_L_backup.usbState;
            To_Motor_L_USB_POWER_REG &= To_Motor_L_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(To_Motor_L__SIO)
        To_Motor_L_SIO_REG = To_Motor_L_backup.sioState;
    #endif
}


/* [] END OF FILE */
