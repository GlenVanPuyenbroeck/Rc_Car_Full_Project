/*******************************************************************************
* File Name: Echo_Links.h  
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

#if !defined(CY_PINS_Echo_Links_ALIASES_H) /* Pins Echo_Links_ALIASES_H */
#define CY_PINS_Echo_Links_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Echo_Links_0			(Echo_Links__0__PC)
#define Echo_Links_0_PS		(Echo_Links__0__PS)
#define Echo_Links_0_PC		(Echo_Links__0__PC)
#define Echo_Links_0_DR		(Echo_Links__0__DR)
#define Echo_Links_0_SHIFT	(Echo_Links__0__SHIFT)
#define Echo_Links_0_INTR	((uint16)((uint16)0x0003u << (Echo_Links__0__SHIFT*2u)))

#define Echo_Links_INTR_ALL	 ((uint16)(Echo_Links_0_INTR))


#endif /* End Pins Echo_Links_ALIASES_H */


/* [] END OF FILE */
