/*******************************************************************************
* File Name: UltraSoon_Rechts_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UltraSoon_Rechts.h"

static UltraSoon_Rechts_BACKUP_STRUCT UltraSoon_Rechts_backup;


/*******************************************************************************
* Function Name: UltraSoon_Rechts_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Rechts_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: UltraSoon_Rechts_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Rechts_Sleep(void)
{
    if(0u != (UltraSoon_Rechts_BLOCK_CONTROL_REG & UltraSoon_Rechts_MASK))
    {
        UltraSoon_Rechts_backup.enableState = 1u;
    }
    else
    {
        UltraSoon_Rechts_backup.enableState = 0u;
    }

    UltraSoon_Rechts_Stop();
    UltraSoon_Rechts_SaveConfig();
}


/*******************************************************************************
* Function Name: UltraSoon_Rechts_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Rechts_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: UltraSoon_Rechts_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Rechts_Wakeup(void)
{
    UltraSoon_Rechts_RestoreConfig();

    if(0u != UltraSoon_Rechts_backup.enableState)
    {
        UltraSoon_Rechts_Enable();
    }
}


/* [] END OF FILE */
