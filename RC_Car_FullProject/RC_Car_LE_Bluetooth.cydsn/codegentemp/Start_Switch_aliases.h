/*******************************************************************************
* File Name: Start_Switch.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Start_Switch_ALIASES_H) /* Pins Start_Switch_ALIASES_H */
#define CY_PINS_Start_Switch_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Start_Switch_0			(Start_Switch__0__PC)
#define Start_Switch_0_PS		(Start_Switch__0__PS)
#define Start_Switch_0_PC		(Start_Switch__0__PC)
#define Start_Switch_0_DR		(Start_Switch__0__DR)
#define Start_Switch_0_SHIFT	(Start_Switch__0__SHIFT)
#define Start_Switch_0_INTR	((uint16)((uint16)0x0003u << (Start_Switch__0__SHIFT*2u)))

#define Start_Switch_INTR_ALL	 ((uint16)(Start_Switch_0_INTR))


#endif /* End Pins Start_Switch_ALIASES_H */


/* [] END OF FILE */
