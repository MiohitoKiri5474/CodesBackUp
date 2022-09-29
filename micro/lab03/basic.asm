LIST p = 18f4520
#include<p18f4520.inc>
    org 0x00

    
start:
init:
    lfsr 0, 0x000
    movlw 0x10
    movwf POSTINC0
    movlw 0x11
    movwf POSTINC0
    movlw 0x12
    movwf POSTINC0
    movlw 0xFF
    movwf POSTINC0
    lfsr 0, 0x010
    movlw 0x20
    movwf POSTINC0
    movlw 0x21
    movwf POSTINC0
    movlw 0x22
    movwf POSTINC0
    movlw 0xFF
    movwf POSTINC0
    lfsr 0, 0x003
    lfsr 1, 0x013
    lfsr 2, 0x023
    clrf TRISA

LOOP:
    call ADD
    clrf WREG
    incf TRISA
    addwf TRISA, 0
    btfss TRISA, 2
		goto LOOP
    goto endl
    
ADD:
    clrf WREG
    clrf TRISB
    clrf TRISC
    addwf INDF0, 0
    addwf INDF1, 0
    cpfsgt POSTDEC0
		incf TRISB
    cpfsgt POSTDEC1
		incf TRISB
    btfsc TRISB, 1
		incf TRISC
    addwf POSTDEC2, 1
    btfss TRISC, 0
		incf INDF2
    return
    
endl:
    
    end

