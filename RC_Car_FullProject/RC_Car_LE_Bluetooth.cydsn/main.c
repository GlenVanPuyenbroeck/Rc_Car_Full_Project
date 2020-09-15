#include "project.h"  
#include <stdio.h>  
#include <stdlib.h>
#include "BLE.c"

void getDistance();
void switchToString();
void print();
void MaxAndMin();

char afstand_rechts[1];
char afstand_midden[1];
char afstand_links[1];

uint8 value = 0;
uint8 value2 = 0;
uint8 value3 = 0;

 
void StackEventHandler( uint32 eventCode, void *eventParam );

int main(void)  
{   
    CyGlobalIntEnable; /* Enable global interrupts. */  
    
    UART_Start();  
    PWM_Start(); 

    UltraSoon_Links_Start();
    UltraSoon_Midden_Start();
    UltraSoon_Rechts_Start();
    
    CyBle_Start( StackEventHandler );
    
    for(;;)
    {
        getDistance();
        switchToString();
        print();    
        CyBle_ProcessEvents();
        //CyDelay(500);  
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
        
        UART_UartPutCRLF(0u);
}

void switchToString()
{
        itoa(a_rechts,afstand_rechts,10);
        itoa(a_midden,afstand_midden,10); 
        itoa(a_links, afstand_links,10);
}

void getDistance()
{
        a_links  = UltraSoon_Links_ReadCompare(); 
        a_midden = UltraSoon_Midden_ReadCompare();  
        a_rechts = UltraSoon_Rechts_ReadCompare();
        MaxAndMin();
}

void MaxAndMin()
{
        if( a_links >= 255 || a_midden >= 255 || a_rechts >= 255)
        {
            a_links = 255;
            a_midden = 255;
            a_rechts = 255;
        }
        
        if( a_links <= 1 || a_midden <= 1 || a_rechts <= 1)
        {
            a_links  = 0;
            a_midden = 0;
            a_rechts = 0;
        }
}

