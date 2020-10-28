/***************************************************************************//**
* \file CYBLE_custom.h
* \version 3.66
* 
* \brief
*  Contains the function prototypes and constants for the Custom Service.
* 
********************************************************************************
* \copyright
* Copyright 2014-2020, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_BLE_CYBLE_CUSTOM_H)
#define CY_BLE_CYBLE_CUSTOM_H

#include "BLE_gatt.h"


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Maximum supported Custom Services */
#define CYBLE_CUSTOMS_SERVICE_COUNT                  (0x03u)
#define CYBLE_CUSTOMC_SERVICE_COUNT                  (0x00u)
#define CYBLE_CUSTOM_SERVICE_CHAR_COUNT              (0x03u)
#define CYBLE_CUSTOM_SERVICE_CHAR_DESCRIPTORS_COUNT  (0x01u)

/* Below are the indexes and handles of the defined Custom Services and their characteristics */
#define CYBLE_SENSOREN_SERVICE_INDEX   (0x00u) /* Index of Sensoren service in the cyBle_customs array */
#define CYBLE_SENSOREN_SENSOR_LINKS_CHAR_INDEX   (0x00u) /* Index of Sensor Links characteristic */
#define CYBLE_SENSOREN_SENSOR_LINKS_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */
#define CYBLE_SENSOREN_SENSOR_MIDDEN_CHAR_INDEX   (0x01u) /* Index of Sensor Midden characteristic */
#define CYBLE_SENSOREN_SENSOR_MIDDEN_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */
#define CYBLE_SENSOREN_SENSOR_RECHTS_CHAR_INDEX   (0x02u) /* Index of Sensor Rechts characteristic */
#define CYBLE_SENSOREN_SENSOR_RECHTS_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */

#define CYBLE_MOTOREN_SERVICE_INDEX   (0x01u) /* Index of Motoren service in the cyBle_customs array */
#define CYBLE_MOTOREN_MOTOR_LINKS_CHAR_INDEX   (0x00u) /* Index of Motor Links characteristic */
#define CYBLE_MOTOREN_MOTOR_LINKS_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */
#define CYBLE_MOTOREN_MOTOR_RECHTS_CHAR_INDEX   (0x01u) /* Index of Motor Rechts characteristic */
#define CYBLE_MOTOREN_MOTOR_RECHTS_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */

#define CYBLE_START_AND_CONTROL_SERVICE_INDEX   (0x02u) /* Index of Start_And_Control service in the cyBle_customs array */
#define CYBLE_START_AND_CONTROL_START_CHAR_INDEX   (0x00u) /* Index of Start characteristic */
#define CYBLE_START_AND_CONTROL_START_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */
#define CYBLE_START_AND_CONTROL_CONTROL_FLAG_CHAR_INDEX   (0x01u) /* Index of Control_Flag characteristic */
#define CYBLE_START_AND_CONTROL_CONTROL_FLAG_CUSTOM_DESCRIPTOR_DESC_INDEX   (0x00u) /* Index of Custom Descriptor descriptor */


#define CYBLE_SENSOREN_SERVICE_HANDLE   (0x000Cu) /* Handle of Sensoren service */
#define CYBLE_SENSOREN_SENSOR_LINKS_DECL_HANDLE   (0x000Du) /* Handle of Sensor Links characteristic declaration */
#define CYBLE_SENSOREN_SENSOR_LINKS_CHAR_HANDLE   (0x000Eu) /* Handle of Sensor Links characteristic */
#define CYBLE_SENSOREN_SENSOR_LINKS_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x000Fu) /* Handle of Custom Descriptor descriptor */
#define CYBLE_SENSOREN_SENSOR_MIDDEN_DECL_HANDLE   (0x0010u) /* Handle of Sensor Midden characteristic declaration */
#define CYBLE_SENSOREN_SENSOR_MIDDEN_CHAR_HANDLE   (0x0011u) /* Handle of Sensor Midden characteristic */
#define CYBLE_SENSOREN_SENSOR_MIDDEN_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x0012u) /* Handle of Custom Descriptor descriptor */
#define CYBLE_SENSOREN_SENSOR_RECHTS_DECL_HANDLE   (0x0013u) /* Handle of Sensor Rechts characteristic declaration */
#define CYBLE_SENSOREN_SENSOR_RECHTS_CHAR_HANDLE   (0x0014u) /* Handle of Sensor Rechts characteristic */
#define CYBLE_SENSOREN_SENSOR_RECHTS_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x0015u) /* Handle of Custom Descriptor descriptor */

#define CYBLE_MOTOREN_SERVICE_HANDLE   (0x0016u) /* Handle of Motoren service */
#define CYBLE_MOTOREN_MOTOR_LINKS_DECL_HANDLE   (0x0017u) /* Handle of Motor Links characteristic declaration */
#define CYBLE_MOTOREN_MOTOR_LINKS_CHAR_HANDLE   (0x0018u) /* Handle of Motor Links characteristic */
#define CYBLE_MOTOREN_MOTOR_LINKS_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x0019u) /* Handle of Custom Descriptor descriptor */
#define CYBLE_MOTOREN_MOTOR_RECHTS_DECL_HANDLE   (0x001Au) /* Handle of Motor Rechts characteristic declaration */
#define CYBLE_MOTOREN_MOTOR_RECHTS_CHAR_HANDLE   (0x001Bu) /* Handle of Motor Rechts characteristic */
#define CYBLE_MOTOREN_MOTOR_RECHTS_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x001Cu) /* Handle of Custom Descriptor descriptor */

#define CYBLE_START_AND_CONTROL_SERVICE_HANDLE   (0x001Du) /* Handle of Start_And_Control service */
#define CYBLE_START_AND_CONTROL_START_DECL_HANDLE   (0x001Eu) /* Handle of Start characteristic declaration */
#define CYBLE_START_AND_CONTROL_START_CHAR_HANDLE   (0x001Fu) /* Handle of Start characteristic */
#define CYBLE_START_AND_CONTROL_START_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x0020u) /* Handle of Custom Descriptor descriptor */
#define CYBLE_START_AND_CONTROL_CONTROL_FLAG_DECL_HANDLE   (0x0021u) /* Handle of Control_Flag characteristic declaration */
#define CYBLE_START_AND_CONTROL_CONTROL_FLAG_CHAR_HANDLE   (0x0022u) /* Handle of Control_Flag characteristic */
#define CYBLE_START_AND_CONTROL_CONTROL_FLAG_CUSTOM_DESCRIPTOR_DESC_HANDLE   (0x0023u) /* Handle of Custom Descriptor descriptor */



#if(CYBLE_CUSTOMS_SERVICE_COUNT != 0u)
    #define CYBLE_CUSTOM_SERVER
#endif /* (CYBLE_CUSTOMS_SERVICE_COUNT != 0u) */
    
#if(CYBLE_CUSTOMC_SERVICE_COUNT != 0u)
    #define CYBLE_CUSTOM_CLIENT
#endif /* (CYBLE_CUSTOMC_SERVICE_COUNT != 0u) */

/***************************************
* Data Struct Definition
***************************************/

/**
 \addtogroup group_service_api_custom
 @{
*/

#ifdef CYBLE_CUSTOM_SERVER

/** Contains information about Custom Characteristic structure */
typedef struct
{
    /** Custom Characteristic handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T customServCharHandle;
    /** Custom Characteristic Descriptors handles */
    CYBLE_GATT_DB_ATTR_HANDLE_T customServCharDesc[     /* MDK doesn't allow array with zero length */
        (CYBLE_CUSTOM_SERVICE_CHAR_DESCRIPTORS_COUNT == 0u) ? 1u : CYBLE_CUSTOM_SERVICE_CHAR_DESCRIPTORS_COUNT];
} CYBLE_CUSTOMS_INFO_T;

/** Structure with Custom Service attribute handles. */
typedef struct
{
    /** Handle of a Custom Service */
    CYBLE_GATT_DB_ATTR_HANDLE_T customServHandle;
    
    /** Information about Custom Characteristics */
    CYBLE_CUSTOMS_INFO_T customServInfo[                /* MDK doesn't allow array with zero length */
        (CYBLE_CUSTOM_SERVICE_CHAR_COUNT == 0u) ? 1u : CYBLE_CUSTOM_SERVICE_CHAR_COUNT];
} CYBLE_CUSTOMS_T;


#endif /* (CYBLE_CUSTOM_SERVER) */

#ifdef CYBLE_CUSTOM_CLIENT

/** Structure with discovered attributes information of Custom Service Descriptors */
typedef struct
{
    /** Custom Descriptor handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T descHandle;
	/** Custom Descriptor 128 bit UUID */
	const void *uuid;           
    /** UUID Format - 16-bit (0x01) or 128-bit (0x02) */
	uint8 uuidFormat;
   
} CYBLE_CUSTOMC_DESC_T;

/** Structure with discovered attributes information of Custom Service Characteristics */
typedef struct
{
    /** Characteristic handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T customServCharHandle;
	/** Characteristic end handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T customServCharEndHandle;
	/** Custom Characteristic UUID */
	const void *uuid;           
    /** UUID Format - 16-bit (0x01) or 128-bit (0x02) */
	uint8 uuidFormat;
    /** Properties for value field */
    uint8  properties;
	/** Number of descriptors */
    uint8 descCount;
    /** Characteristic Descriptors */
    CYBLE_CUSTOMC_DESC_T * customServCharDesc;
} CYBLE_CUSTOMC_CHAR_T;

/** Structure with discovered attributes information of Custom Service */
typedef struct
{
    /** Custom Service handle */
    CYBLE_GATT_DB_ATTR_HANDLE_T customServHandle;
	/** Custom Service UUID */
	const void *uuid;           
    /** UUID Format - 16-bit (0x01) or 128-bit (0x02) */
	uint8 uuidFormat;
	/** Number of characteristics */
    uint8 charCount;
    /** Custom Service Characteristics */
    CYBLE_CUSTOMC_CHAR_T * customServChar;
} CYBLE_CUSTOMC_T;

#endif /* (CYBLE_CUSTOM_CLIENT) */


/***************************************
* External data references 
***************************************/

#ifdef CYBLE_CUSTOM_SERVER

/** Custom Services GATT DB handles structures */
extern const CYBLE_CUSTOMS_T cyBle_customs[CYBLE_CUSTOMS_SERVICE_COUNT];

#endif /* (CYBLE_CUSTOM_SERVER) */

#ifdef CYBLE_CUSTOM_CLIENT

/** Custom Services discovered attributes information */
extern CYBLE_CUSTOMC_T cyBle_customCServ[CYBLE_CUSTOMC_SERVICE_COUNT];

#endif /* (CYBLE_CUSTOM_CLIENT) */

/***************************************
* Private Function Prototypes
***************************************/

/** \cond IGNORE */
void CyBle_CustomInit(void);

#ifdef CYBLE_CUSTOM_CLIENT

void CyBle_CustomcDiscoverServiceEventHandler(const CYBLE_DISC_SRVC128_INFO_T *discServInfo);
void CyBle_CustomcDiscoverCharacteristicsEventHandler(uint16 discoveryService, const CYBLE_DISC_CHAR_INFO_T *discCharInfo);
CYBLE_GATT_ATTR_HANDLE_RANGE_T CyBle_CustomcGetCharRange(uint8 incrementIndex);
void CyBle_CustomcDiscoverCharDescriptorsEventHandler(const CYBLE_DISC_DESCR_INFO_T *discDescrInfo);

#endif /* (CYBLE_CUSTOM_CLIENT) */


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/
#define customServiceCharHandle         customServCharHandle
#define customServiceCharDescriptors    customServCharDesc
#define customServiceHandle             customServHandle
#define customServiceInfo               customServInfo
/** \endcond */

/** @} */

#endif /* CY_BLE_CYBLE_CUSTOM_H  */

/* [] END OF FILE */
