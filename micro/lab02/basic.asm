LIST p = 18f4520
    #include <p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
    org 0x00
    
    
Initial:
    
Start:
    clrf TRISA
    clrf TRISB
    movlw 0x07
    movwf TRISB
    clrf 0x100
    clrf 0x101
    movlw 0x01
    lfsr 0, 0x100
    lfsr 1, 0x101
    lfsr 2, 0x102
    movwf INDF0
    movwf INDF1
    
    
LOOP:
    clrf WREG
    addwf POSTINC0, 0
    addwf POSTINC1, 0

    movwf POSTINC2
    incf TRISA
    clrf WREG
    addwf TRISA, 0
    cpfseq TRISB
	goto LOOP
end
