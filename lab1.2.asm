 .MODEL SMALL
 .STACK 100H

 .DATA
    CONST16 DB 16
    HEXSYM DB '0123456789ABCDEF'
    CODSYM DB 0
 .CODE
   MAIN PROC
     MOV AX, @DATA                 
     MOV DS, AX

     MOV CX, 256                  
     
     MOV AH, 2                     
     MOV DX, 256     
     O:
        MOV DX, 256
        SUB DX, CX   
        MOV AX,40H
        MOV ES,AX
        MOV BH,ES:[62H]
        MOV AH,0AH
        MOV AL,CODSYM
        MOV DX, CX
        MOV SI, CX
        MOV CX,1
        INT 10H
        MOV AH,03H
        INT 10H
        INC DL
        MOV AH,02H
        INT 10H
        MOV DL,'-'
        MOV AH,06H
        INT 21H
        MOV CX, SI                         
        XOR AH,AH
        MOV AL,CODSYM
        DIV CONST16
        MOV BX,OFFSET HEXSYM
        XLAT
        XCHG AX,DX
        MOV AH,06H
        INT 21H
        
        MOV AL,DH
        XLAT
        MOV DL,AL
        MOV AH,06H
        INT 21H
    
        MOV DL,' '
        MOV AH,06H
        INT 21H
        ADD CODSYM,1
        LOOP O                   

     MOV AH, 4CH                  
     INT 21H
   MAIN ENDP
 END MAIN