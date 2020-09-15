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

uint8 value;
uint8 value2;
uint8 value3;

uint8 a_links;
uint8 a_midden;
uint8 a_rechts;

char afstand_rechts[1];
char afstand_midden[1];
char afstand_links[1];

uint8 deviceConnected = 0; 
uint8 restartAdvertisement = 0 ; 
uint8 busyStatus = 0; 
uint8 number = 7; 
uint8 started = 0; 
uint8 whatToDo; 

