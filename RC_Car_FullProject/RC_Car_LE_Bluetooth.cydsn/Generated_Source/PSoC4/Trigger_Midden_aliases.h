/*******************************************************************************
* File Name: Trigger_Midden.h  
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

#if !defined(CY_PINS_Trigger_Midden_ALIASES_H) /* Pins Trigger_Midden_ALIASES_H */
#define CY_PINS_Trigger_Midden_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Trigger_Midden_0			(Trigger_Midden__0__PC)
#define Trigger_Midden_0_PS		(Trigger_Midden__0__PS)
#define Trigger_Midden_0_PC		(Trigger_Midden__0__PC)
#define Trigger_Midden_0_DR		(Trigger_Midden__0__DR)
#define Trigger_Midden_0_SHIFT	(Trigger_Midden__0__SHIFT)
#define Trigger_Midden_0_INTR	((uint16)((uint16)0x0003u << (Trigger_Midden__0__SHIFT*2u)))

#define Trigger_Midden_INTR_ALL	 ((uint16)(Trigger_Midden_0_INTR))


#endif /* End Pins Trigger_Midden_ALIASES_H */


/* [] END OF FILE */
