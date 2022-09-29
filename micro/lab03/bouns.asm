LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67
	CONFIG WDT = OFF
	org 0x00

init:
    movlw 0xF5 ; 0xF5 = 245
    movwf 0x010
    movlw 0x5A ; 0X5A = 90
    movwf 0x011
    
    movff 0x010, TRISA
    movff 0x011, TRISB
    
GCD:
    movff TRISA, WREG
    cpfslt TRISB
    call SWAP
    movff TRISB, WREG
    subwf TRISA, F
    bz NEXT
    goto GCD
    
SWAP:
    movff TRISA, TRISC
    movff TRISB, TRISA
    movff TRISC, TRISB
    return

NEXT:
    clrf TRISA
    clrf TRISB
    addwf TRISA
    rrncf TRISA
    rrncf TRISA
    rrncf TRISA
    rrncf TRISA

    call ALU
    call ALU
    call ALU
    call ALU
    call ALU
    call endl
    
ALU:
    clrf WREG
    addwf TRISA, W
    subwf 0x011, 0
    bnn CHECK
        call SMALLER
    rrncf TRISA, 1
    return

CHECK:
    call LARGER
    rrncf TRISA, 1
    return

LARGER:
    clrf WREG
    addwf TRISA, W
    subwf 0x011, 1
    rlncf TRISB, 1
    bsf TRISB, 0
    return

SMALLER:
    rlncf TRISB, 1
    bcf TRISB, 0
    return


    
endl:
    clrf WREG
    addwf TRISB, W
    mulwf 0x010
    movff PRODH, 0x000
    movff PRODL, 0x001
    end

