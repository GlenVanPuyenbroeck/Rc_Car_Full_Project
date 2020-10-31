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

uint8 deviceConnected = 0; 
uint8 restartAdvertisement = 0 ; 
uint8 busyStatus = 0;  
uint8 started = 0; 

char motor_rechts[1];
char motor_links[1];

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
            
        case CYBLE_EVT_GATTS_WRITE_REQ:			// Recieved something with bluetooth	
			
             wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
           
            
            if(CYBLE_MOTOREN_MOTOR_LINKS_CHAR_HANDLE  ==  wrReqParam->handleValPair.attrHandle)
            {     
                periodMotorL = wrReqParam->handleValPair.value.val[0];    
                Motor_Links_WritePeriod(periodMotorL); // for controlling motor speed
            }
            
			
            if( CYBLE_MOTOREN_MOTOR_RECHTS_CHAR_HANDLE  == wrReqParam->handleValPair.attrHandle)
            {  
                periodMotorR = wrReqParam->handleValPair.value.val[0];    
                Motor_Links_WritePeriod(periodMotorR); // for controlling motor speed
			}
            
            if(CYBLE_START_AND_CONTROL_CONTROL_FLAG_CHAR_HANDLE == wrReqParam->handleValPair.attrHandle)
            {
                control_flag = wrReqParam->handleValPair.value.val[0];   // recieving the start command
            }
            
            if(CYBLE_START_AND_CONTROL_START_CHAR_HANDLE == wrReqParam->handleValPair.attrHandle)
            {
                start_flag = wrReqParam->handleValPair.value.val[0];    // recieving the start command
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

/*
*  Function StackEventHandler( uint32 eventCode, void *eventParam )
*  In bluetooth differents events occure in a specific order , in these function it goes over these events one by one
*  parameters = bluetooth variables for restarting and motor control
*  return = void 
*/

void updateCharacteristic()
{
   
    value  = a_links;
    value2 = a_midden;
    value3 = a_rechts;
    value4 = 0;
    
    CYBLE_GATT_HANDLE_VALUE_PAIR_T Sensor_links; 
    CYBLE_GATT_HANDLE_VALUE_PAIR_T Sensor_midden; 
    CYBLE_GATT_HANDLE_VALUE_PAIR_T Sensor_rechts; 
    CYBLE_GATT_HANDLE_VALUE_PAIR_T control;

    Sensor_links.attrHandle = CYBLE_SENSOREN_SENSOR_LINKS_CHAR_HANDLE; 
    Sensor_links.value.val = (uint8*)&value;
    Sensor_links.value.len = 1; 
    
    Sensor_midden.attrHandle = CYBLE_SENSOREN_SENSOR_MIDDEN_CHAR_HANDLE;
    Sensor_midden.value.val = (uint8*)&value2;
    Sensor_midden.value.len = 1; 
    
    Sensor_rechts.attrHandle = CYBLE_SENSOREN_SENSOR_RECHTS_CHAR_HANDLE;
    Sensor_rechts.value.val = (uint8*)&value3;
    Sensor_rechts.value.len = 1;    
    
        if(control_to_zero == 1) // reading control flag for testing purpose
        {
            control.attrHandle = CYBLE_START_AND_CONTROL_CONTROL_FLAG_CHAR_HANDLE;
            control.value.val = (uint8*)&value4;
            control.value.len = 1; 
        }
    
    CyBle_GattsWriteAttributeValue(&Sensor_links,0, &connectionHandle, CYBLE_GATT_DB_LOCALLY_INITIATED); // sending bluetooth variable
    CyBle_GattsWriteAttributeValue(&Sensor_midden,0, &connectionHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
    CyBle_GattsWriteAttributeValue(&Sensor_rechts,0, &connectionHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
    CyBle_GattsWriteAttributeValue(&control,0, &connectionHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
   
}

/*
* Function updateCharacteristic
* These function sends the data of the ultrasonic range sensors plus the control flag for testing purpose
* parameters =  - ultrasonic range sensors variabels and accompanying bluetooth variables 
*               - control variable and accompanying bluetooth variable
* return = void
*/


/* [] END OF FILE */
