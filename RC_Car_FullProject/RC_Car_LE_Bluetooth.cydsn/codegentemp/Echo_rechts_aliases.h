/*******************************************************************************
* File Name: Echo_rechts.h  
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

#if !defined(CY_PINS_Echo_rechts_ALIASES_H) /* Pins Echo_rechts_ALIASES_H */
#define CY_PINS_Echo_rechts_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Echo_rechts_0			(Echo_rechts__0__PC)
#define Echo_rechts_0_PS		(Echo_rechts__0__PS)
#define Echo_rechts_0_PC		(Echo_rechts__0__PC)
#define Echo_rechts_0_DR		(Echo_rechts__0__DR)
#define Echo_rechts_0_SHIFT	(Echo_rechts__0__SHIFT)
#define Echo_rechts_0_INTR	((uint16)((uint16)0x0003u << (Echo_rechts__0__SHIFT*2u)))

#define Echo_rechts_INTR_ALL	 ((uint16)(Echo_rechts_0_INTR))


#endif /* End Pins Echo_rechts_ALIASES_H */


/* [] END OF FILE */
