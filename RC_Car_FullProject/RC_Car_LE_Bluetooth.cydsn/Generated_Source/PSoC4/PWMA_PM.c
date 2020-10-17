/*******************************************************************************
* File Name: PWMA.c  
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
#include "PWMA.h"

static PWMA_BACKUP_STRUCT  PWMA_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: PWMA_Sleep
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
*  \snippet PWMA_SUT.c usage_PWMA_Sleep_Wakeup
*******************************************************************************/
void PWMA_Sleep(void)
{
    #if defined(PWMA__PC)
        PWMA_backup.pcState = PWMA_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            PWMA_backup.usbState = PWMA_CR1_REG;
            PWMA_USB_POWER_REG |= PWMA_USBIO_ENTER_SLEEP;
            PWMA_CR1_REG &= PWMA_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PWMA__SIO)
        PWMA_backup.sioState = PWMA_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        PWMA_SIO_REG &= (uint32)(~PWMA_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: PWMA_Wakeup
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
*  Refer to PWMA_Sleep() for an example usage.
*******************************************************************************/
void PWMA_Wakeup(void)
{
    #if defined(PWMA__PC)
        PWMA_PC = PWMA_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            PWMA_USB_POWER_REG &= PWMA_USBIO_EXIT_SLEEP_PH1;
            PWMA_CR1_REG = PWMA_backup.usbState;
            PWMA_USB_POWER_REG &= PWMA_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PWMA__SIO)
        PWMA_SIO_REG = PWMA_backup.sioState;
    #endif
}


/* [] END OF FILE */
