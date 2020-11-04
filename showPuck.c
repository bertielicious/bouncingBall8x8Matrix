#include "config.h"
#include "sendNoSPIbyte.h"
#include "sendSPIbyte.h"
#include "NumToColVal.h"
void showPuck(uchar x, uchar y, uchar matrix)
{
    if(matrix >0 && matrix <9)
    {
        y = NumToColVal(y); // write to left hand matrix
        CS = LO;
        sendNoSPIbyte();
        sendSPIbyte(x,y);
        CS = HI;  
    }
    else if(matrix >8 && matrix <17) // write to right hand matrix
    {
        y = NumToColVal(y);
        CS = LO;
        sendSPIbyte(x-8,y);
        sendNoSPIbyte();
        CS = HI;  
    }
  
}
