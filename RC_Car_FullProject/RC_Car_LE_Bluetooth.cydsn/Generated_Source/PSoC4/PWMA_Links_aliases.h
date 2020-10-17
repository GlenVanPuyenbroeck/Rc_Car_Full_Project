/*******************************************************************************
* File Name: PWMA_Links.h  
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

#if !defined(CY_PINS_PWMA_Links_ALIASES_H) /* Pins PWMA_Links_ALIASES_H */
#define CY_PINS_PWMA_Links_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PWMA_Links_0			(PWMA_Links__0__PC)
#define PWMA_Links_0_PS		(PWMA_Links__0__PS)
#define PWMA_Links_0_PC		(PWMA_Links__0__PC)
#define PWMA_Links_0_DR		(PWMA_Links__0__DR)
#define PWMA_Links_0_SHIFT	(PWMA_Links__0__SHIFT)
#define PWMA_Links_0_INTR	((uint16)((uint16)0x0003u << (PWMA_Links__0__SHIFT*2u)))

#define PWMA_Links_INTR_ALL	 ((uint16)(PWMA_Links_0_INTR))


#endif /* End Pins PWMA_Links_ALIASES_H */


/* [] END OF FILE */
