/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/* [] END OF FILE */
#include "project.h"  
#include <stdio.h>  
#include <stdlib.h>
#include "BLE.h"


void StackEventHandler( uint32 eventCode, void *eventParam )
{
    CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;
 
    updateCharacteristic();
    
    switch( eventCode )
    {

        case CYBLE_EVT_STACK_ON:
            restartAdvertisement = 1;       
        break;

        case CYBLE_EVT_TIMEOUT:
        break;

        case CYBLE_EVT_GAP_DEVICE_CONNECTED:
        
        break;

        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:            
            restartAdvertisement = 1; 
        
            break;

        /* GAP Peripheral events */

        case CYBLE_EVT_GAPP_ADVERTISEMENT_START_STOP:
            if(CyBle_GetState() == CYBLE_STATE_DISCONNECTED)
            {
                restartAdvertisement = 0;
            }
            break;

        /* GATT events */

        case CYBLE_EVT_GATT_CONNECT_IND:
            connectionHandle = *(CYBLE_CONN_HANDLE_T*)eventParam;
            deviceConnected = 1; 
            
            break;

        case CYBLE_EVT_GATT_DISCONNECT_IND:
            deviceConnected = 0;            
            break;
            
        case CYBLE_EVT_GATTS_WRITE_REQ:				
			/*When this event is triggered, the peripheral has received 
			* a write command on the custom characteristic */
			
			/* Extract the write value from the event parameter */
             wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
           // wrLinks = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
            
            if( CYBLE_MOTOREN_MOTOR_LINKS_CHAR_HANDLE  == wrReqParam->handleValPair.attrHandle)
            {  
                M_Links = wrReqParam->handleValPair.value.val[0]; 
                Motor_Links_WritePeriod(M_Links);
            
                /* Set flag so that application can start sending notifications.*/
               /* started = 1; */
			}      
			
			/* Check if the returned handle is matching to Random Data Client custom configuration*/
            if( CYBLE_MOTOREN_MOTOR_RECHTS_CHAR_HANDLE  == wrReqParam->handleValPair.attrHandle)
            {  
                M_Rechts = wrReqParam->handleValPair.value.val[0];  
                Motor_Rechts_WritePeriod(M_Rechts);
                /* Set flag so that application can start sending notifications.*/
               /* started = 1; */
			}
        
           
            CyBle_GattsWriteRsp(connectionHandle);
            break; 

        /* default catch-all case */
        case CYBLE_EVT_STACK_BUSY_STATUS:
            busyStatus = *(uint8*) eventParam;
            
        default:
        break;
    }
  }

void updateCharacteristic()
{
   
    value = a_links;
    value2 =a_midden;
    value3 =a_rechts;
    
    CYBLE_GATT_HANDLE_VALUE_PAIR_T Sensor_links; 
    CYBLE_GATT_HANDLE_VALUE_PAIR_T Sensor_midden; 
    CYBLE_GATT_HANDLE_VALUE_PAIR_T Sensor_rechts; 

    Sensor_links.attrHandle = CYBLE_SENSOREN_SENSOR_LINKS_CHAR_HANDLE;
    Sensor_links.value.val = (uint8*)&value;
    Sensor_links.value.len = 1; 
    
    Sensor_midden.attrHandle = CYBLE_SENSOREN_SENSOR_MIDDEN_CHAR_HANDLE;
    Sensor_midden.value.val = (uint8*)&value2;
    Sensor_midden.value.len = 1; 
    
    Sensor_rechts.attrHandle = CYBLE_SENSOREN_SENSOR_RECHTS_CHAR_HANDLE;
    Sensor_rechts.value.val = (uint8*)&value3;
    Sensor_rechts.value.len = 1;    
    
    CyBle_GattsWriteAttributeValue(&Sensor_links,0, &connectionHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
    CyBle_GattsWriteAttributeValue(&Sensor_midden,0, &connectionHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
    CyBle_GattsWriteAttributeValue(&Sensor_rechts,0, &connectionHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
    
    
    //CyBle_GattsReadAttributeValue(&CCCDHandle, &connectionHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);

}

/* [] END OF FILE */
