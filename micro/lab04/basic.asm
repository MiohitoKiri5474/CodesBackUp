LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67
	CONFIG WDT = OFF
	org 0x00

DIST macro x1, y1, x2, y2, hi, lo
    clrf TRISA
    clrf WREG
    movlw x1
    movwf TRISA
    movlw x2
    subwf TRISA
    
    clrf TRISB
    clrf WREG
    movlw y1
    movwf TRISB
    movlw y2
    subwf TRISB
    
    clrf WREG
    addwf TRISA, W
    mulwf TRISA
    movff PRODH, hi
    movff PRODL, lo
    
    clrf WREG
    addwf TRISB, W
    mulwf TRISB
    clrf WREG
    addwf hi, W
    addwf PRODH, W
    movwf hi
    clrf WREG
    addwf lo, W
    addwfc PRODL, W
    movwf lo
    bnc RNT
    incf hi
RNT:
    endm
	
	
init:
    DIST 0x05, 0x07, 0x02, 0x03, 0x00, 0x01
endl:
    end
