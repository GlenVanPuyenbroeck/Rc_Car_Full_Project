/*******************************************************************************
* File Name: M_Links.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_M_Links_H)
#define CY_CLOCK_M_Links_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void M_Links_StartEx(uint32 alignClkDiv);
#define M_Links_Start() \
    M_Links_StartEx(M_Links__PA_DIV_ID)

#else

void M_Links_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void M_Links_Stop(void);

void M_Links_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 M_Links_GetDividerRegister(void);
uint8  M_Links_GetFractionalDividerRegister(void);

#define M_Links_Enable()                         M_Links_Start()
#define M_Links_Disable()                        M_Links_Stop()
#define M_Links_SetDividerRegister(clkDivider, reset)  \
    M_Links_SetFractionalDividerRegister((clkDivider), 0u)
#define M_Links_SetDivider(clkDivider)           M_Links_SetDividerRegister((clkDivider), 1u)
#define M_Links_SetDividerValue(clkDivider)      M_Links_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define M_Links_DIV_ID     M_Links__DIV_ID

#define M_Links_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define M_Links_CTRL_REG   (*(reg32 *)M_Links__CTRL_REGISTER)
#define M_Links_DIV_REG    (*(reg32 *)M_Links__DIV_REGISTER)

#define M_Links_CMD_DIV_SHIFT          (0u)
#define M_Links_CMD_PA_DIV_SHIFT       (8u)
#define M_Links_CMD_DISABLE_SHIFT      (30u)
#define M_Links_CMD_ENABLE_SHIFT       (31u)

#define M_Links_CMD_DISABLE_MASK       ((uint32)((uint32)1u << M_Links_CMD_DISABLE_SHIFT))
#define M_Links_CMD_ENABLE_MASK        ((uint32)((uint32)1u << M_Links_CMD_ENABLE_SHIFT))

#define M_Links_DIV_FRAC_MASK  (0x000000F8u)
#define M_Links_DIV_FRAC_SHIFT (3u)
#define M_Links_DIV_INT_MASK   (0xFFFFFF00u)
#define M_Links_DIV_INT_SHIFT  (8u)

#else 

#define M_Links_DIV_REG        (*(reg32 *)M_Links__REGISTER)
#define M_Links_ENABLE_REG     M_Links_DIV_REG
#define M_Links_DIV_FRAC_MASK  M_Links__FRAC_MASK
#define M_Links_DIV_FRAC_SHIFT (16u)
#define M_Links_DIV_INT_MASK   M_Links__DIVIDER_MASK
#define M_Links_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_M_Links_H) */

/* [] END OF FILE */
