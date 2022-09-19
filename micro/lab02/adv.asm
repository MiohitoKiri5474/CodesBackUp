LIST p=18f4520
#include<p18f4520.inc>
    org 0x00
    
start:
init:
    lfsr 0, 0x010
    movlw 0x0B
    movwf 0x010, 1
    movlw 0x005
    movwf 0x011, 1
    movlw 0x40
    movwf 0x012, 1
    movlw 0x07
    movwf 0x013, 1
    movlw 0x0D
    movwf 0x014, 1
    movlw 0x7F
    movwf 0x015, 1
    movlw 0x0A
    movwf 0x016, 1
    movlw 0x01
    movwf 0x017, 1
    movlw 0xFE
    movwf 0x018, 1

    clrf TRISA
    clrf TRISD
    movlw 0x08
    movwf TRISD

loop1:
    clrf WREG
    clrf TRISB
    lfsr 0, 0x010
    lfsr 1, 0x011
    call loop2
    incf TRISA

    clrf WREG
    addwf TRISA, 0
    cpfseq TRISD
	goto loop1
    goto endl
    
loop2:
    clrf WREG
    addwf INDF0, W
    cpfsgt INDF1
    	call swap
    clrf WREG
    addwf POSTINC0, F
    addwf POSTINC1, F
    incf TRISB, F

    clrf WREG
    addwf TRISB, 0
    cpfseq TRISD
	goto loop2
    return
    
swap: 
    movff INDF0, TRISC
    movff INDF1, INDF0
    movff TRISC, INDF1
    return
    
endl:
    end
