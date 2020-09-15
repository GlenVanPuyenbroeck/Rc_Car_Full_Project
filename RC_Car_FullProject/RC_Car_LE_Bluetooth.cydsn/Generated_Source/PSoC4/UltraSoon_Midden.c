/*******************************************************************************
* File Name: UltraSoon_Midden.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the UltraSoon_Midden
*  component
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

#include "UltraSoon_Midden.h"

uint8 UltraSoon_Midden_initVar = 0u;


/*******************************************************************************
* Function Name: UltraSoon_Midden_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default UltraSoon_Midden configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (UltraSoon_Midden__QUAD == UltraSoon_Midden_CONFIG)
        UltraSoon_Midden_CONTROL_REG = UltraSoon_Midden_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        UltraSoon_Midden_TRIG_CONTROL1_REG  = UltraSoon_Midden_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        UltraSoon_Midden_SetInterruptMode(UltraSoon_Midden_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        UltraSoon_Midden_SetCounterMode(UltraSoon_Midden_COUNT_DOWN);
        UltraSoon_Midden_WritePeriod(UltraSoon_Midden_QUAD_PERIOD_INIT_VALUE);
        UltraSoon_Midden_WriteCounter(UltraSoon_Midden_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (UltraSoon_Midden__QUAD == UltraSoon_Midden_CONFIG) */

    #if (UltraSoon_Midden__TIMER == UltraSoon_Midden_CONFIG)
        UltraSoon_Midden_CONTROL_REG = UltraSoon_Midden_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        UltraSoon_Midden_TRIG_CONTROL1_REG  = UltraSoon_Midden_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        UltraSoon_Midden_SetInterruptMode(UltraSoon_Midden_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        UltraSoon_Midden_WritePeriod(UltraSoon_Midden_TC_PERIOD_VALUE );

        #if (UltraSoon_Midden__COMPARE == UltraSoon_Midden_TC_COMP_CAP_MODE)
            UltraSoon_Midden_WriteCompare(UltraSoon_Midden_TC_COMPARE_VALUE);

            #if (1u == UltraSoon_Midden_TC_COMPARE_SWAP)
                UltraSoon_Midden_SetCompareSwap(1u);
                UltraSoon_Midden_WriteCompareBuf(UltraSoon_Midden_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == UltraSoon_Midden_TC_COMPARE_SWAP) */
        #endif  /* (UltraSoon_Midden__COMPARE == UltraSoon_Midden_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (UltraSoon_Midden_CY_TCPWM_V2 && UltraSoon_Midden_TIMER_UPDOWN_CNT_USED && !UltraSoon_Midden_CY_TCPWM_4000)
            UltraSoon_Midden_WriteCounter(1u);
        #elif(UltraSoon_Midden__COUNT_DOWN == UltraSoon_Midden_TC_COUNTER_MODE)
            UltraSoon_Midden_WriteCounter(UltraSoon_Midden_TC_PERIOD_VALUE);
        #else
            UltraSoon_Midden_WriteCounter(0u);
        #endif /* (UltraSoon_Midden_CY_TCPWM_V2 && UltraSoon_Midden_TIMER_UPDOWN_CNT_USED && !UltraSoon_Midden_CY_TCPWM_4000) */
    #endif  /* (UltraSoon_Midden__TIMER == UltraSoon_Midden_CONFIG) */

    #if (UltraSoon_Midden__PWM_SEL == UltraSoon_Midden_CONFIG)
        UltraSoon_Midden_CONTROL_REG = UltraSoon_Midden_CTRL_PWM_BASE_CONFIG;

        #if (UltraSoon_Midden__PWM_PR == UltraSoon_Midden_PWM_MODE)
            UltraSoon_Midden_CONTROL_REG |= UltraSoon_Midden_CTRL_PWM_RUN_MODE;
            UltraSoon_Midden_WriteCounter(UltraSoon_Midden_PWM_PR_INIT_VALUE);
        #else
            UltraSoon_Midden_CONTROL_REG |= UltraSoon_Midden_CTRL_PWM_ALIGN | UltraSoon_Midden_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (UltraSoon_Midden_CY_TCPWM_V2 && UltraSoon_Midden_PWM_UPDOWN_CNT_USED && !UltraSoon_Midden_CY_TCPWM_4000)
                UltraSoon_Midden_WriteCounter(1u);
            #elif (UltraSoon_Midden__RIGHT == UltraSoon_Midden_PWM_ALIGN)
                UltraSoon_Midden_WriteCounter(UltraSoon_Midden_PWM_PERIOD_VALUE);
            #else 
                UltraSoon_Midden_WriteCounter(0u);
            #endif  /* (UltraSoon_Midden_CY_TCPWM_V2 && UltraSoon_Midden_PWM_UPDOWN_CNT_USED && !UltraSoon_Midden_CY_TCPWM_4000) */
        #endif  /* (UltraSoon_Midden__PWM_PR == UltraSoon_Midden_PWM_MODE) */

        #if (UltraSoon_Midden__PWM_DT == UltraSoon_Midden_PWM_MODE)
            UltraSoon_Midden_CONTROL_REG |= UltraSoon_Midden_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (UltraSoon_Midden__PWM_DT == UltraSoon_Midden_PWM_MODE) */

        #if (UltraSoon_Midden__PWM == UltraSoon_Midden_PWM_MODE)
            UltraSoon_Midden_CONTROL_REG |= UltraSoon_Midden_CTRL_PWM_PRESCALER;
        #endif  /* (UltraSoon_Midden__PWM == UltraSoon_Midden_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        UltraSoon_Midden_TRIG_CONTROL1_REG  = UltraSoon_Midden_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        UltraSoon_Midden_SetInterruptMode(UltraSoon_Midden_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (UltraSoon_Midden__PWM_PR == UltraSoon_Midden_PWM_MODE)
            UltraSoon_Midden_TRIG_CONTROL2_REG =
                    (UltraSoon_Midden_CC_MATCH_NO_CHANGE    |
                    UltraSoon_Midden_OVERLOW_NO_CHANGE      |
                    UltraSoon_Midden_UNDERFLOW_NO_CHANGE);
        #else
            #if (UltraSoon_Midden__LEFT == UltraSoon_Midden_PWM_ALIGN)
                UltraSoon_Midden_TRIG_CONTROL2_REG = UltraSoon_Midden_PWM_MODE_LEFT;
            #endif  /* ( UltraSoon_Midden_PWM_LEFT == UltraSoon_Midden_PWM_ALIGN) */

            #if (UltraSoon_Midden__RIGHT == UltraSoon_Midden_PWM_ALIGN)
                UltraSoon_Midden_TRIG_CONTROL2_REG = UltraSoon_Midden_PWM_MODE_RIGHT;
            #endif  /* ( UltraSoon_Midden_PWM_RIGHT == UltraSoon_Midden_PWM_ALIGN) */

            #if (UltraSoon_Midden__CENTER == UltraSoon_Midden_PWM_ALIGN)
                UltraSoon_Midden_TRIG_CONTROL2_REG = UltraSoon_Midden_PWM_MODE_CENTER;
            #endif  /* ( UltraSoon_Midden_PWM_CENTER == UltraSoon_Midden_PWM_ALIGN) */

            #if (UltraSoon_Midden__ASYMMETRIC == UltraSoon_Midden_PWM_ALIGN)
                UltraSoon_Midden_TRIG_CONTROL2_REG = UltraSoon_Midden_PWM_MODE_ASYM;
            #endif  /* (UltraSoon_Midden__ASYMMETRIC == UltraSoon_Midden_PWM_ALIGN) */
        #endif  /* (UltraSoon_Midden__PWM_PR == UltraSoon_Midden_PWM_MODE) */

        /* Set other values from customizer */
        UltraSoon_Midden_WritePeriod(UltraSoon_Midden_PWM_PERIOD_VALUE );
        UltraSoon_Midden_WriteCompare(UltraSoon_Midden_PWM_COMPARE_VALUE);

        #if (1u == UltraSoon_Midden_PWM_COMPARE_SWAP)
            UltraSoon_Midden_SetCompareSwap(1u);
            UltraSoon_Midden_WriteCompareBuf(UltraSoon_Midden_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == UltraSoon_Midden_PWM_COMPARE_SWAP) */

        #if (1u == UltraSoon_Midden_PWM_PERIOD_SWAP)
            UltraSoon_Midden_SetPeriodSwap(1u);
            UltraSoon_Midden_WritePeriodBuf(UltraSoon_Midden_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == UltraSoon_Midden_PWM_PERIOD_SWAP) */
    #endif  /* (UltraSoon_Midden__PWM_SEL == UltraSoon_Midden_CONFIG) */
    
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_Enable
********************************************************************************
*
* Summary:
*  Enables the UltraSoon_Midden.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    UltraSoon_Midden_BLOCK_CONTROL_REG |= UltraSoon_Midden_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (UltraSoon_Midden__PWM_SEL == UltraSoon_Midden_CONFIG)
        #if (0u == UltraSoon_Midden_PWM_START_SIGNAL_PRESENT)
            UltraSoon_Midden_TriggerCommand(UltraSoon_Midden_MASK, UltraSoon_Midden_CMD_START);
        #endif /* (0u == UltraSoon_Midden_PWM_START_SIGNAL_PRESENT) */
    #endif /* (UltraSoon_Midden__PWM_SEL == UltraSoon_Midden_CONFIG) */

    #if (UltraSoon_Midden__TIMER == UltraSoon_Midden_CONFIG)
        #if (0u == UltraSoon_Midden_TC_START_SIGNAL_PRESENT)
            UltraSoon_Midden_TriggerCommand(UltraSoon_Midden_MASK, UltraSoon_Midden_CMD_START);
        #endif /* (0u == UltraSoon_Midden_TC_START_SIGNAL_PRESENT) */
    #endif /* (UltraSoon_Midden__TIMER == UltraSoon_Midden_CONFIG) */
    
    #if (UltraSoon_Midden__QUAD == UltraSoon_Midden_CONFIG)
        #if (0u != UltraSoon_Midden_QUAD_AUTO_START)
            UltraSoon_Midden_TriggerCommand(UltraSoon_Midden_MASK, UltraSoon_Midden_CMD_RELOAD);
        #endif /* (0u != UltraSoon_Midden_QUAD_AUTO_START) */
    #endif  /* (UltraSoon_Midden__QUAD == UltraSoon_Midden_CONFIG) */
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_Start
********************************************************************************
*
* Summary:
*  Initializes the UltraSoon_Midden with default customizer
*  values when called the first time and enables the UltraSoon_Midden.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  UltraSoon_Midden_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time UltraSoon_Midden_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the UltraSoon_Midden_Start() routine.
*
*******************************************************************************/
void UltraSoon_Midden_Start(void)
{
    if (0u == UltraSoon_Midden_initVar)
    {
        UltraSoon_Midden_Init();
        UltraSoon_Midden_initVar = 1u;
    }

    UltraSoon_Midden_Enable();
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_Stop
********************************************************************************
*
* Summary:
*  Disables the UltraSoon_Midden.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_BLOCK_CONTROL_REG &= (uint32)~UltraSoon_Midden_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the UltraSoon_Midden. This function is used when
*  configured as a generic UltraSoon_Midden and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the UltraSoon_Midden to operate in
*   Values:
*   - UltraSoon_Midden_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - UltraSoon_Midden_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - UltraSoon_Midden_MODE_QUAD - Quadrature decoder
*         - UltraSoon_Midden_MODE_PWM - PWM
*         - UltraSoon_Midden_MODE_PWM_DT - PWM with dead time
*         - UltraSoon_Midden_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_MODE_MASK;
    UltraSoon_Midden_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - UltraSoon_Midden_MODE_X1 - Counts on phi 1 rising
*         - UltraSoon_Midden_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - UltraSoon_Midden_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_QUAD_MODE_MASK;
    UltraSoon_Midden_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - UltraSoon_Midden_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - UltraSoon_Midden_PRESCALE_DIVBY2    - Divide by 2
*         - UltraSoon_Midden_PRESCALE_DIVBY4    - Divide by 4
*         - UltraSoon_Midden_PRESCALE_DIVBY8    - Divide by 8
*         - UltraSoon_Midden_PRESCALE_DIVBY16   - Divide by 16
*         - UltraSoon_Midden_PRESCALE_DIVBY32   - Divide by 32
*         - UltraSoon_Midden_PRESCALE_DIVBY64   - Divide by 64
*         - UltraSoon_Midden_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_PRESCALER_MASK;
    UltraSoon_Midden_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the UltraSoon_Midden runs
*  continuously or stops when terminal count is reached.  By default the
*  UltraSoon_Midden operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_ONESHOT_MASK;
    UltraSoon_Midden_CONTROL_REG |= ((uint32)((oneShotEnable & UltraSoon_Midden_1BIT_MASK) <<
                                                               UltraSoon_Midden_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetPWMMode(uint32 modeMask)
{
    UltraSoon_Midden_TRIG_CONTROL2_REG = (modeMask & UltraSoon_Midden_6BIT_MASK);
}



/*******************************************************************************
* Function Name: UltraSoon_Midden_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_PWM_SYNC_KILL_MASK;
    UltraSoon_Midden_CONTROL_REG |= ((uint32)((syncKillEnable & UltraSoon_Midden_1BIT_MASK)  <<
                                               UltraSoon_Midden_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_PWM_STOP_KILL_MASK;
    UltraSoon_Midden_CONTROL_REG |= ((uint32)((stopOnKillEnable & UltraSoon_Midden_1BIT_MASK)  <<
                                                         UltraSoon_Midden_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_PRESCALER_MASK;
    UltraSoon_Midden_CONTROL_REG |= ((uint32)((deadTime & UltraSoon_Midden_8BIT_MASK) <<
                                                          UltraSoon_Midden_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - UltraSoon_Midden_INVERT_LINE   - Inverts the line output
*         - UltraSoon_Midden_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_INV_OUT_MASK;
    UltraSoon_Midden_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: UltraSoon_Midden_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_WriteCounter(uint32 count)
{
    UltraSoon_Midden_COUNTER_REG = (count & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 UltraSoon_Midden_ReadCounter(void)
{
    return (UltraSoon_Midden_COUNTER_REG & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - UltraSoon_Midden_COUNT_UP       - Counts up
*     - UltraSoon_Midden_COUNT_DOWN     - Counts down
*     - UltraSoon_Midden_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - UltraSoon_Midden_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_UPDOWN_MASK;
    UltraSoon_Midden_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_WritePeriod(uint32 period)
{
    UltraSoon_Midden_PERIOD_REG = (period & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 UltraSoon_Midden_ReadPeriod(void)
{
    return (UltraSoon_Midden_PERIOD_REG & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_RELOAD_CC_MASK;
    UltraSoon_Midden_CONTROL_REG |= (swapEnable & UltraSoon_Midden_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_WritePeriodBuf(uint32 periodBuf)
{
    UltraSoon_Midden_PERIOD_BUF_REG = (periodBuf & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 UltraSoon_Midden_ReadPeriodBuf(void)
{
    return (UltraSoon_Midden_PERIOD_BUF_REG & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_CONTROL_REG &= (uint32)~UltraSoon_Midden_RELOAD_PERIOD_MASK;
    UltraSoon_Midden_CONTROL_REG |= ((uint32)((swapEnable & UltraSoon_Midden_1BIT_MASK) <<
                                                            UltraSoon_Midden_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void UltraSoon_Midden_WriteCompare(uint32 compare)
{
    #if (UltraSoon_Midden_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (UltraSoon_Midden_CY_TCPWM_4000) */

    #if (UltraSoon_Midden_CY_TCPWM_4000)
        currentMode = ((UltraSoon_Midden_CONTROL_REG & UltraSoon_Midden_UPDOWN_MASK) >> UltraSoon_Midden_UPDOWN_SHIFT);

        if (((uint32)UltraSoon_Midden__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)UltraSoon_Midden__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (UltraSoon_Midden_CY_TCPWM_4000) */
    
    UltraSoon_Midden_COMP_CAP_REG = (compare & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 UltraSoon_Midden_ReadCompare(void)
{
    #if (UltraSoon_Midden_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (UltraSoon_Midden_CY_TCPWM_4000) */

    #if (UltraSoon_Midden_CY_TCPWM_4000)
        currentMode = ((UltraSoon_Midden_CONTROL_REG & UltraSoon_Midden_UPDOWN_MASK) >> UltraSoon_Midden_UPDOWN_SHIFT);
        
        regVal = UltraSoon_Midden_COMP_CAP_REG;
        
        if (((uint32)UltraSoon_Midden__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)UltraSoon_Midden__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & UltraSoon_Midden_16BIT_MASK);
    #else
        return (UltraSoon_Midden_COMP_CAP_REG & UltraSoon_Midden_16BIT_MASK);
    #endif /* (UltraSoon_Midden_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void UltraSoon_Midden_WriteCompareBuf(uint32 compareBuf)
{
    #if (UltraSoon_Midden_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (UltraSoon_Midden_CY_TCPWM_4000) */

    #if (UltraSoon_Midden_CY_TCPWM_4000)
        currentMode = ((UltraSoon_Midden_CONTROL_REG & UltraSoon_Midden_UPDOWN_MASK) >> UltraSoon_Midden_UPDOWN_SHIFT);

        if (((uint32)UltraSoon_Midden__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)UltraSoon_Midden__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (UltraSoon_Midden_CY_TCPWM_4000) */
    
    UltraSoon_Midden_COMP_CAP_BUF_REG = (compareBuf & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 UltraSoon_Midden_ReadCompareBuf(void)
{
    #if (UltraSoon_Midden_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (UltraSoon_Midden_CY_TCPWM_4000) */

    #if (UltraSoon_Midden_CY_TCPWM_4000)
        currentMode = ((UltraSoon_Midden_CONTROL_REG & UltraSoon_Midden_UPDOWN_MASK) >> UltraSoon_Midden_UPDOWN_SHIFT);

        regVal = UltraSoon_Midden_COMP_CAP_BUF_REG;
        
        if (((uint32)UltraSoon_Midden__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)UltraSoon_Midden__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & UltraSoon_Midden_16BIT_MASK);
    #else
        return (UltraSoon_Midden_COMP_CAP_BUF_REG & UltraSoon_Midden_16BIT_MASK);
    #endif /* (UltraSoon_Midden_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 UltraSoon_Midden_ReadCapture(void)
{
    return (UltraSoon_Midden_COMP_CAP_REG & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 UltraSoon_Midden_ReadCaptureBuf(void)
{
    return (UltraSoon_Midden_COMP_CAP_BUF_REG & UltraSoon_Midden_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UltraSoon_Midden_TRIG_LEVEL     - Level
*     - UltraSoon_Midden_TRIG_RISING    - Rising edge
*     - UltraSoon_Midden_TRIG_FALLING   - Falling edge
*     - UltraSoon_Midden_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_TRIG_CONTROL1_REG &= (uint32)~UltraSoon_Midden_CAPTURE_MASK;
    UltraSoon_Midden_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UltraSoon_Midden_TRIG_LEVEL     - Level
*     - UltraSoon_Midden_TRIG_RISING    - Rising edge
*     - UltraSoon_Midden_TRIG_FALLING   - Falling edge
*     - UltraSoon_Midden_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_TRIG_CONTROL1_REG &= (uint32)~UltraSoon_Midden_RELOAD_MASK;
    UltraSoon_Midden_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << UltraSoon_Midden_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UltraSoon_Midden_TRIG_LEVEL     - Level
*     - UltraSoon_Midden_TRIG_RISING    - Rising edge
*     - UltraSoon_Midden_TRIG_FALLING   - Falling edge
*     - UltraSoon_Midden_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_TRIG_CONTROL1_REG &= (uint32)~UltraSoon_Midden_START_MASK;
    UltraSoon_Midden_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << UltraSoon_Midden_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UltraSoon_Midden_TRIG_LEVEL     - Level
*     - UltraSoon_Midden_TRIG_RISING    - Rising edge
*     - UltraSoon_Midden_TRIG_FALLING   - Falling edge
*     - UltraSoon_Midden_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_TRIG_CONTROL1_REG &= (uint32)~UltraSoon_Midden_STOP_MASK;
    UltraSoon_Midden_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << UltraSoon_Midden_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UltraSoon_Midden_TRIG_LEVEL     - Level
*     - UltraSoon_Midden_TRIG_RISING    - Rising edge
*     - UltraSoon_Midden_TRIG_FALLING   - Falling edge
*     - UltraSoon_Midden_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_TRIG_CONTROL1_REG &= (uint32)~UltraSoon_Midden_COUNT_MASK;
    UltraSoon_Midden_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << UltraSoon_Midden_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - UltraSoon_Midden_CMD_CAPTURE    - Trigger Capture/Switch command
*     - UltraSoon_Midden_CMD_RELOAD     - Trigger Reload/Index command
*     - UltraSoon_Midden_CMD_STOP       - Trigger Stop/Kill command
*     - UltraSoon_Midden_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UltraSoon_Midden_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the UltraSoon_Midden.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - UltraSoon_Midden_STATUS_DOWN    - Set if counting down
*     - UltraSoon_Midden_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 UltraSoon_Midden_ReadStatus(void)
{
    return ((UltraSoon_Midden_STATUS_REG >> UltraSoon_Midden_RUNNING_STATUS_SHIFT) |
            (UltraSoon_Midden_STATUS_REG & UltraSoon_Midden_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - UltraSoon_Midden_INTR_MASK_TC       - Terminal count mask
*     - UltraSoon_Midden_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetInterruptMode(uint32 interruptMask)
{
    UltraSoon_Midden_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - UltraSoon_Midden_INTR_MASK_TC       - Terminal count mask
*     - UltraSoon_Midden_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 UltraSoon_Midden_GetInterruptSourceMasked(void)
{
    return (UltraSoon_Midden_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - UltraSoon_Midden_INTR_MASK_TC       - Terminal count mask
*     - UltraSoon_Midden_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 UltraSoon_Midden_GetInterruptSource(void)
{
    return (UltraSoon_Midden_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - UltraSoon_Midden_INTR_MASK_TC       - Terminal count mask
*     - UltraSoon_Midden_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_ClearInterrupt(uint32 interruptMask)
{
    UltraSoon_Midden_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: UltraSoon_Midden_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - UltraSoon_Midden_INTR_MASK_TC       - Terminal count mask
*     - UltraSoon_Midden_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void UltraSoon_Midden_SetInterrupt(uint32 interruptMask)
{
    UltraSoon_Midden_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
