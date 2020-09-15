/*******************************************************************************
* File Name: UltraSoon_Links_PM.c
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

#include "UltraSoon_Links.h"

static UltraSoon_Links_BACKUP_STRUCT UltraSoon_Links_backup;


/*******************************************************************************
* Function Name: UltraSoon_Links_SaveConfig
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
void UltraSoon_Links_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: UltraSoon_Links_Sleep
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
void UltraSoon_Links_Sleep(void)
{
    if(0u != (UltraSoon_Links_BLOCK_CONTROL_REG & UltraSoon_Links_MASK))
    {
        UltraSoon_Links_backup.enableState = 1u;
    }
    else
    {
        UltraSoon_Links_backup.enableState = 0u;
    }

    UltraSoon_Links_Stop();
    UltraSoon_Links_SaveConfig();
}


/*******************************************************************************
* Function Name: UltraSoon_Links_RestoreConfig
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
void UltraSoon_Links_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: UltraSoon_Links_Wakeup
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
void UltraSoon_Links_Wakeup(void)
{
    UltraSoon_Links_RestoreConfig();

    if(0u != UltraSoon_Links_backup.enableState)
    {
        UltraSoon_Links_Enable();
    }
}


/* [] END OF FILE */
