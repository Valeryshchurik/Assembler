.MODEL TINY
.CODE
.STARTUP
    INT 16H
    MOV BL,10
    SUB AL,'0'
    MUL AL
    CMP AL,16
    JG P
    MUL AL
    CMP AH,0
    JLE P
    MOV AX, '2'
    INT 29H
    MOV AL, 56
P:
    DIV BL
    ADD AL,'0'
    INT 29H    
    MOV AL, AH
    ADD AL,'0'
    INT 29H
END