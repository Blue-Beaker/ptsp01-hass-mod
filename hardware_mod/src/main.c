
#include "stc8g_sdcc.h"
#include "stdlib.h"
#define FOSC 11059200UL
#define BRT  65536 - (FOSC / 115200 / 4)

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;
void sleep(uint16_t i)
{
    while (i > 0) {
        i--;
    }
}
void sleep_2(uint16_t i)
{
    while (i > 0) {
        i--;
        sleep(11059);
    }
}
__bit busy;
char wptr;
char rptr;
//char buffer[16];
char target[57] = "Press the [f] key and hit [enter] to enter failsafe mode";
void UartIsr() __interrupt(4)
{
    if (TI) {
        TI   = 0;
        busy = 0;
    }
    if (RI) {
        RI             = 0;
        if(SBUF==target[wptr]){
            wptr++;
        }else{
            wptr=0;
        }
    }
}
void UartInit()
{
    SCON = 0x50;
    TMOD = 0x00;
    TL1  = BRT & 0xff;
    TH1  = BRT >> 8;
    TR1  = 1;
    AUXR = 0x40;
    wptr = 0x00;
    rptr = 0x00;
    busy = 0;
}
void UartSend(char dat)
{
    while (busy);
    busy = 1;
    SBUF = dat;
}
void UartSendStr(char *p)
{
    while (*p) {
        UartSend(*p++);
    }
}
void main()
{
    P3M0 = 0x00;
    P3M1 = 0x00;
    P5M0 = 0x00;
    P5M1 = 0x00;
    UartInit();
    ES = 1;
    EA = 1;
    P55=0;
    while (1) {
        if (wptr>=56){
            wptr=0;
            UartSendStr("f\r/etc/init.d/rcS S boot\r");
            P55=!P55;
        }
    }
}
