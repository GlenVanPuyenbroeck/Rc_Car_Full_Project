/*******************************************************************************
* File Name: T_Motor_L_Geel.c  
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
#include "T_Motor_L_Geel.h"

static T_Motor_L_Geel_BACKUP_STRUCT  T_Motor_L_Geel_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: T_Motor_L_Geel_Sleep
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
*  \snippet T_Motor_L_Geel_SUT.c usage_T_Motor_L_Geel_Sleep_Wakeup
*******************************************************************************/
void T_Motor_L_Geel_Sleep(void)
{
    #if defined(T_Motor_L_Geel__PC)
        T_Motor_L_Geel_backup.pcState = T_Motor_L_Geel_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            T_Motor_L_Geel_backup.usbState = T_Motor_L_Geel_CR1_REG;
            T_Motor_L_Geel_USB_POWER_REG |= T_Motor_L_Geel_USBIO_ENTER_SLEEP;
            T_Motor_L_Geel_CR1_REG &= T_Motor_L_Geel_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(T_Motor_L_Geel__SIO)
        T_Motor_L_Geel_backup.sioState = T_Motor_L_Geel_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        T_Motor_L_Geel_SIO_REG &= (uint32)(~T_Motor_L_Geel_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: T_Motor_L_Geel_Wakeup
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
*  Refer to T_Motor_L_Geel_Sleep() for an example usage.
*******************************************************************************/
void T_Motor_L_Geel_Wakeup(void)
{
    #if defined(T_Motor_L_Geel__PC)
        T_Motor_L_Geel_PC = T_Motor_L_Geel_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            T_Motor_L_Geel_USB_POWER_REG &= T_Motor_L_Geel_USBIO_EXIT_SLEEP_PH1;
            T_Motor_L_Geel_CR1_REG = T_Motor_L_Geel_backup.usbState;
            T_Motor_L_Geel_USB_POWER_REG &= T_Motor_L_Geel_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(T_Motor_L_Geel__SIO)
        T_Motor_L_Geel_SIO_REG = T_Motor_L_Geel_backup.sioState;
    #endif
}


/* [] END OF FILE */
