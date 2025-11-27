#include <reg51.h>
#include "uart.h"

#define LM35 P1

void delay(unsigned int ms){
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void main() {
    unsigned int temp;

    UART_Init();

    while(1) {
        temp = LM35;
        UART_Tx((temp / 2) + 30);
        delay(500);
    }
}
