LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67
	CONFIG WDT = OFF
	org 0x00

init:
    clrf TRISA
    lfsr 0, 0x010
    movlw 0x01
    movwf INDF0
    movwf 0x002
    movlw 0x03
    movwf TRISA
    clrf TRISB
    rcall GP

    clrf WREG
    movlw endl
    movwf PCL
    
GP:
    clrf WREG
    addwf POSTINC0, W
    mulwf TRISA
    clrf WREG
    addwf PRODL, W
    movwf INDF0
    addwf 0x002
    incf TRISB
    clrf WREG
    movlw GP
    btfss TRISB, 1
	movwf PCL
    return
    
endl:
    end
