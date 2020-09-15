/*******************************************************************************
* File Name: UltraSoon_Rechts.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the UltraSoon_Rechts
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_UltraSoon_Rechts_H)
#define CY_TCPWM_UltraSoon_Rechts_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} UltraSoon_Rechts_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  UltraSoon_Rechts_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define UltraSoon_Rechts_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define UltraSoon_Rechts_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define UltraSoon_Rechts_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define UltraSoon_Rechts_QUAD_ENCODING_MODES            (0lu)
#define UltraSoon_Rechts_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define UltraSoon_Rechts_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define UltraSoon_Rechts_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define UltraSoon_Rechts_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define UltraSoon_Rechts_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define UltraSoon_Rechts_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define UltraSoon_Rechts_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define UltraSoon_Rechts_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define UltraSoon_Rechts_TC_RUN_MODE                    (0lu)
#define UltraSoon_Rechts_TC_COUNTER_MODE                (0lu)
#define UltraSoon_Rechts_TC_COMP_CAP_MODE               (2lu)
#define UltraSoon_Rechts_TC_PRESCALER                   (0lu)

/* Signal modes */
#define UltraSoon_Rechts_TC_RELOAD_SIGNAL_MODE          (0lu)
#define UltraSoon_Rechts_TC_COUNT_SIGNAL_MODE           (3lu)
#define UltraSoon_Rechts_TC_START_SIGNAL_MODE           (0lu)
#define UltraSoon_Rechts_TC_STOP_SIGNAL_MODE            (1lu)
#define UltraSoon_Rechts_TC_CAPTURE_SIGNAL_MODE         (1lu)

/* Signal present */
#define UltraSoon_Rechts_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define UltraSoon_Rechts_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define UltraSoon_Rechts_TC_START_SIGNAL_PRESENT        (1lu)
#define UltraSoon_Rechts_TC_STOP_SIGNAL_PRESENT         (1lu)
#define UltraSoon_Rechts_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define UltraSoon_Rechts_TC_INTERRUPT_MASK              (2lu)

/* PWM Mode */
/* Parameters */
#define UltraSoon_Rechts_PWM_KILL_EVENT                 (0lu)
#define UltraSoon_Rechts_PWM_STOP_EVENT                 (0lu)
#define UltraSoon_Rechts_PWM_MODE                       (4lu)
#define UltraSoon_Rechts_PWM_OUT_N_INVERT               (0lu)
#define UltraSoon_Rechts_PWM_OUT_INVERT                 (0lu)
#define UltraSoon_Rechts_PWM_ALIGN                      (0lu)
#define UltraSoon_Rechts_PWM_RUN_MODE                   (0lu)
#define UltraSoon_Rechts_PWM_DEAD_TIME_CYCLE            (0lu)
#define UltraSoon_Rechts_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define UltraSoon_Rechts_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define UltraSoon_Rechts_PWM_COUNT_SIGNAL_MODE          (2lu)
#define UltraSoon_Rechts_PWM_START_SIGNAL_MODE          (0lu)
#define UltraSoon_Rechts_PWM_STOP_SIGNAL_MODE           (0lu)
#define UltraSoon_Rechts_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define UltraSoon_Rechts_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define UltraSoon_Rechts_PWM_COUNT_SIGNAL_PRESENT       (1lu)
#define UltraSoon_Rechts_PWM_START_SIGNAL_PRESENT       (0lu)
#define UltraSoon_Rechts_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define UltraSoon_Rechts_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define UltraSoon_Rechts_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define UltraSoon_Rechts_TC_PERIOD_VALUE                (65535lu)
#define UltraSoon_Rechts_TC_COMPARE_VALUE               (65535lu)
#define UltraSoon_Rechts_TC_COMPARE_BUF_VALUE           (65535lu)
#define UltraSoon_Rechts_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define UltraSoon_Rechts_PWM_PERIOD_VALUE               (65535lu)
#define UltraSoon_Rechts_PWM_PERIOD_BUF_VALUE           (65535lu)
#define UltraSoon_Rechts_PWM_PERIOD_SWAP                (0lu)
#define UltraSoon_Rechts_PWM_COMPARE_VALUE              (65535lu)
#define UltraSoon_Rechts_PWM_COMPARE_BUF_VALUE          (65535lu)
#define UltraSoon_Rechts_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define UltraSoon_Rechts__LEFT 0
#define UltraSoon_Rechts__RIGHT 1
#define UltraSoon_Rechts__CENTER 2
#define UltraSoon_Rechts__ASYMMETRIC 3

#define UltraSoon_Rechts__X1 0
#define UltraSoon_Rechts__X2 1
#define UltraSoon_Rechts__X4 2

#define UltraSoon_Rechts__PWM 4
#define UltraSoon_Rechts__PWM_DT 5
#define UltraSoon_Rechts__PWM_PR 6

#define UltraSoon_Rechts__INVERSE 1
#define UltraSoon_Rechts__DIRECT 0

#define UltraSoon_Rechts__CAPTURE 2
#define UltraSoon_Rechts__COMPARE 0

#define UltraSoon_Rechts__TRIG_LEVEL 3
#define UltraSoon_Rechts__TRIG_RISING 0
#define UltraSoon_Rechts__TRIG_FALLING 1
#define UltraSoon_Rechts__TRIG_BOTH 2

#define UltraSoon_Rechts__INTR_MASK_TC 1
#define UltraSoon_Rechts__INTR_MASK_CC_MATCH 2
#define UltraSoon_Rechts__INTR_MASK_NONE 0
#define UltraSoon_Rechts__INTR_MASK_TC_CC 3

#define UltraSoon_Rechts__UNCONFIG 8
#define UltraSoon_Rechts__TIMER 1
#define UltraSoon_Rechts__QUAD 3
#define UltraSoon_Rechts__PWM_SEL 7

#define UltraSoon_Rechts__COUNT_UP 0
#define UltraSoon_Rechts__COUNT_DOWN 1
#define UltraSoon_Rechts__COUNT_UPDOWN0 2
#define UltraSoon_Rechts__COUNT_UPDOWN1 3


/* Prescaler */
#define UltraSoon_Rechts_PRESCALE_DIVBY1                ((uint32)(0u << UltraSoon_Rechts_PRESCALER_SHIFT))
#define UltraSoon_Rechts_PRESCALE_DIVBY2                ((uint32)(1u << UltraSoon_Rechts_PRESCALER_SHIFT))
#define UltraSoon_Rechts_PRESCALE_DIVBY4                ((uint32)(2u << UltraSoon_Rechts_PRESCALER_SHIFT))
#define UltraSoon_Rechts_PRESCALE_DIVBY8                ((uint32)(3u << UltraSoon_Rechts_PRESCALER_SHIFT))
#define UltraSoon_Rechts_PRESCALE_DIVBY16               ((uint32)(4u << UltraSoon_Rechts_PRESCALER_SHIFT))
#define UltraSoon_Rechts_PRESCALE_DIVBY32               ((uint32)(5u << UltraSoon_Rechts_PRESCALER_SHIFT))
#define UltraSoon_Rechts_PRESCALE_DIVBY64               ((uint32)(6u << UltraSoon_Rechts_PRESCALER_SHIFT))
#define UltraSoon_Rechts_PRESCALE_DIVBY128              ((uint32)(7u << UltraSoon_Rechts_PRESCALER_SHIFT))

/* TCPWM set modes */
#define UltraSoon_Rechts_MODE_TIMER_COMPARE             ((uint32)(UltraSoon_Rechts__COMPARE         <<  \
                                                                  UltraSoon_Rechts_MODE_SHIFT))
#define UltraSoon_Rechts_MODE_TIMER_CAPTURE             ((uint32)(UltraSoon_Rechts__CAPTURE         <<  \
                                                                  UltraSoon_Rechts_MODE_SHIFT))
#define UltraSoon_Rechts_MODE_QUAD                      ((uint32)(UltraSoon_Rechts__QUAD            <<  \
                                                                  UltraSoon_Rechts_MODE_SHIFT))
#define UltraSoon_Rechts_MODE_PWM                       ((uint32)(UltraSoon_Rechts__PWM             <<  \
                                                                  UltraSoon_Rechts_MODE_SHIFT))
#define UltraSoon_Rechts_MODE_PWM_DT                    ((uint32)(UltraSoon_Rechts__PWM_DT          <<  \
                                                                  UltraSoon_Rechts_MODE_SHIFT))
#define UltraSoon_Rechts_MODE_PWM_PR                    ((uint32)(UltraSoon_Rechts__PWM_PR          <<  \
                                                                  UltraSoon_Rechts_MODE_SHIFT))

/* Quad Modes */
#define UltraSoon_Rechts_MODE_X1                        ((uint32)(UltraSoon_Rechts__X1              <<  \
                                                                  UltraSoon_Rechts_QUAD_MODE_SHIFT))
#define UltraSoon_Rechts_MODE_X2                        ((uint32)(UltraSoon_Rechts__X2              <<  \
                                                                  UltraSoon_Rechts_QUAD_MODE_SHIFT))
#define UltraSoon_Rechts_MODE_X4                        ((uint32)(UltraSoon_Rechts__X4              <<  \
                                                                  UltraSoon_Rechts_QUAD_MODE_SHIFT))

/* Counter modes */
#define UltraSoon_Rechts_COUNT_UP                       ((uint32)(UltraSoon_Rechts__COUNT_UP        <<  \
                                                                  UltraSoon_Rechts_UPDOWN_SHIFT))
#define UltraSoon_Rechts_COUNT_DOWN                     ((uint32)(UltraSoon_Rechts__COUNT_DOWN      <<  \
                                                                  UltraSoon_Rechts_UPDOWN_SHIFT))
#define UltraSoon_Rechts_COUNT_UPDOWN0                  ((uint32)(UltraSoon_Rechts__COUNT_UPDOWN0   <<  \
                                                                  UltraSoon_Rechts_UPDOWN_SHIFT))
#define UltraSoon_Rechts_COUNT_UPDOWN1                  ((uint32)(UltraSoon_Rechts__COUNT_UPDOWN1   <<  \
                                                                  UltraSoon_Rechts_UPDOWN_SHIFT))

/* PWM output invert */
#define UltraSoon_Rechts_INVERT_LINE                    ((uint32)(UltraSoon_Rechts__INVERSE         <<  \
                                                                  UltraSoon_Rechts_INV_OUT_SHIFT))
#define UltraSoon_Rechts_INVERT_LINE_N                  ((uint32)(UltraSoon_Rechts__INVERSE         <<  \
                                                                  UltraSoon_Rechts_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define UltraSoon_Rechts_TRIG_RISING                    ((uint32)UltraSoon_Rechts__TRIG_RISING)
#define UltraSoon_Rechts_TRIG_FALLING                   ((uint32)UltraSoon_Rechts__TRIG_FALLING)
#define UltraSoon_Rechts_TRIG_BOTH                      ((uint32)UltraSoon_Rechts__TRIG_BOTH)
#define UltraSoon_Rechts_TRIG_LEVEL                     ((uint32)UltraSoon_Rechts__TRIG_LEVEL)

/* Interrupt mask */
#define UltraSoon_Rechts_INTR_MASK_TC                   ((uint32)UltraSoon_Rechts__INTR_MASK_TC)
#define UltraSoon_Rechts_INTR_MASK_CC_MATCH             ((uint32)UltraSoon_Rechts__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define UltraSoon_Rechts_CC_MATCH_SET                   (0x00u)
#define UltraSoon_Rechts_CC_MATCH_CLEAR                 (0x01u)
#define UltraSoon_Rechts_CC_MATCH_INVERT                (0x02u)
#define UltraSoon_Rechts_CC_MATCH_NO_CHANGE             (0x03u)
#define UltraSoon_Rechts_OVERLOW_SET                    (0x00u)
#define UltraSoon_Rechts_OVERLOW_CLEAR                  (0x04u)
#define UltraSoon_Rechts_OVERLOW_INVERT                 (0x08u)
#define UltraSoon_Rechts_OVERLOW_NO_CHANGE              (0x0Cu)
#define UltraSoon_Rechts_UNDERFLOW_SET                  (0x00u)
#define UltraSoon_Rechts_UNDERFLOW_CLEAR                (0x10u)
#define UltraSoon_Rechts_UNDERFLOW_INVERT               (0x20u)
#define UltraSoon_Rechts_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define UltraSoon_Rechts_PWM_MODE_LEFT                  (UltraSoon_Rechts_CC_MATCH_CLEAR        |   \
                                                         UltraSoon_Rechts_OVERLOW_SET           |   \
                                                         UltraSoon_Rechts_UNDERFLOW_NO_CHANGE)
#define UltraSoon_Rechts_PWM_MODE_RIGHT                 (UltraSoon_Rechts_CC_MATCH_SET          |   \
                                                         UltraSoon_Rechts_OVERLOW_NO_CHANGE     |   \
                                                         UltraSoon_Rechts_UNDERFLOW_CLEAR)
#define UltraSoon_Rechts_PWM_MODE_ASYM                  (UltraSoon_Rechts_CC_MATCH_INVERT       |   \
                                                         UltraSoon_Rechts_OVERLOW_SET           |   \
                                                         UltraSoon_Rechts_UNDERFLOW_CLEAR)

#if (UltraSoon_Rechts_CY_TCPWM_V2)
    #if(UltraSoon_Rechts_CY_TCPWM_4000)
        #define UltraSoon_Rechts_PWM_MODE_CENTER                (UltraSoon_Rechts_CC_MATCH_INVERT       |   \
                                                                 UltraSoon_Rechts_OVERLOW_NO_CHANGE     |   \
                                                                 UltraSoon_Rechts_UNDERFLOW_CLEAR)
    #else
        #define UltraSoon_Rechts_PWM_MODE_CENTER                (UltraSoon_Rechts_CC_MATCH_INVERT       |   \
                                                                 UltraSoon_Rechts_OVERLOW_SET           |   \
                                                                 UltraSoon_Rechts_UNDERFLOW_CLEAR)
    #endif /* (UltraSoon_Rechts_CY_TCPWM_4000) */
#else
    #define UltraSoon_Rechts_PWM_MODE_CENTER                (UltraSoon_Rechts_CC_MATCH_INVERT       |   \
                                                             UltraSoon_Rechts_OVERLOW_NO_CHANGE     |   \
                                                             UltraSoon_Rechts_UNDERFLOW_CLEAR)
#endif /* (UltraSoon_Rechts_CY_TCPWM_NEW) */

/* Command operations without condition */
#define UltraSoon_Rechts_CMD_CAPTURE                    (0u)
#define UltraSoon_Rechts_CMD_RELOAD                     (8u)
#define UltraSoon_Rechts_CMD_STOP                       (16u)
#define UltraSoon_Rechts_CMD_START                      (24u)

/* Status */
#define UltraSoon_Rechts_STATUS_DOWN                    (1u)
#define UltraSoon_Rechts_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   UltraSoon_Rechts_Init(void);
void   UltraSoon_Rechts_Enable(void);
void   UltraSoon_Rechts_Start(void);
void   UltraSoon_Rechts_Stop(void);

void   UltraSoon_Rechts_SetMode(uint32 mode);
void   UltraSoon_Rechts_SetCounterMode(uint32 counterMode);
void   UltraSoon_Rechts_SetPWMMode(uint32 modeMask);
void   UltraSoon_Rechts_SetQDMode(uint32 qdMode);

void   UltraSoon_Rechts_SetPrescaler(uint32 prescaler);
void   UltraSoon_Rechts_TriggerCommand(uint32 mask, uint32 command);
void   UltraSoon_Rechts_SetOneShot(uint32 oneShotEnable);
uint32 UltraSoon_Rechts_ReadStatus(void);

void   UltraSoon_Rechts_SetPWMSyncKill(uint32 syncKillEnable);
void   UltraSoon_Rechts_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   UltraSoon_Rechts_SetPWMDeadTime(uint32 deadTime);
void   UltraSoon_Rechts_SetPWMInvert(uint32 mask);

void   UltraSoon_Rechts_SetInterruptMode(uint32 interruptMask);
uint32 UltraSoon_Rechts_GetInterruptSourceMasked(void);
uint32 UltraSoon_Rechts_GetInterruptSource(void);
void   UltraSoon_Rechts_ClearInterrupt(uint32 interruptMask);
void   UltraSoon_Rechts_SetInterrupt(uint32 interruptMask);

void   UltraSoon_Rechts_WriteCounter(uint32 count);
uint32 UltraSoon_Rechts_ReadCounter(void);

uint32 UltraSoon_Rechts_ReadCapture(void);
uint32 UltraSoon_Rechts_ReadCaptureBuf(void);

void   UltraSoon_Rechts_WritePeriod(uint32 period);
uint32 UltraSoon_Rechts_ReadPeriod(void);
void   UltraSoon_Rechts_WritePeriodBuf(uint32 periodBuf);
uint32 UltraSoon_Rechts_ReadPeriodBuf(void);

void   UltraSoon_Rechts_WriteCompare(uint32 compare);
uint32 UltraSoon_Rechts_ReadCompare(void);
void   UltraSoon_Rechts_WriteCompareBuf(uint32 compareBuf);
uint32 UltraSoon_Rechts_ReadCompareBuf(void);

void   UltraSoon_Rechts_SetPeriodSwap(uint32 swapEnable);
void   UltraSoon_Rechts_SetCompareSwap(uint32 swapEnable);

void   UltraSoon_Rechts_SetCaptureMode(uint32 triggerMode);
void   UltraSoon_Rechts_SetReloadMode(uint32 triggerMode);
void   UltraSoon_Rechts_SetStartMode(uint32 triggerMode);
void   UltraSoon_Rechts_SetStopMode(uint32 triggerMode);
void   UltraSoon_Rechts_SetCountMode(uint32 triggerMode);

void   UltraSoon_Rechts_SaveConfig(void);
void   UltraSoon_Rechts_RestoreConfig(void);
void   UltraSoon_Rechts_Sleep(void);
void   UltraSoon_Rechts_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define UltraSoon_Rechts_BLOCK_CONTROL_REG              (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define UltraSoon_Rechts_BLOCK_CONTROL_PTR              ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define UltraSoon_Rechts_COMMAND_REG                    (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define UltraSoon_Rechts_COMMAND_PTR                    ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define UltraSoon_Rechts_INTRRUPT_CAUSE_REG             (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define UltraSoon_Rechts_INTRRUPT_CAUSE_PTR             ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define UltraSoon_Rechts_CONTROL_REG                    (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__CTRL )
#define UltraSoon_Rechts_CONTROL_PTR                    ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__CTRL )
#define UltraSoon_Rechts_STATUS_REG                     (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__STATUS )
#define UltraSoon_Rechts_STATUS_PTR                     ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__STATUS )
#define UltraSoon_Rechts_COUNTER_REG                    (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__COUNTER )
#define UltraSoon_Rechts_COUNTER_PTR                    ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__COUNTER )
#define UltraSoon_Rechts_COMP_CAP_REG                   (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__CC )
#define UltraSoon_Rechts_COMP_CAP_PTR                   ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__CC )
#define UltraSoon_Rechts_COMP_CAP_BUF_REG               (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__CC_BUFF )
#define UltraSoon_Rechts_COMP_CAP_BUF_PTR               ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__CC_BUFF )
#define UltraSoon_Rechts_PERIOD_REG                     (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__PERIOD )
#define UltraSoon_Rechts_PERIOD_PTR                     ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__PERIOD )
#define UltraSoon_Rechts_PERIOD_BUF_REG                 (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define UltraSoon_Rechts_PERIOD_BUF_PTR                 ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define UltraSoon_Rechts_TRIG_CONTROL0_REG              (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define UltraSoon_Rechts_TRIG_CONTROL0_PTR              ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define UltraSoon_Rechts_TRIG_CONTROL1_REG              (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define UltraSoon_Rechts_TRIG_CONTROL1_PTR              ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define UltraSoon_Rechts_TRIG_CONTROL2_REG              (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define UltraSoon_Rechts_TRIG_CONTROL2_PTR              ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define UltraSoon_Rechts_INTERRUPT_REQ_REG              (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__INTR )
#define UltraSoon_Rechts_INTERRUPT_REQ_PTR              ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__INTR )
#define UltraSoon_Rechts_INTERRUPT_SET_REG              (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__INTR_SET )
#define UltraSoon_Rechts_INTERRUPT_SET_PTR              ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__INTR_SET )
#define UltraSoon_Rechts_INTERRUPT_MASK_REG             (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__INTR_MASK )
#define UltraSoon_Rechts_INTERRUPT_MASK_PTR             ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__INTR_MASK )
#define UltraSoon_Rechts_INTERRUPT_MASKED_REG           (*(reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__INTR_MASKED )
#define UltraSoon_Rechts_INTERRUPT_MASKED_PTR           ( (reg32 *) UltraSoon_Rechts_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define UltraSoon_Rechts_MASK                           ((uint32)UltraSoon_Rechts_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define UltraSoon_Rechts_RELOAD_CC_SHIFT                (0u)
#define UltraSoon_Rechts_RELOAD_PERIOD_SHIFT            (1u)
#define UltraSoon_Rechts_PWM_SYNC_KILL_SHIFT            (2u)
#define UltraSoon_Rechts_PWM_STOP_KILL_SHIFT            (3u)
#define UltraSoon_Rechts_PRESCALER_SHIFT                (8u)
#define UltraSoon_Rechts_UPDOWN_SHIFT                   (16u)
#define UltraSoon_Rechts_ONESHOT_SHIFT                  (18u)
#define UltraSoon_Rechts_QUAD_MODE_SHIFT                (20u)
#define UltraSoon_Rechts_INV_OUT_SHIFT                  (20u)
#define UltraSoon_Rechts_INV_COMPL_OUT_SHIFT            (21u)
#define UltraSoon_Rechts_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define UltraSoon_Rechts_RELOAD_CC_MASK                 ((uint32)(UltraSoon_Rechts_1BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_RELOAD_CC_SHIFT))
#define UltraSoon_Rechts_RELOAD_PERIOD_MASK             ((uint32)(UltraSoon_Rechts_1BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_RELOAD_PERIOD_SHIFT))
#define UltraSoon_Rechts_PWM_SYNC_KILL_MASK             ((uint32)(UltraSoon_Rechts_1BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_PWM_SYNC_KILL_SHIFT))
#define UltraSoon_Rechts_PWM_STOP_KILL_MASK             ((uint32)(UltraSoon_Rechts_1BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_PWM_STOP_KILL_SHIFT))
#define UltraSoon_Rechts_PRESCALER_MASK                 ((uint32)(UltraSoon_Rechts_8BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_PRESCALER_SHIFT))
#define UltraSoon_Rechts_UPDOWN_MASK                    ((uint32)(UltraSoon_Rechts_2BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_UPDOWN_SHIFT))
#define UltraSoon_Rechts_ONESHOT_MASK                   ((uint32)(UltraSoon_Rechts_1BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_ONESHOT_SHIFT))
#define UltraSoon_Rechts_QUAD_MODE_MASK                 ((uint32)(UltraSoon_Rechts_3BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_QUAD_MODE_SHIFT))
#define UltraSoon_Rechts_INV_OUT_MASK                   ((uint32)(UltraSoon_Rechts_2BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_INV_OUT_SHIFT))
#define UltraSoon_Rechts_MODE_MASK                      ((uint32)(UltraSoon_Rechts_3BIT_MASK        <<  \
                                                                            UltraSoon_Rechts_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define UltraSoon_Rechts_CAPTURE_SHIFT                  (0u)
#define UltraSoon_Rechts_COUNT_SHIFT                    (2u)
#define UltraSoon_Rechts_RELOAD_SHIFT                   (4u)
#define UltraSoon_Rechts_STOP_SHIFT                     (6u)
#define UltraSoon_Rechts_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define UltraSoon_Rechts_CAPTURE_MASK                   ((uint32)(UltraSoon_Rechts_2BIT_MASK        <<  \
                                                                  UltraSoon_Rechts_CAPTURE_SHIFT))
#define UltraSoon_Rechts_COUNT_MASK                     ((uint32)(UltraSoon_Rechts_2BIT_MASK        <<  \
                                                                  UltraSoon_Rechts_COUNT_SHIFT))
#define UltraSoon_Rechts_RELOAD_MASK                    ((uint32)(UltraSoon_Rechts_2BIT_MASK        <<  \
                                                                  UltraSoon_Rechts_RELOAD_SHIFT))
#define UltraSoon_Rechts_STOP_MASK                      ((uint32)(UltraSoon_Rechts_2BIT_MASK        <<  \
                                                                  UltraSoon_Rechts_STOP_SHIFT))
#define UltraSoon_Rechts_START_MASK                     ((uint32)(UltraSoon_Rechts_2BIT_MASK        <<  \
                                                                  UltraSoon_Rechts_START_SHIFT))

/* MASK */
#define UltraSoon_Rechts_1BIT_MASK                      ((uint32)0x01u)
#define UltraSoon_Rechts_2BIT_MASK                      ((uint32)0x03u)
#define UltraSoon_Rechts_3BIT_MASK                      ((uint32)0x07u)
#define UltraSoon_Rechts_6BIT_MASK                      ((uint32)0x3Fu)
#define UltraSoon_Rechts_8BIT_MASK                      ((uint32)0xFFu)
#define UltraSoon_Rechts_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define UltraSoon_Rechts_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define UltraSoon_Rechts_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(UltraSoon_Rechts_QUAD_ENCODING_MODES     << UltraSoon_Rechts_QUAD_MODE_SHIFT))       |\
         ((uint32)(UltraSoon_Rechts_CONFIG                  << UltraSoon_Rechts_MODE_SHIFT)))

#define UltraSoon_Rechts_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(UltraSoon_Rechts_PWM_STOP_EVENT          << UltraSoon_Rechts_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(UltraSoon_Rechts_PWM_OUT_INVERT          << UltraSoon_Rechts_INV_OUT_SHIFT))         |\
         ((uint32)(UltraSoon_Rechts_PWM_OUT_N_INVERT        << UltraSoon_Rechts_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(UltraSoon_Rechts_PWM_MODE                << UltraSoon_Rechts_MODE_SHIFT)))

#define UltraSoon_Rechts_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(UltraSoon_Rechts_PWM_RUN_MODE         << UltraSoon_Rechts_ONESHOT_SHIFT))
            
#define UltraSoon_Rechts_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(UltraSoon_Rechts_PWM_ALIGN            << UltraSoon_Rechts_UPDOWN_SHIFT))

#define UltraSoon_Rechts_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(UltraSoon_Rechts_PWM_KILL_EVENT      << UltraSoon_Rechts_PWM_SYNC_KILL_SHIFT))

#define UltraSoon_Rechts_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(UltraSoon_Rechts_PWM_DEAD_TIME_CYCLE  << UltraSoon_Rechts_PRESCALER_SHIFT))

#define UltraSoon_Rechts_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(UltraSoon_Rechts_PWM_PRESCALER        << UltraSoon_Rechts_PRESCALER_SHIFT))

#define UltraSoon_Rechts_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(UltraSoon_Rechts_TC_PRESCALER            << UltraSoon_Rechts_PRESCALER_SHIFT))       |\
         ((uint32)(UltraSoon_Rechts_TC_COUNTER_MODE         << UltraSoon_Rechts_UPDOWN_SHIFT))          |\
         ((uint32)(UltraSoon_Rechts_TC_RUN_MODE             << UltraSoon_Rechts_ONESHOT_SHIFT))         |\
         ((uint32)(UltraSoon_Rechts_TC_COMP_CAP_MODE        << UltraSoon_Rechts_MODE_SHIFT)))
        
#define UltraSoon_Rechts_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(UltraSoon_Rechts_QUAD_PHIA_SIGNAL_MODE   << UltraSoon_Rechts_COUNT_SHIFT))           |\
         ((uint32)(UltraSoon_Rechts_QUAD_INDEX_SIGNAL_MODE  << UltraSoon_Rechts_RELOAD_SHIFT))          |\
         ((uint32)(UltraSoon_Rechts_QUAD_STOP_SIGNAL_MODE   << UltraSoon_Rechts_STOP_SHIFT))            |\
         ((uint32)(UltraSoon_Rechts_QUAD_PHIB_SIGNAL_MODE   << UltraSoon_Rechts_START_SHIFT)))

#define UltraSoon_Rechts_PWM_SIGNALS_MODES                                                              \
        (((uint32)(UltraSoon_Rechts_PWM_SWITCH_SIGNAL_MODE  << UltraSoon_Rechts_CAPTURE_SHIFT))         |\
         ((uint32)(UltraSoon_Rechts_PWM_COUNT_SIGNAL_MODE   << UltraSoon_Rechts_COUNT_SHIFT))           |\
         ((uint32)(UltraSoon_Rechts_PWM_RELOAD_SIGNAL_MODE  << UltraSoon_Rechts_RELOAD_SHIFT))          |\
         ((uint32)(UltraSoon_Rechts_PWM_STOP_SIGNAL_MODE    << UltraSoon_Rechts_STOP_SHIFT))            |\
         ((uint32)(UltraSoon_Rechts_PWM_START_SIGNAL_MODE   << UltraSoon_Rechts_START_SHIFT)))

#define UltraSoon_Rechts_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(UltraSoon_Rechts_TC_CAPTURE_SIGNAL_MODE  << UltraSoon_Rechts_CAPTURE_SHIFT))         |\
         ((uint32)(UltraSoon_Rechts_TC_COUNT_SIGNAL_MODE    << UltraSoon_Rechts_COUNT_SHIFT))           |\
         ((uint32)(UltraSoon_Rechts_TC_RELOAD_SIGNAL_MODE   << UltraSoon_Rechts_RELOAD_SHIFT))          |\
         ((uint32)(UltraSoon_Rechts_TC_STOP_SIGNAL_MODE     << UltraSoon_Rechts_STOP_SHIFT))            |\
         ((uint32)(UltraSoon_Rechts_TC_START_SIGNAL_MODE    << UltraSoon_Rechts_START_SHIFT)))
        
#define UltraSoon_Rechts_TIMER_UPDOWN_CNT_USED                                                          \
                ((UltraSoon_Rechts__COUNT_UPDOWN0 == UltraSoon_Rechts_TC_COUNTER_MODE)                  ||\
                 (UltraSoon_Rechts__COUNT_UPDOWN1 == UltraSoon_Rechts_TC_COUNTER_MODE))

#define UltraSoon_Rechts_PWM_UPDOWN_CNT_USED                                                            \
                ((UltraSoon_Rechts__CENTER == UltraSoon_Rechts_PWM_ALIGN)                               ||\
                 (UltraSoon_Rechts__ASYMMETRIC == UltraSoon_Rechts_PWM_ALIGN))               
        
#define UltraSoon_Rechts_PWM_PR_INIT_VALUE              (1u)
#define UltraSoon_Rechts_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_UltraSoon_Rechts_H */

/* [] END OF FILE */
