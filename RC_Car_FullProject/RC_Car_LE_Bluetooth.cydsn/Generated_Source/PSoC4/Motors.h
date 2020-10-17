/*******************************************************************************
* File Name: Motors.h
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

#if !defined(CY_CLOCK_Motors_H)
#define CY_CLOCK_Motors_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Motors_StartEx(uint32 alignClkDiv);
#define Motors_Start() \
    Motors_StartEx(Motors__PA_DIV_ID)

#else

void Motors_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Motors_Stop(void);

void Motors_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Motors_GetDividerRegister(void);
uint8  Motors_GetFractionalDividerRegister(void);

#define Motors_Enable()                         Motors_Start()
#define Motors_Disable()                        Motors_Stop()
#define Motors_SetDividerRegister(clkDivider, reset)  \
    Motors_SetFractionalDividerRegister((clkDivider), 0u)
#define Motors_SetDivider(clkDivider)           Motors_SetDividerRegister((clkDivider), 1u)
#define Motors_SetDividerValue(clkDivider)      Motors_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Motors_DIV_ID     Motors__DIV_ID

#define Motors_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Motors_CTRL_REG   (*(reg32 *)Motors__CTRL_REGISTER)
#define Motors_DIV_REG    (*(reg32 *)Motors__DIV_REGISTER)

#define Motors_CMD_DIV_SHIFT          (0u)
#define Motors_CMD_PA_DIV_SHIFT       (8u)
#define Motors_CMD_DISABLE_SHIFT      (30u)
#define Motors_CMD_ENABLE_SHIFT       (31u)

#define Motors_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Motors_CMD_DISABLE_SHIFT))
#define Motors_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Motors_CMD_ENABLE_SHIFT))

#define Motors_DIV_FRAC_MASK  (0x000000F8u)
#define Motors_DIV_FRAC_SHIFT (3u)
#define Motors_DIV_INT_MASK   (0xFFFFFF00u)
#define Motors_DIV_INT_SHIFT  (8u)

#else 

#define Motors_DIV_REG        (*(reg32 *)Motors__REGISTER)
#define Motors_ENABLE_REG     Motors_DIV_REG
#define Motors_DIV_FRAC_MASK  Motors__FRAC_MASK
#define Motors_DIV_FRAC_SHIFT (16u)
#define Motors_DIV_INT_MASK   Motors__DIVIDER_MASK
#define Motors_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Motors_H) */

/* [] END OF FILE */
