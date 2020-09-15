/*******************************************************************************
* File Name: Echo_Links.h  
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

#if !defined(CY_PINS_Echo_Links_H) /* Pins Echo_Links_H */
#define CY_PINS_Echo_Links_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Echo_Links_aliases.h"


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
} Echo_Links_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Echo_Links_Read(void);
void    Echo_Links_Write(uint8 value);
uint8   Echo_Links_ReadDataReg(void);
#if defined(Echo_Links__PC) || (CY_PSOC4_4200L) 
    void    Echo_Links_SetDriveMode(uint8 mode);
#endif
void    Echo_Links_SetInterruptMode(uint16 position, uint16 mode);
uint8   Echo_Links_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Echo_Links_Sleep(void); 
void Echo_Links_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Echo_Links__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Echo_Links_DRIVE_MODE_BITS        (3)
    #define Echo_Links_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Echo_Links_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Echo_Links_SetDriveMode() function.
         *  @{
         */
        #define Echo_Links_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Echo_Links_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Echo_Links_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Echo_Links_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Echo_Links_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Echo_Links_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Echo_Links_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Echo_Links_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Echo_Links_MASK               Echo_Links__MASK
#define Echo_Links_SHIFT              Echo_Links__SHIFT
#define Echo_Links_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Echo_Links_SetInterruptMode() function.
     *  @{
     */
        #define Echo_Links_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Echo_Links_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Echo_Links_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Echo_Links_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Echo_Links__SIO)
    #define Echo_Links_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Echo_Links__PC) && (CY_PSOC4_4200L)
    #define Echo_Links_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Echo_Links_USBIO_DISABLE              ((uint32)(~Echo_Links_USBIO_ENABLE))
    #define Echo_Links_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Echo_Links_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Echo_Links_USBIO_ENTER_SLEEP          ((uint32)((1u << Echo_Links_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Echo_Links_USBIO_SUSPEND_DEL_SHIFT)))
    #define Echo_Links_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Echo_Links_USBIO_SUSPEND_SHIFT)))
    #define Echo_Links_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Echo_Links_USBIO_SUSPEND_DEL_SHIFT)))
    #define Echo_Links_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Echo_Links__PC)
    /* Port Configuration */
    #define Echo_Links_PC                 (* (reg32 *) Echo_Links__PC)
#endif
/* Pin State */
#define Echo_Links_PS                     (* (reg32 *) Echo_Links__PS)
/* Data Register */
#define Echo_Links_DR                     (* (reg32 *) Echo_Links__DR)
/* Input Buffer Disable Override */
#define Echo_Links_INP_DIS                (* (reg32 *) Echo_Links__PC2)

/* Interrupt configuration Registers */
#define Echo_Links_INTCFG                 (* (reg32 *) Echo_Links__INTCFG)
#define Echo_Links_INTSTAT                (* (reg32 *) Echo_Links__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Echo_Links_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Echo_Links__SIO)
    #define Echo_Links_SIO_REG            (* (reg32 *) Echo_Links__SIO)
#endif /* (Echo_Links__SIO_CFG) */

/* USBIO registers */
#if !defined(Echo_Links__PC) && (CY_PSOC4_4200L)
    #define Echo_Links_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Echo_Links_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Echo_Links_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Echo_Links_DRIVE_MODE_SHIFT       (0x00u)
#define Echo_Links_DRIVE_MODE_MASK        (0x07u << Echo_Links_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Echo_Links_H */


/* [] END OF FILE */
