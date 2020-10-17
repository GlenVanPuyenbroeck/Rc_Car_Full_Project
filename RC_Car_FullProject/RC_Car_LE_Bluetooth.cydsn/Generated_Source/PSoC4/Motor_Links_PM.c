/*******************************************************************************
* File Name: Motor_Links_PM.c
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

#include "Motor_Links.h"

static Motor_Links_backupStruct Motor_Links_backup;


/*******************************************************************************
* Function Name: Motor_Links_SaveConfig
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
*  Motor_Links_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Motor_Links_SaveConfig(void) 
{

    #if(!Motor_Links_UsingFixedFunction)
        #if(!Motor_Links_PWMModeIsCenterAligned)
            Motor_Links_backup.PWMPeriod = Motor_Links_ReadPeriod();
        #endif /* (!Motor_Links_PWMModeIsCenterAligned) */
        Motor_Links_backup.PWMUdb = Motor_Links_ReadCounter();
        #if (Motor_Links_UseStatus)
            Motor_Links_backup.InterruptMaskValue = Motor_Links_STATUS_MASK;
        #endif /* (Motor_Links_UseStatus) */

        #if(Motor_Links_DeadBandMode == Motor_Links__B_PWM__DBM_256_CLOCKS || \
            Motor_Links_DeadBandMode == Motor_Links__B_PWM__DBM_2_4_CLOCKS)
            Motor_Links_backup.PWMdeadBandValue = Motor_Links_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Motor_Links_KillModeMinTime)
             Motor_Links_backup.PWMKillCounterPeriod = Motor_Links_ReadKillTime();
        #endif /* (Motor_Links_KillModeMinTime) */

        #if(Motor_Links_UseControl)
            Motor_Links_backup.PWMControlRegister = Motor_Links_ReadControlRegister();
        #endif /* (Motor_Links_UseControl) */
    #endif  /* (!Motor_Links_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Motor_Links_RestoreConfig
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
*  Motor_Links_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_Links_RestoreConfig(void) 
{
        #if(!Motor_Links_UsingFixedFunction)
            #if(!Motor_Links_PWMModeIsCenterAligned)
                Motor_Links_WritePeriod(Motor_Links_backup.PWMPeriod);
            #endif /* (!Motor_Links_PWMModeIsCenterAligned) */

            Motor_Links_WriteCounter(Motor_Links_backup.PWMUdb);

            #if (Motor_Links_UseStatus)
                Motor_Links_STATUS_MASK = Motor_Links_backup.InterruptMaskValue;
            #endif /* (Motor_Links_UseStatus) */

            #if(Motor_Links_DeadBandMode == Motor_Links__B_PWM__DBM_256_CLOCKS || \
                Motor_Links_DeadBandMode == Motor_Links__B_PWM__DBM_2_4_CLOCKS)
                Motor_Links_WriteDeadTime(Motor_Links_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Motor_Links_KillModeMinTime)
                Motor_Links_WriteKillTime(Motor_Links_backup.PWMKillCounterPeriod);
            #endif /* (Motor_Links_KillModeMinTime) */

            #if(Motor_Links_UseControl)
                Motor_Links_WriteControlRegister(Motor_Links_backup.PWMControlRegister);
            #endif /* (Motor_Links_UseControl) */
        #endif  /* (!Motor_Links_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Motor_Links_Sleep
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
*  Motor_Links_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Motor_Links_Sleep(void) 
{
    #if(Motor_Links_UseControl)
        if(Motor_Links_CTRL_ENABLE == (Motor_Links_CONTROL & Motor_Links_CTRL_ENABLE))
        {
            /*Component is enabled */
            Motor_Links_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Motor_Links_backup.PWMEnableState = 0u;
        }
    #endif /* (Motor_Links_UseControl) */

    /* Stop component */
    Motor_Links_Stop();

    /* Save registers configuration */
    Motor_Links_SaveConfig();
}


/*******************************************************************************
* Function Name: Motor_Links_Wakeup
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
*  Motor_Links_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Motor_Links_Wakeup(void) 
{
     /* Restore registers values */
    Motor_Links_RestoreConfig();

    if(Motor_Links_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Motor_Links_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
