#include "project.h"  
#include <stdio.h>  
#include <stdlib.h>
#include "BLE.c"


void getDistance();
void switchToString();
void print();
void MaxAndMin();
void Move(uint8);

void testLEDleft();
void testLEDright();


void getDistance();
void switchToString();
void print();
void MaxAndMin();


 
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
        getDistance();
        decide(a_links, a_midden , a_rechts);
        print();
        switchToString();  
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

void switchToString()
{
        itoa(a_rechts,afstand_rechts,10);
        itoa(a_midden,afstand_midden,10); 
        itoa(a_links, afstand_links,10);
        
        itoa(Motor_Links_ReadPeriod() ,motor_rechts,10);
        itoa(Motor_Rechts_ReadPeriod(),motor_links,10);  
}

void getDistance()
{
        a_links  = UltraSoon_Links_ReadCompare(); 
        a_midden = UltraSoon_Midden_ReadCompare();  
        a_rechts = UltraSoon_Rechts_ReadCompare();
}

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
        
 
       
        case FORWARD: 
        
    
        if(start_flag == 1)
        {
                if(control_flag == 0)
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


