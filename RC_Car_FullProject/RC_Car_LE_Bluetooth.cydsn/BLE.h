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

uint8 periodMotorL = 0;
uint8 periodMotorR = 0; 

uint8 start_flag = 0; 
uint8 control_flag = 0; 
uint8 control_to_zero = 0;

static uint8 value = 0;
static uint8 value2 = 0;
static uint8 value3 = 0;
static uint8 value4 = 0;

uint8 a_links = 0;
uint8 a_midden = 0;
uint8 a_rechts = 0;

char afstand_rechts[1];
char afstand_midden[1];
char afstand_links[1];


/*
* These varaiables are needed in main.c and BLE.c
*/

