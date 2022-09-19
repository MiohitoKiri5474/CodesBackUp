LIST p = 18f4520
#include<p18f4520.inc>
    org 0x00

    
start:
init:
    lfsr 0, 0x100
    movlw 0xA1
    movwf POSTINC0
    movlw 0xB2
    movwf POSTINC0
    movlw 0xC3
    movwf POSTINC0
    movlw 0xD4
    movwf POSTINC0
    movlw 0xE5
    movwf POSTINC0
    
    lfsr 0, 0x110
    movlw 0xA7
    movwf POSTINC0
    movlw 0xB3
    movwf POSTINC0
    movlw 0xC9
    movwf POSTINC0
    movlw 0xF6
    movwf POSTINC0
    
    lfsr 0, 0x100
    lfsr 1, 0x110
    lfsr 2, 0x120
    
    clrf TRISA
    clrf TRISB
    clrf TRISC
    
MERGE:
    clrf WREG
    addwf INDF0, W
    cpfslt INDF1
	call PUSH_A
    cpfsgt INDF1
	call PUSH_B
	
    clrf TRISC
    clrf WREG
    movlw 0x05
    cpfseq TRISA
	incf TRISC
    clrf WREG
    movlw 0x04
    cpfseq TRISC
	incf TRISC
	
    btfss TRISC, 1
	goto endl
    goto MERGE
    
PUSH_A:
    clrf WREG
    addwf POSTINC0, W
    movwf POSTINC2
    
    incf TRISA
    ; incf TRISC
    return
    
PUSH_B:
    clrf WREG
    addwf POSTINC1, W
    movwf POSTINC2
    
    incf TRISB
    ; incf TRISC
    return
    
CLEAR_A:

CLEAR_B:
    
endl:
    clrf WREG
    movlw 0x05
    cpfseq TRISA
	call CLEAR_A
    clrf WREG
    movlw 0x04
    cpfseq TRISB
	call CLEAR_B
    end

