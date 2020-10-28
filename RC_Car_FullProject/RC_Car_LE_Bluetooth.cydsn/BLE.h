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
void decide( uint8 var1, uint8 var2 , uint8 var3);

enum APP{DISTANCE , DECIDE ,TESTLEDLEFT , TESTLEDRIGHT, TOSTRING , PRINT , BLE};
enum Control{ NOTHING ,FORWARD, SLOW_DOWN , TOLEFT, TORIGHT, STOP}; 
enum motorStopControl{SHUTDOWN, SHUTDOWN_RIGHT , SHUTDOWN_LEFT};
enum remote{RECIEVED , NOTRECIEVED};

enum APP PROGRAM = DISTANCE;
enum Control GO;
enum motorStopControl DANGER;
enum remote BLUETOOTH;

uint8 periodMotorL = 0;
uint8 periodMotorR = 0; 

uint8 start_flag = 0;
uint8 control_flag = 0;
uint8 control_to_zero = 0;
    

static uint8 var1 = 0;
static uint8 var2 = 0;
static uint8 var3 = 0;

static uint8 value = 0;
static uint8 value2 = 0;
static uint8 value3 = 0;
static uint8 value4 = 0;

uint8 a_links = 0;
uint8 a_midden = 0;
uint8 a_rechts = 0;

static uint8 M_Links = 0;
static uint8 M_Rechts = 0;

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

