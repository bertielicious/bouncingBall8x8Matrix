#include "config.h"
#include "sendSPIbyte.h"
void init1_max7219(void)
{
 CS = 0;
 sendSPIbyte (decodeModeAddr,noDecodeDigits0to7);//leave shutdown mode and enter normal operation
 CS = 1;    // load last 16 bits on rising edge

 CS = 0;
 sendSPIbyte (displayIntensityAddr,displayIntensityData);// minimum display intensity 1/32
 CS = 1;

 CS = 0;
 sendSPIbyte (scanLimitAddr,scanLimitData); // decode mode off
 CS = 1;

 CS = 0;
sendSPIbyte (shutdownModeAddr,shutdownNormalOperationData); // scan limit = 8 digits multiplexed
 CS = 1; // LOAD is high


}
