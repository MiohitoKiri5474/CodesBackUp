#include "p18f4520.inc"

CONFIG  OSC = INTIO67
CONFIG  WDT = OFF
CONFIG  PBADEN = OFF
CONFIG  LVP = OFF

CNTVAL equ d'253'
L1 equ 0x14
L2 equ 0x15
org 0x00

goto INITIAL

DELAY macro num1, num2
    local LOOP1
    local LOOP2
    movlw num2
    movwf L2
    LOOP2:
        movlw num1
        movwf L1
        LOOP1:
            nop
            nop
            nop
            nop
            decfsz L1, 1
            goto LOOP1
        decfsz L2, 1
        goto LOOP2
endm

ISR:
    org 0x08
    btg 0x11, 0 ;0x11[0] toggle
    bcf INTCON, INT0IF
    retfie

INITIAL:
    movlw 0x11
    movwf 0x10 ;0x10==b'00010001'
	movlw 0x55
	movwf 0x12 ;0x12==b'01010101'
    clrf 0x11  ;0x11[0]==0

    clrf PORTA
    clrf LATA
    bsf  TRISB, 0 ;set RA4 as input
    clrf TRISD
    clrf PORTD
    
    movlw b'11111000' ;setup T0CON
    movwf T0CON, 0

    clrf TMR0L, 0     ;set up timer
    bsf RCON, IPEN
    bsf INTCON, GIE
    bsf INTCON, INT0IE
    bcf INTCON, INT0IF 
    
    movlw CNTVAL
    movwf TMR0L, 0

MAIN:
    btfsc 0x11, 0
	goto Type2
    btfss 0x11, 0
	goto Type1

    DELAY d'200', d'90'
    goto MAIN
    
Type1:
    rlncf 0x10, 1 ;0x11[0]!=1
    clrf LATD
    
    btfsc 0x10, 0 ;lightup RD0 if 0x10[0]==1
    btg LATD, 0

    btfsc 0x10, 1 ;lightup RD1 if 0x10[1]==1
    btg LATD, 1

    btfsc 0x10, 2 ;lightup RD2 if 0x10[2]==1
    btg LATD, 2

    btfsc 0x10, 3 ;lightup RD3 if 0x10[3]==1
    btg LATD, 3
    
    DELAY d'200', d'90'
    goto MAIN
    
Type2:
	rlncf 0x12, 1
	clrf LATD
	btfsc 0x12, 0
		goto BlinkOdd
	goto BlinkEven

BlinkOdd:
	btg LATD, 1
	btg LATD, 3

	DELAY d'200', d'90'
	goto MAIN

BlinkEven:
	btg LATD, 0
	btg LATD, 2

	DELAY d'200', d'90'
    goto MAIN
end
