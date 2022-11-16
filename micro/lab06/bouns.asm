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
    MOVLW 0x0f
    MOVWF ADCON1
    CLRF TRISB
    BSF TRISB, 0;set RA4 as input, TRISA = 0001 0000
    CLRF TRISA ;set RD0~RD3 as output, TRISD = 0000 0000
    CLRF LATA
    MOVLW B'00000000'
    MOVWF LATA, 0 ; set RAD0~RAD3 initial status, RD1 and 3 is light
    
check_press_1:
    BTFSC PORTB, 0
    BRA check_press_1
    BRA light_change_1
    
light_change_1:
    ; we don't need to care about RD4~RD7
    MOVLW B'00110011'
    MOVWF LATA, 0
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    CLRF LATA
    
    DELAY D'90', D'70'
    BRA check_press_2
    
check_press_2:
    BTFSC PORTB, 0
    BRA check_press_2
    BRA light_change_2
    
light_change_2:
    ; we don't need to care about RD4~RD7
    MOVLW B'01100110'
    MOVWF LATA, 0
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    CLRF LATA
    
    DELAY D'90', D'70'
    BRA check_press_3
    
check_press_3:
    BTFSC PORTB, 0
    BRA check_press_3
    BRA light_change_3
    
light_change_3:
    ; we don't need to care about RD4~RD7
    MOVLW B'11001100'
    MOVWF LATA, 0
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    CLRF LATA
    
    DELAY D'90', D'70'
    BRA check_press_4
    
check_press_4:
    BTFSC PORTB, 0
    BRA check_press_4
    BRA light_change_4
    
light_change_4:
    ; we don't need to care about RD4~RD7
    MOVLW B'10011001'
    MOVWF LATA, 0
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    RLNCF LATA, 1
    DELAY D'90', D'80'
    CLRF LATA
    
    DELAY D'90', D'70'
    BRA check_press_1
end


