/*******************************************************************************
* File Name: M_Rechts.h
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

#if !defined(CY_CLOCK_M_Rechts_H)
#define CY_CLOCK_M_Rechts_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void M_Rechts_StartEx(uint32 alignClkDiv);
#define M_Rechts_Start() \
    M_Rechts_StartEx(M_Rechts__PA_DIV_ID)

#else

void M_Rechts_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void M_Rechts_Stop(void);

void M_Rechts_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 M_Rechts_GetDividerRegister(void);
uint8  M_Rechts_GetFractionalDividerRegister(void);

#define M_Rechts_Enable()                         M_Rechts_Start()
#define M_Rechts_Disable()                        M_Rechts_Stop()
#define M_Rechts_SetDividerRegister(clkDivider, reset)  \
    M_Rechts_SetFractionalDividerRegister((clkDivider), 0u)
#define M_Rechts_SetDivider(clkDivider)           M_Rechts_SetDividerRegister((clkDivider), 1u)
#define M_Rechts_SetDividerValue(clkDivider)      M_Rechts_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define M_Rechts_DIV_ID     M_Rechts__DIV_ID

#define M_Rechts_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define M_Rechts_CTRL_REG   (*(reg32 *)M_Rechts__CTRL_REGISTER)
#define M_Rechts_DIV_REG    (*(reg32 *)M_Rechts__DIV_REGISTER)

#define M_Rechts_CMD_DIV_SHIFT          (0u)
#define M_Rechts_CMD_PA_DIV_SHIFT       (8u)
#define M_Rechts_CMD_DISABLE_SHIFT      (30u)
#define M_Rechts_CMD_ENABLE_SHIFT       (31u)

#define M_Rechts_CMD_DISABLE_MASK       ((uint32)((uint32)1u << M_Rechts_CMD_DISABLE_SHIFT))
#define M_Rechts_CMD_ENABLE_MASK        ((uint32)((uint32)1u << M_Rechts_CMD_ENABLE_SHIFT))

#define M_Rechts_DIV_FRAC_MASK  (0x000000F8u)
#define M_Rechts_DIV_FRAC_SHIFT (3u)
#define M_Rechts_DIV_INT_MASK   (0xFFFFFF00u)
#define M_Rechts_DIV_INT_SHIFT  (8u)

#else 

#define M_Rechts_DIV_REG        (*(reg32 *)M_Rechts__REGISTER)
#define M_Rechts_ENABLE_REG     M_Rechts_DIV_REG
#define M_Rechts_DIV_FRAC_MASK  M_Rechts__FRAC_MASK
#define M_Rechts_DIV_FRAC_SHIFT (16u)
#define M_Rechts_DIV_INT_MASK   M_Rechts__DIVIDER_MASK
#define M_Rechts_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_M_Rechts_H) */

/* [] END OF FILE */
