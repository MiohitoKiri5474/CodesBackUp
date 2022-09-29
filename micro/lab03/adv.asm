LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67
	CONFIG WDT = OFF
	org 0x00

Init:
    movlw b'00000110'
    movwf TRISA
    rrncf TRISA
    rrncf TRISA
    rrncf TRISA
    rrncf TRISA
    movlw b'00010111'
    movwf 0x001
    call ALU
    call ALU
    call ALU
    call ALU
    call ALU
    call endl

ALU:
    clrf WREG
    addwf TRISA, W
    subwf 0x001, 0
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
    subwf 0x001, 1
    rlncf 0x000, 1
    bsf 0x000, 0
    return

SMALLER:
    rlncf 0x000, 1
    bcf 0x000, 0
    return

endl:
    end

