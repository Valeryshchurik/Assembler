.MODEL TINY
.CODE
.STARTUP
	MOV AX,40H
	MOV ES,AX
	MOV BH,ES:[62H]
	MOV AL,10
	MOV CX,1
	MOV AH,0AH
	INT 10H
	INT 20H
END