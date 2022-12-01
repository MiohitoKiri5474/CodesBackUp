#include <xc.h>
#include <pic18f4520.h>
//#include<unistd.h>
#include<stdio.h>

#pragma config OSC = INTIO67    // Oscillator Selection bits
#pragma config WDT = OFF        // Watchdog Timer Enable bit 
#pragma config PWRT = OFF       // Power-up Enable bit
#pragma config BOREN = ON       // Brown-out Reset Enable bit
#pragma config PBADEN = OFF     // Watchdog Timer Enable bit 
#pragma config LVP = OFF        // Low Voltage (single -supply) In-Circute Serial Pragramming Enable bit
#pragma config CPD = OFF        // Data EEPROM?Memory Code Protection bit (Data EEPROM code protection off)

void main(void) {
    // Timer2 -> On, prescaler -> 4
    T2CONbits.TMR2ON = 0b1;
    T2CONbits.T2CKPS = 0b01;

    // Internal Oscillator Frequency, Fosc = 125 kHz, Tosc = 8 µs
    OSCCONbits.IRCF = 0b001;

    // PWM mode, P1A, P1C active-high; P1B, P1D active-high
    CCP1CONbits.CCP1M = 0b1100;

    // CCP1/RC2 -> Output
    TRISC = 0;
    LATC = 0;

    TRISB=1;
    PORTB=0;

    // Set up PR2, CCP to decide PWM period and Duty Cycle
    /**
     * PWM period
     * = (PR2 + 1) * 4 * Tosc * (TMR2 prescaler)
     * = (0x9b + 1) * 4 * 8µs * 4
     * = 0.019968s ~= 20ms
     */
    PR2 = 0x9b;

    /**
     * Duty cycle
     * = (CCPR1L:CCP1CON<5:4>) * Tosc * (TMR2 prescaler)
     * = (0x0b*4 + 0b01) * 8µs * 4
     * = 0.00144s ~= 1450µs
     */
    //0b 0
    int delay=1500;
    //int delay2=1700;
    int delay3=75;
    while(1) {
        delay=1500;
        // delay2=1700;
        if(!PORTB) {
            while(CCPR1L<0X18) {
                delay3=75;
                CCP1CONbits.DC1B ++;
                if(CCP1CONbits.DC1B==3) {
                    CCP1CONbits.DC1B=0;
                    CCPR1L++;
                }
                while(delay3--);
            }

            //while(delay2--);
            CCPR1L = 0x03;
            CCP1CONbits.DC1B = 0b11;
            while(delay--);
        }


    }


    return;
}
