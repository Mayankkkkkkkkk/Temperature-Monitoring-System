#ifndef UART_H
#define UART_H

#include <reg51.h>

void UART_Init() {
    TMOD = 0x20;
    TH1 = 0xFD;
    SCON = 0x50;
    TR1 = 1;
}

void UART_Tx(char data) {
    SBUF = data;
    while(TI == 0);
    TI = 0;
}

#endif
