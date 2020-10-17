/*******************************************************************************
* File Name: Motor_Rechts.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_Motor_Rechts_H)
#define CY_PWM_Motor_Rechts_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Motor_Rechts_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define Motor_Rechts_Resolution                     (8u)
#define Motor_Rechts_UsingFixedFunction             (0u)
#define Motor_Rechts_DeadBandMode                   (0u)
#define Motor_Rechts_KillModeMinTime                (0u)
#define Motor_Rechts_KillMode                       (0u)
#define Motor_Rechts_PWMMode                        (0u)
#define Motor_Rechts_PWMModeIsCenterAligned         (0u)
#define Motor_Rechts_DeadBandUsed                   (0u)
#define Motor_Rechts_DeadBand2_4                    (0u)

#if !defined(Motor_Rechts_PWMUDB_genblk8_stsreg__REMOVED)
    #define Motor_Rechts_UseStatus                  (1u)
#else
    #define Motor_Rechts_UseStatus                  (0u)
#endif /* !defined(Motor_Rechts_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(Motor_Rechts_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define Motor_Rechts_UseControl                 (1u)
#else
    #define Motor_Rechts_UseControl                 (0u)
#endif /* !defined(Motor_Rechts_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define Motor_Rechts_UseOneCompareMode              (1u)
#define Motor_Rechts_MinimumKillTime                (1u)
#define Motor_Rechts_EnableMode                     (0u)

#define Motor_Rechts_CompareMode1SW                 (0u)
#define Motor_Rechts_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define Motor_Rechts__B_PWM__DISABLED 0
#define Motor_Rechts__B_PWM__ASYNCHRONOUS 1
#define Motor_Rechts__B_PWM__SINGLECYCLE 2
#define Motor_Rechts__B_PWM__LATCHED 3
#define Motor_Rechts__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define Motor_Rechts__B_PWM__DBMDISABLED 0
#define Motor_Rechts__B_PWM__DBM_2_4_CLOCKS 1
#define Motor_Rechts__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define Motor_Rechts__B_PWM__ONE_OUTPUT 0
#define Motor_Rechts__B_PWM__TWO_OUTPUTS 1
#define Motor_Rechts__B_PWM__DUAL_EDGE 2
#define Motor_Rechts__B_PWM__CENTER_ALIGN 3
#define Motor_Rechts__B_PWM__DITHER 5
#define Motor_Rechts__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define Motor_Rechts__B_PWM__LESS_THAN 1
#define Motor_Rechts__B_PWM__LESS_THAN_OR_EQUAL 2
#define Motor_Rechts__B_PWM__GREATER_THAN 3
#define Motor_Rechts__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define Motor_Rechts__B_PWM__EQUAL 0
#define Motor_Rechts__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!Motor_Rechts_UsingFixedFunction)
        uint8 PWMUdb;               /* PWM Current Counter value  */
        #if(!Motor_Rechts_PWMModeIsCenterAligned)
            uint8 PWMPeriod;
        #endif /* (!Motor_Rechts_PWMModeIsCenterAligned) */
        #if (Motor_Rechts_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (Motor_Rechts_UseStatus) */

        /* Backup for Deadband parameters */
        #if(Motor_Rechts_DeadBandMode == Motor_Rechts__B_PWM__DBM_256_CLOCKS || \
            Motor_Rechts_DeadBandMode == Motor_Rechts__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(Motor_Rechts_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (Motor_Rechts_KillModeMinTime) */

        /* Backup control register */
        #if(Motor_Rechts_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (Motor_Rechts_UseControl) */

    #endif /* (!Motor_Rechts_UsingFixedFunction) */

}Motor_Rechts_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    Motor_Rechts_Start(void) ;
void    Motor_Rechts_Stop(void) ;

#if (Motor_Rechts_UseStatus || Motor_Rechts_UsingFixedFunction)
    void  Motor_Rechts_SetInterruptMode(uint8 interruptMode) ;
    uint8 Motor_Rechts_ReadStatusRegister(void) ;
#endif /* (Motor_Rechts_UseStatus || Motor_Rechts_UsingFixedFunction) */

#define Motor_Rechts_GetInterruptSource() Motor_Rechts_ReadStatusRegister()

#if (Motor_Rechts_UseControl)
    uint8 Motor_Rechts_ReadControlRegister(void) ;
    void  Motor_Rechts_WriteControlRegister(uint8 control)
          ;
#endif /* (Motor_Rechts_UseControl) */

#if (Motor_Rechts_UseOneCompareMode)
   #if (Motor_Rechts_CompareMode1SW)
       void    Motor_Rechts_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (Motor_Rechts_CompareMode1SW) */
#else
    #if (Motor_Rechts_CompareMode1SW)
        void    Motor_Rechts_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (Motor_Rechts_CompareMode1SW) */
    #if (Motor_Rechts_CompareMode2SW)
        void    Motor_Rechts_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (Motor_Rechts_CompareMode2SW) */
#endif /* (Motor_Rechts_UseOneCompareMode) */

#if (!Motor_Rechts_UsingFixedFunction)
    uint8   Motor_Rechts_ReadCounter(void) ;
    uint8 Motor_Rechts_ReadCapture(void) ;

    #if (Motor_Rechts_UseStatus)
            void Motor_Rechts_ClearFIFO(void) ;
    #endif /* (Motor_Rechts_UseStatus) */

    void    Motor_Rechts_WriteCounter(uint8 counter)
            ;
#endif /* (!Motor_Rechts_UsingFixedFunction) */

void    Motor_Rechts_WritePeriod(uint8 period)
        ;
uint8 Motor_Rechts_ReadPeriod(void) ;

#if (Motor_Rechts_UseOneCompareMode)
    void    Motor_Rechts_WriteCompare(uint8 compare)
            ;
    uint8 Motor_Rechts_ReadCompare(void) ;
#else
    void    Motor_Rechts_WriteCompare1(uint8 compare)
            ;
    uint8 Motor_Rechts_ReadCompare1(void) ;
    void    Motor_Rechts_WriteCompare2(uint8 compare)
            ;
    uint8 Motor_Rechts_ReadCompare2(void) ;
#endif /* (Motor_Rechts_UseOneCompareMode) */


#if (Motor_Rechts_DeadBandUsed)
    void    Motor_Rechts_WriteDeadTime(uint8 deadtime) ;
    uint8   Motor_Rechts_ReadDeadTime(void) ;
#endif /* (Motor_Rechts_DeadBandUsed) */

#if ( Motor_Rechts_KillModeMinTime)
    void Motor_Rechts_WriteKillTime(uint8 killtime) ;
    uint8 Motor_Rechts_ReadKillTime(void) ;
#endif /* ( Motor_Rechts_KillModeMinTime) */

void Motor_Rechts_Init(void) ;
void Motor_Rechts_Enable(void) ;
void Motor_Rechts_Sleep(void) ;
void Motor_Rechts_Wakeup(void) ;
void Motor_Rechts_SaveConfig(void) ;
void Motor_Rechts_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define Motor_Rechts_INIT_PERIOD_VALUE          (255u)
#define Motor_Rechts_INIT_COMPARE_VALUE1        (127u)
#define Motor_Rechts_INIT_COMPARE_VALUE2        (63u)
#define Motor_Rechts_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    Motor_Rechts_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Motor_Rechts_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Motor_Rechts_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Motor_Rechts_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define Motor_Rechts_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  Motor_Rechts_CTRL_CMPMODE2_SHIFT)
#define Motor_Rechts_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  Motor_Rechts_CTRL_CMPMODE1_SHIFT)
#define Motor_Rechts_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (Motor_Rechts_UsingFixedFunction)
   #define Motor_Rechts_PERIOD_LSB              (*(reg16 *) Motor_Rechts_PWMHW__PER0)
   #define Motor_Rechts_PERIOD_LSB_PTR          ( (reg16 *) Motor_Rechts_PWMHW__PER0)
   #define Motor_Rechts_COMPARE1_LSB            (*(reg16 *) Motor_Rechts_PWMHW__CNT_CMP0)
   #define Motor_Rechts_COMPARE1_LSB_PTR        ( (reg16 *) Motor_Rechts_PWMHW__CNT_CMP0)
   #define Motor_Rechts_COMPARE2_LSB            (0x00u)
   #define Motor_Rechts_COMPARE2_LSB_PTR        (0x00u)
   #define Motor_Rechts_COUNTER_LSB             (*(reg16 *) Motor_Rechts_PWMHW__CNT_CMP0)
   #define Motor_Rechts_COUNTER_LSB_PTR         ( (reg16 *) Motor_Rechts_PWMHW__CNT_CMP0)
   #define Motor_Rechts_CAPTURE_LSB             (*(reg16 *) Motor_Rechts_PWMHW__CAP0)
   #define Motor_Rechts_CAPTURE_LSB_PTR         ( (reg16 *) Motor_Rechts_PWMHW__CAP0)
   #define Motor_Rechts_RT1                     (*(reg8 *)  Motor_Rechts_PWMHW__RT1)
   #define Motor_Rechts_RT1_PTR                 ( (reg8 *)  Motor_Rechts_PWMHW__RT1)

#else
   #if (Motor_Rechts_Resolution == 8u) /* 8bit - PWM */

       #if(Motor_Rechts_PWMModeIsCenterAligned)
           #define Motor_Rechts_PERIOD_LSB      (*(reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D1_REG)
           #define Motor_Rechts_PERIOD_LSB_PTR  ((reg8 *)   Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #else
           #define Motor_Rechts_PERIOD_LSB      (*(reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__F0_REG)
           #define Motor_Rechts_PERIOD_LSB_PTR  ((reg8 *)   Motor_Rechts_PWMUDB_sP8_pwmdp_u0__F0_REG)
       #endif /* (Motor_Rechts_PWMModeIsCenterAligned) */

       #define Motor_Rechts_COMPARE1_LSB        (*(reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define Motor_Rechts_COMPARE1_LSB_PTR    ((reg8 *)   Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define Motor_Rechts_COMPARE2_LSB        (*(reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define Motor_Rechts_COMPARE2_LSB_PTR    ((reg8 *)   Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define Motor_Rechts_COUNTERCAP_LSB      (*(reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define Motor_Rechts_COUNTERCAP_LSB_PTR  ((reg8 *)   Motor_Rechts_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define Motor_Rechts_COUNTER_LSB         (*(reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define Motor_Rechts_COUNTER_LSB_PTR     ((reg8 *)   Motor_Rechts_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define Motor_Rechts_CAPTURE_LSB         (*(reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__F1_REG)
       #define Motor_Rechts_CAPTURE_LSB_PTR     ((reg8 *)   Motor_Rechts_PWMUDB_sP8_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(Motor_Rechts_PWMModeIsCenterAligned)
               #define Motor_Rechts_PERIOD_LSB      (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D1_REG)
               #define Motor_Rechts_PERIOD_LSB_PTR  ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #else
               #define Motor_Rechts_PERIOD_LSB      (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__F0_REG)
               #define Motor_Rechts_PERIOD_LSB_PTR  ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__F0_REG)
            #endif /* (Motor_Rechts_PWMModeIsCenterAligned) */

            #define Motor_Rechts_COMPARE1_LSB       (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define Motor_Rechts_COMPARE1_LSB_PTR   ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define Motor_Rechts_COMPARE2_LSB       (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define Motor_Rechts_COMPARE2_LSB_PTR   ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define Motor_Rechts_COUNTERCAP_LSB     (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define Motor_Rechts_COUNTERCAP_LSB_PTR ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define Motor_Rechts_COUNTER_LSB        (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define Motor_Rechts_COUNTER_LSB_PTR    ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define Motor_Rechts_CAPTURE_LSB        (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__F1_REG)
            #define Motor_Rechts_CAPTURE_LSB_PTR    ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__F1_REG)
        #else
            #if(Motor_Rechts_PWMModeIsCenterAligned)
               #define Motor_Rechts_PERIOD_LSB      (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
               #define Motor_Rechts_PERIOD_LSB_PTR  ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #else
               #define Motor_Rechts_PERIOD_LSB      (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
               #define Motor_Rechts_PERIOD_LSB_PTR  ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
            #endif /* (Motor_Rechts_PWMModeIsCenterAligned) */

            #define Motor_Rechts_COMPARE1_LSB       (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define Motor_Rechts_COMPARE1_LSB_PTR   ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define Motor_Rechts_COMPARE2_LSB       (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define Motor_Rechts_COMPARE2_LSB_PTR   ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define Motor_Rechts_COUNTERCAP_LSB     (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define Motor_Rechts_COUNTERCAP_LSB_PTR ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define Motor_Rechts_COUNTER_LSB        (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define Motor_Rechts_COUNTER_LSB_PTR    ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define Motor_Rechts_CAPTURE_LSB        (*(reg16 *) Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
            #define Motor_Rechts_CAPTURE_LSB_PTR    ((reg16 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define Motor_Rechts_AUX_CONTROLDP1          (*(reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)
       #define Motor_Rechts_AUX_CONTROLDP1_PTR      ((reg8 *)   Motor_Rechts_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (Motor_Rechts_Resolution == 8) */

   #define Motor_Rechts_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__A1_REG)
   #define Motor_Rechts_AUX_CONTROLDP0          (*(reg8 *)  Motor_Rechts_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)
   #define Motor_Rechts_AUX_CONTROLDP0_PTR      ((reg8 *)   Motor_Rechts_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (Motor_Rechts_UsingFixedFunction) */

#if(Motor_Rechts_KillModeMinTime )
    #define Motor_Rechts_KILLMODEMINTIME        (*(reg8 *)  Motor_Rechts_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define Motor_Rechts_KILLMODEMINTIME_PTR    ((reg8 *)   Motor_Rechts_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (Motor_Rechts_KillModeMinTime ) */

#if(Motor_Rechts_DeadBandMode == Motor_Rechts__B_PWM__DBM_256_CLOCKS)
    #define Motor_Rechts_DEADBAND_COUNT         (*(reg8 *)  Motor_Rechts_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Motor_Rechts_DEADBAND_COUNT_PTR     ((reg8 *)   Motor_Rechts_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Motor_Rechts_DEADBAND_LSB_PTR       ((reg8 *)   Motor_Rechts_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define Motor_Rechts_DEADBAND_LSB           (*(reg8 *)  Motor_Rechts_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(Motor_Rechts_DeadBandMode == Motor_Rechts__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (Motor_Rechts_UsingFixedFunction)
        #define Motor_Rechts_DEADBAND_COUNT         (*(reg8 *)  Motor_Rechts_PWMHW__CFG0)
        #define Motor_Rechts_DEADBAND_COUNT_PTR     ((reg8 *)   Motor_Rechts_PWMHW__CFG0)
        #define Motor_Rechts_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Motor_Rechts_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define Motor_Rechts_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define Motor_Rechts_DEADBAND_COUNT         (*(reg8 *)  Motor_Rechts_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Motor_Rechts_DEADBAND_COUNT_PTR     ((reg8 *)   Motor_Rechts_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Motor_Rechts_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Motor_Rechts_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define Motor_Rechts_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (Motor_Rechts_UsingFixedFunction) */
#endif /* (Motor_Rechts_DeadBandMode == Motor_Rechts__B_PWM__DBM_256_CLOCKS) */



#if (Motor_Rechts_UsingFixedFunction)
    #define Motor_Rechts_STATUS                 (*(reg8 *) Motor_Rechts_PWMHW__SR0)
    #define Motor_Rechts_STATUS_PTR             ((reg8 *) Motor_Rechts_PWMHW__SR0)
    #define Motor_Rechts_STATUS_MASK            (*(reg8 *) Motor_Rechts_PWMHW__SR0)
    #define Motor_Rechts_STATUS_MASK_PTR        ((reg8 *) Motor_Rechts_PWMHW__SR0)
    #define Motor_Rechts_CONTROL                (*(reg8 *) Motor_Rechts_PWMHW__CFG0)
    #define Motor_Rechts_CONTROL_PTR            ((reg8 *) Motor_Rechts_PWMHW__CFG0)
    #define Motor_Rechts_CONTROL2               (*(reg8 *) Motor_Rechts_PWMHW__CFG1)
    #define Motor_Rechts_CONTROL3               (*(reg8 *) Motor_Rechts_PWMHW__CFG2)
    #define Motor_Rechts_GLOBAL_ENABLE          (*(reg8 *) Motor_Rechts_PWMHW__PM_ACT_CFG)
    #define Motor_Rechts_GLOBAL_ENABLE_PTR      ( (reg8 *) Motor_Rechts_PWMHW__PM_ACT_CFG)
    #define Motor_Rechts_GLOBAL_STBY_ENABLE     (*(reg8 *) Motor_Rechts_PWMHW__PM_STBY_CFG)
    #define Motor_Rechts_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) Motor_Rechts_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define Motor_Rechts_BLOCK_EN_MASK          (Motor_Rechts_PWMHW__PM_ACT_MSK)
    #define Motor_Rechts_BLOCK_STBY_EN_MASK     (Motor_Rechts_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define Motor_Rechts_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define Motor_Rechts_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define Motor_Rechts_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define Motor_Rechts_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define Motor_Rechts_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define Motor_Rechts_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define Motor_Rechts_CTRL_ENABLE            (uint8)((uint8)0x01u << Motor_Rechts_CTRL_ENABLE_SHIFT)
    #define Motor_Rechts_CTRL_RESET             (uint8)((uint8)0x01u << Motor_Rechts_CTRL_RESET_SHIFT)
    #define Motor_Rechts_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Motor_Rechts_CTRL_CMPMODE2_SHIFT)
    #define Motor_Rechts_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Motor_Rechts_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Motor_Rechts_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define Motor_Rechts_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << Motor_Rechts_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define Motor_Rechts_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define Motor_Rechts_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define Motor_Rechts_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define Motor_Rechts_STATUS_TC_INT_EN_MASK_SHIFT            (Motor_Rechts_STATUS_TC_SHIFT - 4u)
    #define Motor_Rechts_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define Motor_Rechts_STATUS_CMP1_INT_EN_MASK_SHIFT          (Motor_Rechts_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define Motor_Rechts_STATUS_TC              (uint8)((uint8)0x01u << Motor_Rechts_STATUS_TC_SHIFT)
    #define Motor_Rechts_STATUS_CMP1            (uint8)((uint8)0x01u << Motor_Rechts_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define Motor_Rechts_STATUS_TC_INT_EN_MASK              (uint8)((uint8)Motor_Rechts_STATUS_TC >> 4u)
    #define Motor_Rechts_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)Motor_Rechts_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define Motor_Rechts_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define Motor_Rechts_RT1_MASK              (uint8)((uint8)0x03u << Motor_Rechts_RT1_SHIFT)
    #define Motor_Rechts_SYNC                  (uint8)((uint8)0x03u << Motor_Rechts_RT1_SHIFT)
    #define Motor_Rechts_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define Motor_Rechts_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << Motor_Rechts_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define Motor_Rechts_SYNCDSI_EN            (uint8)((uint8)0x0Fu << Motor_Rechts_SYNCDSI_SHIFT)


#else
    #define Motor_Rechts_STATUS                (*(reg8 *)   Motor_Rechts_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Motor_Rechts_STATUS_PTR            ((reg8 *)    Motor_Rechts_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Motor_Rechts_STATUS_MASK           (*(reg8 *)   Motor_Rechts_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Motor_Rechts_STATUS_MASK_PTR       ((reg8 *)    Motor_Rechts_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Motor_Rechts_STATUS_AUX_CTRL       (*(reg8 *)   Motor_Rechts_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define Motor_Rechts_CONTROL               (*(reg8 *)   Motor_Rechts_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define Motor_Rechts_CONTROL_PTR           ((reg8 *)    Motor_Rechts_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define Motor_Rechts_CTRL_ENABLE_SHIFT      (0x07u)
    #define Motor_Rechts_CTRL_RESET_SHIFT       (0x06u)
    #define Motor_Rechts_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define Motor_Rechts_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define Motor_Rechts_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define Motor_Rechts_CTRL_ENABLE            (uint8)((uint8)0x01u << Motor_Rechts_CTRL_ENABLE_SHIFT)
    #define Motor_Rechts_CTRL_RESET             (uint8)((uint8)0x01u << Motor_Rechts_CTRL_RESET_SHIFT)
    #define Motor_Rechts_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Motor_Rechts_CTRL_CMPMODE2_SHIFT)
    #define Motor_Rechts_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Motor_Rechts_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define Motor_Rechts_STATUS_KILL_SHIFT          (0x05u)
    #define Motor_Rechts_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define Motor_Rechts_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define Motor_Rechts_STATUS_TC_SHIFT            (0x02u)
    #define Motor_Rechts_STATUS_CMP2_SHIFT          (0x01u)
    #define Motor_Rechts_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Motor_Rechts_STATUS_KILL_INT_EN_MASK_SHIFT          (Motor_Rechts_STATUS_KILL_SHIFT)
    #define Motor_Rechts_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (Motor_Rechts_STATUS_FIFONEMPTY_SHIFT)
    #define Motor_Rechts_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (Motor_Rechts_STATUS_FIFOFULL_SHIFT)
    #define Motor_Rechts_STATUS_TC_INT_EN_MASK_SHIFT            (Motor_Rechts_STATUS_TC_SHIFT)
    #define Motor_Rechts_STATUS_CMP2_INT_EN_MASK_SHIFT          (Motor_Rechts_STATUS_CMP2_SHIFT)
    #define Motor_Rechts_STATUS_CMP1_INT_EN_MASK_SHIFT          (Motor_Rechts_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define Motor_Rechts_STATUS_KILL            (uint8)((uint8)0x00u << Motor_Rechts_STATUS_KILL_SHIFT )
    #define Motor_Rechts_STATUS_FIFOFULL        (uint8)((uint8)0x01u << Motor_Rechts_STATUS_FIFOFULL_SHIFT)
    #define Motor_Rechts_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << Motor_Rechts_STATUS_FIFONEMPTY_SHIFT)
    #define Motor_Rechts_STATUS_TC              (uint8)((uint8)0x01u << Motor_Rechts_STATUS_TC_SHIFT)
    #define Motor_Rechts_STATUS_CMP2            (uint8)((uint8)0x01u << Motor_Rechts_STATUS_CMP2_SHIFT)
    #define Motor_Rechts_STATUS_CMP1            (uint8)((uint8)0x01u << Motor_Rechts_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Motor_Rechts_STATUS_KILL_INT_EN_MASK            (Motor_Rechts_STATUS_KILL)
    #define Motor_Rechts_STATUS_FIFOFULL_INT_EN_MASK        (Motor_Rechts_STATUS_FIFOFULL)
    #define Motor_Rechts_STATUS_FIFONEMPTY_INT_EN_MASK      (Motor_Rechts_STATUS_FIFONEMPTY)
    #define Motor_Rechts_STATUS_TC_INT_EN_MASK              (Motor_Rechts_STATUS_TC)
    #define Motor_Rechts_STATUS_CMP2_INT_EN_MASK            (Motor_Rechts_STATUS_CMP2)
    #define Motor_Rechts_STATUS_CMP1_INT_EN_MASK            (Motor_Rechts_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define Motor_Rechts_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define Motor_Rechts_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define Motor_Rechts_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define Motor_Rechts_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define Motor_Rechts_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* Motor_Rechts_UsingFixedFunction */

#endif  /* CY_PWM_Motor_Rechts_H */


/* [] END OF FILE */
