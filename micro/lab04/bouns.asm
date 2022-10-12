LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67
	CONFIG WDT = OFF
	org 0x00

Next macro x1
    clrf WREG
    addwf 0x002, W
    addwf 0x002
    goto Hanoi
    endm
	
init:
    clrf TRISC
    clrf WREG
    movlw 0x03
    movwf TRISA
    movlw 0x01
    movwf TRISB
    call Hanoi
    
    goto endl
    
Hanoi:
    clrf WREG
    addwf TRISA, W
    incf 0x002
    dcfsnz WREG
	goto ret
    decf TRISA
    clrf WREG
    addwf 0x002, W
    addwf 0x002
    goto Hanoi
ret:
    return

endl:
    end
