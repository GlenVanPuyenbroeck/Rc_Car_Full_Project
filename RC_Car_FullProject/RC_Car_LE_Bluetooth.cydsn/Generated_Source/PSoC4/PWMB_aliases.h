/*******************************************************************************
* File Name: PWMB.h  
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

#if !defined(CY_PINS_PWMB_ALIASES_H) /* Pins PWMB_ALIASES_H */
#define CY_PINS_PWMB_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PWMB_0			(PWMB__0__PC)
#define PWMB_0_PS		(PWMB__0__PS)
#define PWMB_0_PC		(PWMB__0__PC)
#define PWMB_0_DR		(PWMB__0__DR)
#define PWMB_0_SHIFT	(PWMB__0__SHIFT)
#define PWMB_0_INTR	((uint16)((uint16)0x0003u << (PWMB__0__SHIFT*2u)))

#define PWMB_INTR_ALL	 ((uint16)(PWMB_0_INTR))


#endif /* End Pins PWMB_ALIASES_H */


/* [] END OF FILE */
