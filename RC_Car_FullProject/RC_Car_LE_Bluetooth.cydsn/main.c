#include "project.h"  
#include <stdio.h>  
#include <stdlib.h>
#include "BLE.c"

void getDistance();
void decide( uint8 var1, uint8 var2 , uint8 var3);
void print();
void switchToString();
void testLEDleft();
void testLEDright();


enum APP{DISTANCE , DECIDE ,TESTLEDLEFT , TESTLEDRIGHT, TOSTRING , PRINT , BLE};
enum Control{ NOTHING ,FORWARD, SLOW_DOWN , TOLEFT, TORIGHT, STOP}; 
enum motorStopControl{SHUTDOWN, SHUTDOWN_RIGHT , SHUTDOWN_LEFT};

enum APP PROGRAM = DISTANCE;
enum Control GO;
enum motorStopControl DANGER;

void StackEventHandler( uint32 eventCode, void *eventParam );

int main(void)  
{   
    CyGlobalIntEnable; /* Enable global interrupts. */  
    
    UART_Start();  
    PWM_Start(); 

    UltraSoon_Links_Start();
    UltraSoon_Midden_Start();
    UltraSoon_Rechts_Start();
    
    Motor_Links_Start();
    Motor_Rechts_Start();
    
    Motor_Links_WritePeriod(periodMotorL);
    Motor_Rechts_WritePeriod(periodMotorR);
   
    CyBle_Start( StackEventHandler );
    
    for(;;)
    {
        /*Can also be set in a enum with a case statement*/
        
        getDistance();
        switchToString(); 
        decide(a_links, a_midden , a_rechts);
        print(); 
        testLEDleft();
        testLEDright();
        
        CyBle_ProcessEvents();
        
     
        if(restartAdvertisement)
        {
            restartAdvertisement = 0; 
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
        }
    }        
}  


void getDistance()
{
        a_links  = UltraSoon_Links_ReadCompare(); 
        a_midden = UltraSoon_Midden_ReadCompare();  
        a_rechts = UltraSoon_Rechts_ReadCompare();
}

/*
* Function getDistance
* Get the distance of the ultrasonic range sensors and it is put in variabels
* parameters =  a_links = left sensor , a_midden = middle sensor , a_rechts = right sensor
* return = void
*/

void switchToString()
{
        itoa(a_rechts,afstand_rechts,10);
        itoa(a_midden,afstand_midden,10); 
        itoa(a_links, afstand_links,10);
        
        itoa(Motor_Links_ReadPeriod() ,motor_rechts,10);
        itoa(Motor_Rechts_ReadPeriod(),motor_links,10);  
}

/*
* Function switchToString
* The variables of the getDistancefuction are now switch into a string for printing use in putty
* This also for the period of the motors
* parameters = multiple char arrays[1]
* return = void 
*/

void decide( uint8 links, uint8 midden , uint8 rechts)
{
    
        if( links <= 15 && midden <= 15 && rechts <= 15)
            {
                GO = STOP;
                DANGER = SHUTDOWN;
            }
            
                 else if( links <= 15 &&  midden > 30  && rechts > 30)
                 {
                    GO = STOP;
                    DANGER = SHUTDOWN_RIGHT;
                 }
                
                
                 else if( links > 30 &&  midden > 30 && rechts <= 15)
                 {
                    GO = STOP;
                    DANGER = SHUTDOWN_LEFT;
                 }
                
                    
                 else if( links <= 30 && midden <= 30 && rechts <= 30)
                 {
                    GO = SLOW_DOWN;                
                 }
                
                 else if( links <= 30 && midden > 30  &&  rechts > 30)
                 {
                    GO = TORIGHT; 
                 }
                
                 else if( links > 30  &&  midden > 30 && rechts <= 30)
                 {
                    GO = TOLEFT;
                 }            
       
                     else
                     {
                        GO = FORWARD;
                     }
    
                 
    
    switch(GO)
    {      
        case NOTHING: ; break;
        
 
       
        case FORWARD: // safe zone , no collision can occur
        
    
        if(start_flag == 1) // start bluetooth command recieved 
        {
                if(control_flag == 0) // if bluetooth command not active
                {
                     
                        if(periodMotorL < 255 && periodMotorR < 255)
                        {
                            periodMotorL += 1;
                            periodMotorR += 1;
                            Motor_Links_WritePeriod(periodMotorL);
                            Motor_Rechts_WritePeriod(periodMotorR);                   
                        } 
                                            
                             else if(periodMotorL < 255 && periodMotorR == 255)
                             {
                                periodMotorL += 1;
                                Motor_Links_WritePeriod(periodMotorL);                
                             } 
                                            
                              else if(periodMotorL == 255 && periodMotorR < 255)
                              {
                                periodMotorR += 1;
                                Motor_Rechts_WritePeriod(periodMotorR);                   
                              }  
                            
                              else
                              {
                                Motor_Links_WritePeriod(periodMotorL);
                                Motor_Rechts_WritePeriod(periodMotorR);  
                              }
                }
         }
        
            else
            {
                
                  if(periodMotorL > 0 && periodMotorR > 0)
                        {
                        periodMotorL -= 1;
                        periodMotorR -= 1;
                        Motor_Links_WritePeriod(periodMotorL);
                        Motor_Rechts_WritePeriod(periodMotorR); 
                        }
                        
                            else if(periodMotorL <= 3)
                            {
                                periodMotorL = 0;
                                Motor_Links_WritePeriod(periodMotorL);
                            }
                        
                            else if(periodMotorR <= 3)
                            {
                                periodMotorR = 0;
                                Motor_Links_WritePeriod(periodMotorL);
                            }
                            
                                  else 
                                  {
                                    periodMotorL = 0;
                                    periodMotorR = 0;
                                    Motor_Links_WritePeriod(periodMotorL);
                                    Motor_Rechts_WritePeriod(periodMotorR); 
                                
                                  }
                                    
            }
         
                            
                             
                    
        break;
                   
        case SLOW_DOWN:  
             
                    if(periodMotorL > 0 && periodMotorR > 0)
                        {
                        periodMotorL -= 1;
                        periodMotorR -= 1;
                        Motor_Links_WritePeriod(periodMotorL);
                        Motor_Rechts_WritePeriod(periodMotorR); 
                        }
                        
                        else
                        {
                         Motor_Links_WritePeriod(periodMotorL); 
                        }
        break;
                        
                        
                         
        case TOLEFT:  
                        
                    if(periodMotorL > 0 && periodMotorR == 255)
                       {                
                        periodMotorL -= 1;
                        Motor_Links_WritePeriod(periodMotorL);    
                       } 
                    
                       else if(periodMotorL > 0 && periodMotorR > 0)
                       {                
                        periodMotorL -= 1;
                        periodMotorR += 1;
                        Motor_Links_WritePeriod(periodMotorL); 
                        Motor_Rechts_WritePeriod(periodMotorR);                        
                       }
                    
                        else
                        {
                         Motor_Links_WritePeriod(periodMotorL); 
                        }
        break;  
                    
        case TORIGHT:
              
                        
                    if(periodMotorR > 0 && periodMotorL == 255)
                       {                
                        periodMotorR -= 1;
                        Motor_Rechts_WritePeriod(periodMotorR); 
                       }
                    
                        else if(periodMotorR > 0 && periodMotorL > 0)
                       {                
                        periodMotorR -= 1;
                        periodMotorL += 1;
                        Motor_Rechts_WritePeriod(periodMotorR); 
                        Motor_Links_WritePeriod(periodMotorL); 
                       }
                    
                            else
                            {
                             Motor_Rechts_WritePeriod(periodMotorR); 
                            }
        break;
                    
        case STOP:   
                            
                    if(DANGER == SHUTDOWN)
                    {
                        periodMotorL = 0;
                        periodMotorR = 0;                    
                        Motor_Links_WritePeriod(periodMotorL);
                        Motor_Rechts_WritePeriod(periodMotorR);  
                    }
                        else if(DANGER == SHUTDOWN_LEFT)
                        {
                            periodMotorR = 0; 
                            Motor_Links_WritePeriod(periodMotorL);
                            Motor_Rechts_WritePeriod(periodMotorR);                          
                        }
                        
                        else if(DANGER == SHUTDOWN_RIGHT)
                        {
                            periodMotorL = 0;                    
                            Motor_Rechts_WritePeriod(periodMotorL);
                            Motor_Rechts_WritePeriod(periodMotorR); 
                        }
        break;            
    }  	
}

/*
* Function decide( uint8 links, uint8 midden , uint8 rechts)
* basic AI algoritme function = it decides what the motors should do if the distance variates of the ultrasonic range sensors
* parameters = captured distances of the ultrasonic range sensors  (links , midden , rechts)
* return = void 
*/

void print()
{
        UART_UartPutString(" Afstand links = "); 
        UART_UartPutString(afstand_links);
        UART_UartPutString(" cm ");  
        
        UART_UartPutChar('\t');
        
        UART_UartPutString(" Afstand midden = "); 
        UART_UartPutString(afstand_midden);
        UART_UartPutString(" cm ");  
        
        UART_UartPutChar('\t');
        
        UART_UartPutString(" Afstand rechts = "); 
        UART_UartPutString(afstand_rechts);
        UART_UartPutString(" cm ");   
        
        UART_UartPutChar('\t');
        
        UART_UartPutString(" Period Motor rechts = "); 
        UART_UartPutString(motor_rechts);
       
        UART_UartPutChar('\t');
        
        UART_UartPutString(" Period Motor links = "); 
        UART_UartPutString(motor_links);
        
        UART_UartPutCRLF(0u);
        UART_UartPutCRLF(0u);
        
        CyDelay(500);
}

/*
* Function print()
* print distance in UART
* parameters = char strings to print (afstand_links , afstand_midden , afstand_rechts , motor_rechts , motor_links) 
* return = void 
*/

void testLEDleft()
{
    if (periodMotorL <= 5 && periodMotorL >= 0)
    {
        T_Motor_R_Groen_Write(0);
        T_Motor_R_Geel_Write(0);
        T_Motor_R_Rood_Write(1);   
    }
        else if(periodMotorL <= 20 && periodMotorL >= 5)
        {
             T_Motor_R_Groen_Write(0);
             T_Motor_R_Geel_Write(1);
             T_Motor_R_Rood_Write(0);   
        }
        
            else
            {
                T_Motor_R_Groen_Write(1);
                T_Motor_R_Geel_Write(0);
                T_Motor_R_Rood_Write(0);  
            }
}

/*
* Function testLEDleft
* For visual testing , if period varies of the left motor different lights are lit
* parameters = periodMotorL
* return = void 
*/

void testLEDright()
{
    if (periodMotorR <= 5 && periodMotorR >= 0)
    {
         T_Motor_L_Groen_Write(0);
         T_Motor_L_Geel_Write(0);
         T_Motor_L_Rood_Write(1);    
    }
        else if(periodMotorR <= 20 && periodMotorR > 5)
        {
             T_Motor_L_Groen_Write(0);
             T_Motor_L_Geel_Write(1);
             T_Motor_L_Rood_Write(0);
        }        
            else
            {
                T_Motor_L_Groen_Write(1);
                T_Motor_L_Geel_Write(0);
                T_Motor_L_Rood_Write(0);
            }    
}

/*
* Function testLEDright
* For visual testing , if period varies of the right motor different lights are lit
* parameters = periodMotorR
* return = void 
*/



