/*******************************************************************************
* File Name: Trigger_Links.c  
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
#include "Trigger_Links.h"

static Trigger_Links_BACKUP_STRUCT  Trigger_Links_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Trigger_Links_Sleep
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
*  \snippet Trigger_Links_SUT.c usage_Trigger_Links_Sleep_Wakeup
*******************************************************************************/
void Trigger_Links_Sleep(void)
{
    #if defined(Trigger_Links__PC)
        Trigger_Links_backup.pcState = Trigger_Links_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Trigger_Links_backup.usbState = Trigger_Links_CR1_REG;
            Trigger_Links_USB_POWER_REG |= Trigger_Links_USBIO_ENTER_SLEEP;
            Trigger_Links_CR1_REG &= Trigger_Links_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Trigger_Links__SIO)
        Trigger_Links_backup.sioState = Trigger_Links_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Trigger_Links_SIO_REG &= (uint32)(~Trigger_Links_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Trigger_Links_Wakeup
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
*  Refer to Trigger_Links_Sleep() for an example usage.
*******************************************************************************/
void Trigger_Links_Wakeup(void)
{
    #if defined(Trigger_Links__PC)
        Trigger_Links_PC = Trigger_Links_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Trigger_Links_USB_POWER_REG &= Trigger_Links_USBIO_EXIT_SLEEP_PH1;
            Trigger_Links_CR1_REG = Trigger_Links_backup.usbState;
            Trigger_Links_USB_POWER_REG &= Trigger_Links_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Trigger_Links__SIO)
        Trigger_Links_SIO_REG = Trigger_Links_backup.sioState;
    #endif
}


/* [] END OF FILE */
