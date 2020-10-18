#include "project.h"  
#include <stdio.h>  
#include <stdlib.h>
#include "BLE.c"
#include "Control.c"

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
    
   // Motor_Links_Start();
   // Motor_Rechts_Start();
   
    CyBle_Start( StackEventHandler );
    
    for(;;)
    {
        getDistance();
        switchToString();
        print();    
        CyBle_ProcessEvents();
        CyDelay(500); 
        
        
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
        
        DeviceControl( a_links, a_midden , a_rechts);
       
}

void DeviceControl( uint8 links , uint8 midden , uint8 rechts)
{
  
    if(midden >= 45)
            {                    
                   if(periodMotorL < 255 && periodMotorR < 255)
                    {
                      periodMotorL += 15;
                      periodMotorR += 15;
                      Motor_Links_WritePeriod(periodMotorL);
                      Motor_Rechts_WritePeriod(periodMotorR);                   
                    }  
                     else
                      {      
                     Motor_Links_WritePeriod(periodMotorL);
                     Motor_Rechts_WritePeriod(periodMotorR);   
                      }
                
            } 
        
    else if(midden <= 45)
            {
                  periodMotorL -= 15;
                  periodMotorR -= 15;
                  Motor_Links_WritePeriod(periodMotorL);
                  Motor_Rechts_WritePeriod(periodMotorR);
                  
            }
        
    if(midden <= 15)
                 {
                 Motor_Links_WritePeriod(0);
                 Motor_Rechts_WritePeriod(0);                     
                 }
}






