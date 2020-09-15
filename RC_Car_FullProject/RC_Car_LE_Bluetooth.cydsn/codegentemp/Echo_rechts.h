/*******************************************************************************
* File Name: Echo_rechts.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Echo_rechts_H) /* Pins Echo_rechts_H */
#define CY_PINS_Echo_rechts_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Echo_rechts_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Echo_rechts_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Echo_rechts_Read(void);
void    Echo_rechts_Write(uint8 value);
uint8   Echo_rechts_ReadDataReg(void);
#if defined(Echo_rechts__PC) || (CY_PSOC4_4200L) 
    void    Echo_rechts_SetDriveMode(uint8 mode);
#endif
void    Echo_rechts_SetInterruptMode(uint16 position, uint16 mode);
uint8   Echo_rechts_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Echo_rechts_Sleep(void); 
void Echo_rechts_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Echo_rechts__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Echo_rechts_DRIVE_MODE_BITS        (3)
    #define Echo_rechts_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Echo_rechts_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Echo_rechts_SetDriveMode() function.
         *  @{
         */
        #define Echo_rechts_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Echo_rechts_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Echo_rechts_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Echo_rechts_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Echo_rechts_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Echo_rechts_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Echo_rechts_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Echo_rechts_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Echo_rechts_MASK               Echo_rechts__MASK
#define Echo_rechts_SHIFT              Echo_rechts__SHIFT
#define Echo_rechts_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Echo_rechts_SetInterruptMode() function.
     *  @{
     */
        #define Echo_rechts_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Echo_rechts_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Echo_rechts_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Echo_rechts_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Echo_rechts__SIO)
    #define Echo_rechts_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Echo_rechts__PC) && (CY_PSOC4_4200L)
    #define Echo_rechts_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Echo_rechts_USBIO_DISABLE              ((uint32)(~Echo_rechts_USBIO_ENABLE))
    #define Echo_rechts_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Echo_rechts_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Echo_rechts_USBIO_ENTER_SLEEP          ((uint32)((1u << Echo_rechts_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Echo_rechts_USBIO_SUSPEND_DEL_SHIFT)))
    #define Echo_rechts_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Echo_rechts_USBIO_SUSPEND_SHIFT)))
    #define Echo_rechts_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Echo_rechts_USBIO_SUSPEND_DEL_SHIFT)))
    #define Echo_rechts_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Echo_rechts__PC)
    /* Port Configuration */
    #define Echo_rechts_PC                 (* (reg32 *) Echo_rechts__PC)
#endif
/* Pin State */
#define Echo_rechts_PS                     (* (reg32 *) Echo_rechts__PS)
/* Data Register */
#define Echo_rechts_DR                     (* (reg32 *) Echo_rechts__DR)
/* Input Buffer Disable Override */
#define Echo_rechts_INP_DIS                (* (reg32 *) Echo_rechts__PC2)

/* Interrupt configuration Registers */
#define Echo_rechts_INTCFG                 (* (reg32 *) Echo_rechts__INTCFG)
#define Echo_rechts_INTSTAT                (* (reg32 *) Echo_rechts__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Echo_rechts_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Echo_rechts__SIO)
    #define Echo_rechts_SIO_REG            (* (reg32 *) Echo_rechts__SIO)
#endif /* (Echo_rechts__SIO_CFG) */

/* USBIO registers */
#if !defined(Echo_rechts__PC) && (CY_PSOC4_4200L)
    #define Echo_rechts_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Echo_rechts_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Echo_rechts_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Echo_rechts_DRIVE_MODE_SHIFT       (0x00u)
#define Echo_rechts_DRIVE_MODE_MASK        (0x07u << Echo_rechts_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Echo_rechts_H */


/* [] END OF FILE */
