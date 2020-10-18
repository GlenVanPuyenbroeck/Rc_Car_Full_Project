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
#include "stdlib.h"
CYBLE_CONN_HANDLE_T connectionHandle; 

void updateCharacteristic();
void DeviceControl( uint8 var1, uint8 var2 , uint8 var3);
//void LED(uint8 , uint8 , uint8 , uint8 , uint8 , uint8 );

static uint8 periodMotorL = 255;
static uint8 periodMotorR = 255; 
    

static uint8 var1 = 0;
static uint8 var2 = 0;
static uint8 var3 = 0;

static uint8 value = 0;
static uint8 value2 = 0;
static uint8 value3 = 0;

static uint8 a_links = 0;
static uint8 a_midden = 0;
static uint8 a_rechts = 0;

static uint8 M_Links = 0;
static uint8 M_Rechts = 0;

static uint8 M_L = 0;
static uint8 M_R = 0; 

char afstand_rechts[1];
char afstand_midden[1];
char afstand_links[1];

char motor_rechts[1];
char motor_links[1];

uint8 deviceConnected = 0; 
uint8 restartAdvertisement = 0 ; 
uint8 busyStatus = 0; 
uint8 number = 7; 
uint8 started = 0; 
uint8 whatToDo = 0; 

