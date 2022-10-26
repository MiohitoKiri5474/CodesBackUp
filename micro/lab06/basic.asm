LIST p=18f4520
#include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
    ;CONFIG PBADEN
    CONFIG LVP = OFF
    
    L1 EQU 0x14
    L2 EQU 0x15
    
    ORG 0x0
    
DELAY macro num1, num2
    local LOOP1
    local LOOP2
    MOVLW num2
    MOVWF L2
    LOOP2:
        MOVLW num1
        MOVWF L1
    LOOP1:
        NOP
	NOP
	NOP
	NOP
	NOP
	DECFSZ L1, 1
	BRA LOOP1
	DECFSZ L2, 1
	BRA LOOP2
    endm

start:
init:
    CLRF TRISA
    BSF TRISB, 0;set RA4 as input, TRISA = 0001 0000
    CLRF TRISD ;set RD0~RD3 as output, TRISD = 0000 0000
    CLRF LATD
    MOVLW B'00000000'
    MOVWF LATD, 0 ; set RAD0~RAD3 initial status, RD1 and 3 is light
    
check_press:
    BTFSC PORTB, 0
    BRA check_press
    BRA light_change
    
light_change:
    ; we don't need to care about RD4~RD7
    BSF LATD, 0
    DELAY D'90', D'80'
    BSF LATD, 1
    DELAY D'90', D'80'
    BSF LATD, 2
    DELAY D'90', D'80'
    BSF LATD, 3
    DELAY D'90', D'80'
    CLRF LATD
    
    DELAY D'90', D'80'
    BRA check_press
    
end
