/* 
 * File:   config.h
 * Author: Phil Glazzard
 *
 * Created on 12 October 2020, 10:16
 */

#ifndef CONFIG_H
#define	CONFIG_H

// PIC16F1459 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include<stdbool.h>
#define _XTAL_FREQ 16000000
#define DIAGNOSTIC_LED PORTAbits.RA5   // pin 2
#define SCK PORTBbits.RB6   // pin 11
#define SDO PORTCbits.RC7   // pin 9
#define CS PORTCbits.RC6    // pin 8
enum status {LO, HI};
typedef unsigned char uchar;

//**********************MAX7219 CONSTANTS***********************************************
#define noOpAddr 0x00 // No operation address
#define noOpData 0x00 // No operation data

#define row0 0x01     // row 0 address
#define row1 0x02     // row 1 address
#define row2 0x03     // row 2 address
#define row3 0x04     // row 3 address
#define row4 0x05     // row 4 address
#define row5 0x06     // row 5 address
#define row6 0x07     // row 6 address
#define row7 0x08     // row 7 address

#define decodeModeAddr 0x09     //decode mode address
#define noDecodeDigits0to7 0x00 // no 7 seg decode of data

#define displayIntensityAddr 0x0A   // display intensity address
#define displayIntensityData 0x00   // 0x00 to 0x0f for max brightness

#define scanLimitAddr 0x0B      // scan limit address
#define scanLimitData 0x07      // 0x00 = 0 digit only, 0x07 = 7 digits

#define shutdownModeAddr 0x0C   // low power mode
#define shutdownNormalOperationData 0x01    //normal operation ie not shutdown





typedef struct{
    uchar width;
    uchar height;
    uchar scorePlayerA;
    uchar scorePlayerB;
    uchar displayScoreA;
    uchar displayScoreB;
    uchar hiScorename[20];
    uchar hiScoreScore;
   // uchar xSpeed;
   // uchar ySpeed;
    uchar xStart;
    uchar yStart;
    uchar xAccelleration;
    uchar yAccelleration;
    uchar angleOfDeflection;
    uchar startGametune;
    uchar puckStrikespaddleTune;
    uchar puckReboundWallTune;
    uchar playerWinsApointTune;
    uchar gameOverTune;
    uchar highScoreTune;
    uchar newGameTune;
    uchar xMovementboundaryOfPaddles;   
   // uchar gameArea[16][8];
  //  uchar gameBoarder[18][10];
}pong;
pong puck;  // define a variable puck of type pong
pong board;
#endif	/* CONFIG_H */

