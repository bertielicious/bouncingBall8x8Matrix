/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 12 October 2020, 10:19
 */

#include "config.h"
#include "configPorts.h"
#include "configOsc.h"
#include "configSPI.h"
#include "init1_max7219.h"
#include "init2Max7219.h"
#include "configUsart.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
#include "NumToColVal.h"
#include "clearScreen.h"
#include "splashScreen.h"
#include "showPuck.h"
#include <xc.h>
#include <stdio.h>

void main(void) 
{
    
    uchar x, y, xSpeed, ySpeed = 1;
    
    configPorts();
    configOsc();
    configSPI();
    init1_max7219();
    init2Max7219();
    configUsart();
    
  
    splashScreen();
    __delay_ms(2000);
    clearScreen();
  
   
    
    board.width = 16;
    board.height = 8;
   // x = board.width/2;      // starting x = 8, y = 128 location of puck
   // y = board.height/2;
   // y = 6;
  
    while(1)
    {
         if(x >= board.width)
            {
                xSpeed = -1;
            }
            else if(x <=1)
            {
                xSpeed = 1;
            }
            x = x + xSpeed;       // horizontal ball bouncing
            
            //__delay_ms(100);
            
            if(y > board.height)
            {
                ySpeed = -1;
            }
            
            if (y <= 1)
            {
                ySpeed = 1;
            }
            y = y + ySpeed;       // vertical ball bouncing
            showPuck(x,y,x);
            
            __delay_ms(25);
            printf("x %d xSpeed %d  y %d   ySpeed %d\n", x,y, xSpeed, ySpeed);
            clearScreen();
    }
       
        
        
    
}    