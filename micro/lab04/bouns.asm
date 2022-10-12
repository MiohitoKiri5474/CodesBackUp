LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67
	CONFIG WDT = OFF
	org 0x00
	
init:
    clrf WREG
    movlw 0x04
    movwf TRISA
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
