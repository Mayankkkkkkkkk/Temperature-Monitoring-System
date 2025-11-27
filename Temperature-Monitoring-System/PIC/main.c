#include <xc.h>

#define _XTAL_FREQ 8000000
#define LM35 ADC_Read(0)

void UART_Init() {
    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 12;
}

void UART_Write(unsigned char data){
    while(!TXIF);
    TXREG = data;
}

unsigned int ADC_Read(unsigned char ch){
    ADCON0 = (ch << 2) | 0x81;
    __delay_ms(2);
    GO_nDONE = 1;
    while(GO_nDONE);
    return ((ADRESH << 8) + ADRESL);
}

void main(void) {
    ADCON1 = 0x80;
    UART_Init();

    unsigned int raw, temp;

    while(1){
        raw = LM35;
        temp = raw / 2;

        UART_Write(temp);
        __delay_ms(500);
    }
}
