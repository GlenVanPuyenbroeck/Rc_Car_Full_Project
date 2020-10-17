/*******************************************************************************
* File Name: Motor_Rechts_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Motor_Rechts.h"

static Motor_Rechts_backupStruct Motor_Rechts_backup;


/*******************************************************************************
* Function Name: Motor_Rechts_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Motor_Rechts_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Motor_Rechts_SaveConfig(void) 
{

    #if(!Motor_Rechts_UsingFixedFunction)
        #if(!Motor_Rechts_PWMModeIsCenterAligned)
            Motor_Rechts_backup.PWMPeriod = Motor_Rechts_ReadPeriod();
        #endif /* (!Motor_Rechts_PWMModeIsCenterAligned) */
        Motor_Rechts_backup.PWMUdb = Motor_Rechts_ReadCounter();
        #if (Motor_Rechts_UseStatus)
            Motor_Rechts_backup.InterruptMaskValue = Motor_Rechts_STATUS_MASK;
        #endif /* (Motor_Rechts_UseStatus) */

        #if(Motor_Rechts_DeadBandMode == Motor_Rechts__B_PWM__DBM_256_CLOCKS || \
            Motor_Rechts_DeadBandMode == Motor_Rechts__B_PWM__DBM_2_4_CLOCKS)
            Motor_Rechts_backup.PWMdeadBandValue = Motor_Rechts_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Motor_Rechts_KillModeMinTime)
             Motor_Rechts_backup.PWMKillCounterPeriod = Motor_Rechts_ReadKillTime();
        #endif /* (Motor_Rechts_KillModeMinTime) */

        #if(Motor_Rechts_UseControl)
            Motor_Rechts_backup.PWMControlRegister = Motor_Rechts_ReadControlRegister();
        #endif /* (Motor_Rechts_UseControl) */
    #endif  /* (!Motor_Rechts_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Motor_Rechts_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Motor_Rechts_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_Rechts_RestoreConfig(void) 
{
        #if(!Motor_Rechts_UsingFixedFunction)
            #if(!Motor_Rechts_PWMModeIsCenterAligned)
                Motor_Rechts_WritePeriod(Motor_Rechts_backup.PWMPeriod);
            #endif /* (!Motor_Rechts_PWMModeIsCenterAligned) */

            Motor_Rechts_WriteCounter(Motor_Rechts_backup.PWMUdb);

            #if (Motor_Rechts_UseStatus)
                Motor_Rechts_STATUS_MASK = Motor_Rechts_backup.InterruptMaskValue;
            #endif /* (Motor_Rechts_UseStatus) */

            #if(Motor_Rechts_DeadBandMode == Motor_Rechts__B_PWM__DBM_256_CLOCKS || \
                Motor_Rechts_DeadBandMode == Motor_Rechts__B_PWM__DBM_2_4_CLOCKS)
                Motor_Rechts_WriteDeadTime(Motor_Rechts_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Motor_Rechts_KillModeMinTime)
                Motor_Rechts_WriteKillTime(Motor_Rechts_backup.PWMKillCounterPeriod);
            #endif /* (Motor_Rechts_KillModeMinTime) */

            #if(Motor_Rechts_UseControl)
                Motor_Rechts_WriteControlRegister(Motor_Rechts_backup.PWMControlRegister);
            #endif /* (Motor_Rechts_UseControl) */
        #endif  /* (!Motor_Rechts_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Motor_Rechts_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Motor_Rechts_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Motor_Rechts_Sleep(void) 
{
    #if(Motor_Rechts_UseControl)
        if(Motor_Rechts_CTRL_ENABLE == (Motor_Rechts_CONTROL & Motor_Rechts_CTRL_ENABLE))
        {
            /*Component is enabled */
            Motor_Rechts_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Motor_Rechts_backup.PWMEnableState = 0u;
        }
    #endif /* (Motor_Rechts_UseControl) */

    /* Stop component */
    Motor_Rechts_Stop();

    /* Save registers configuration */
    Motor_Rechts_SaveConfig();
}


/*******************************************************************************
* Function Name: Motor_Rechts_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Motor_Rechts_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_Rechts_Wakeup(void) 
{
     /* Restore registers values */
    Motor_Rechts_RestoreConfig();

    if(Motor_Rechts_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Motor_Rechts_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
