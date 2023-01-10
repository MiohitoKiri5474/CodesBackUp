/*
 * File:   main.c
 * Author: lltzpp
 *
 * Created on 2023?1?10?, ?? 1:15
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pic18f4520.h>

#pragma config OSC = INTIO67 // Oscillator Selection bits
#pragma config WDT = OFF     // Watchdog Timer Enable bit 
#pragma config PWRT = OFF    // Power-up Enable bit
#pragma config BOREN = ON   // Brown-out Reset Enable bit
#pragma config PBADEN = OFF     // Watchdog Timer Enable bit 
#pragma config LVP = OFF     // Low Voltage (single -supply) In-Circute Serial Pragramming Enable bit
#pragma config CPD = OFF     // Data EEPROM?Memory Code Protection bit (Data EEPROM code protection off)

#define _XTAL_FREQ 4000000


int enable = 1; // 可變電阻是否有作用
int start = 0;
int times; // 0 ~ 9 min

void display ( int num ) {
	int res;
	switch ( num ) {
		case 0: res = 0b11000000; break;
		case 1: res = 0b11111001; break;
		case 2: res = 0b10100100; break;
		case 3: res = 0b10110000; break;
		case 4: res = 0b10011001; break;
		case 5: res = 0b10010010; break;
		case 6: res = 0b10000010; break;
		case 7: res = 0b11111000; break;
		case 8: res = 0b10000000; break;
		case 9: res = 0b10010000; break;
		default: res = 0b00000000; break;
	}
	// res ^= 0b11111111; // use if need
	LATD = res;
}

void main ( void ) {
    OSCCONbits.IRCF = 0b110; //4MHz
    TRISAbits.RA0 = 1; //analog input
    PORTA = 0;
    
    //set RD0~7 = output
    TRISD = 0;
    LATD = 0;
    
    ADCON1bits.VCFG = 0b00; // VREF+ = VDD VREF- = VSS
    ADCON1bits.PCFG = 0b1110; // AN0(RA0)=A
    ADCON0bits.CHS = 0b0000; // analog input = RA0
    ADCON2bits.ADCS = 0b001; // Fosc = 4MHz, 8*1/4M = 2 mu s，算Tad
    ADCON2bits.ACQT = 0b100; // Tad = 2, AQtime 4tad = 8 > 2.4，幾次一輪迴
    ADCON2bits.ADFM = 1; // 0~1023 = 10 bits, right justified
    ADCON0bits.ADON = 1; // open A/D convert bit
    
    PIE1bits.ADIE = 1; // enable AD convert interrupt
    PIR1bits.ADIF = 0; // AD conversion is not complete at first
    INTCONbits.PEIE = 1; // enable all unmasked periheral interrupts
    INTCONbits.GIE = 1; // enable all unmasked interrupt
    
    //configure ADIP
    IPR1bits.ADIP = 1;
    
    ADCON0bits.GODONE = 1;//do AD in progress
    __delay_us(4);
    // RB0: set time
    // RB1: start or not
    int cnt = 0;
    while(1){
        if ( !PORTBbits.RB0 ) {
            enable ^= 1;
            __delay_us ( 10000 );
        }
        if ( !PORTBbits.RB1 ) {
            start ^= 1;
            if ( !start )
                __delay_us ( 10000 );
        }
        if ( !start ) {
            // running
            __delay_us ( 10000 );
            cnt++;
            if ( cnt == 6000 ) {
                times--, cnt = 0;
				display ( times );
			}
        }
    }
}

/*
 * 0~63 = 0     512~575 = 8
 * 64~127 = 1   576~639 = 9
 * 128~191 = 2  640~703 = 10
 * 192~255 = 3  704~767 = 11
 * 256~319 = 4  768~831 = 12
 * 320~383 = 5  832~895 = 13
 * 384~447 = 6  896~959 = 14
 * 448~511 = 7  960~1023 = 15
*/

void __interrupt(high_priority) ADC_ISR (){
    if ( !enable )
        return;
    unsigned int number = 0;
    number = number | ADRESH;
    number = number << 8;
    number = number | ADRESL;
    unsigned char i = 0;
    while(number > 64){
        number -= 64;
        i++;
    }
    times = min ( i + 1, 9 );
    PIR1bits.ADIF = 0;
    ADCON0bits.GODONE = 1;
    __delay_us(4);
}