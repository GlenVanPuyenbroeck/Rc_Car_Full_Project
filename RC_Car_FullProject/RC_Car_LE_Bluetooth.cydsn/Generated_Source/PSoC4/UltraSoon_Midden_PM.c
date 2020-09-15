/*******************************************************************************
* File Name: UltraSoon_Midden_PM.c
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

#include "UltraSoon_Midden.h"

static UltraSoon_Midden_BACKUP_STRUCT UltraSoon_Midden_backup;


/*******************************************************************************
* Function Name: UltraSoon_Midden_SaveConfig
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
void UltraSoon_Midden_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: UltraSoon_Midden_Sleep
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
void UltraSoon_Midden_Sleep(void)
{
    if(0u != (UltraSoon_Midden_BLOCK_CONTROL_REG & UltraSoon_Midden_MASK))
    {
        UltraSoon_Midden_backup.enableState = 1u;
    }
    else
    {
        UltraSoon_Midden_backup.enableState = 0u;
    }

    UltraSoon_Midden_Stop();
    UltraSoon_Midden_SaveConfig();
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_RestoreConfig
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
void UltraSoon_Midden_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: UltraSoon_Midden_Wakeup
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
void UltraSoon_Midden_Wakeup(void)
{
    UltraSoon_Midden_RestoreConfig();

    if(0u != UltraSoon_Midden_backup.enableState)
    {
        UltraSoon_Midden_Enable();
    }
}


/* [] END OF FILE */
