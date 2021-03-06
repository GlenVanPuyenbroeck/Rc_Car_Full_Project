/*******************************************************************************
* File Name: PWMA_Rechts.h  
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

#if !defined(CY_PINS_PWMA_Rechts_ALIASES_H) /* Pins PWMA_Rechts_ALIASES_H */
#define CY_PINS_PWMA_Rechts_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PWMA_Rechts_0			(PWMA_Rechts__0__PC)
#define PWMA_Rechts_0_PS		(PWMA_Rechts__0__PS)
#define PWMA_Rechts_0_PC		(PWMA_Rechts__0__PC)
#define PWMA_Rechts_0_DR		(PWMA_Rechts__0__DR)
#define PWMA_Rechts_0_SHIFT	(PWMA_Rechts__0__SHIFT)
#define PWMA_Rechts_0_INTR	((uint16)((uint16)0x0003u << (PWMA_Rechts__0__SHIFT*2u)))

#define PWMA_Rechts_INTR_ALL	 ((uint16)(PWMA_Rechts_0_INTR))


#endif /* End Pins PWMA_Rechts_ALIASES_H */


/* [] END OF FILE */
