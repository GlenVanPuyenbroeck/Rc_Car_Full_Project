/*******************************************************************************
* File Name: Echo_M.c  
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
#include "Echo_M.h"

static Echo_M_BACKUP_STRUCT  Echo_M_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Echo_M_Sleep
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
*  \snippet Echo_M_SUT.c usage_Echo_M_Sleep_Wakeup
*******************************************************************************/
void Echo_M_Sleep(void)
{
    #if defined(Echo_M__PC)
        Echo_M_backup.pcState = Echo_M_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Echo_M_backup.usbState = Echo_M_CR1_REG;
            Echo_M_USB_POWER_REG |= Echo_M_USBIO_ENTER_SLEEP;
            Echo_M_CR1_REG &= Echo_M_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Echo_M__SIO)
        Echo_M_backup.sioState = Echo_M_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Echo_M_SIO_REG &= (uint32)(~Echo_M_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Echo_M_Wakeup
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
*  Refer to Echo_M_Sleep() for an example usage.
*******************************************************************************/
void Echo_M_Wakeup(void)
{
    #if defined(Echo_M__PC)
        Echo_M_PC = Echo_M_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Echo_M_USB_POWER_REG &= Echo_M_USBIO_EXIT_SLEEP_PH1;
            Echo_M_CR1_REG = Echo_M_backup.usbState;
            Echo_M_USB_POWER_REG &= Echo_M_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Echo_M__SIO)
        Echo_M_SIO_REG = Echo_M_backup.sioState;
    #endif
}


/* [] END OF FILE */
