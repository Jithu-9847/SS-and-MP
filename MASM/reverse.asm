ASSUME CS:CODE,DS:DATA

DATA SEGMENT

MS1 DB 13,10, "ENTER THE STRING $"
STR DB 0AH DUP(?)
 
DATA ENDS

CODE SEGMENT

START:	
	MOV AX,DATA
	MOV DS,AX	
	
	LEA DX,MS1
	MOV AH,09H
	INT 21H
	MOV DI,OFFSET STR
	MOV SI,OFFSET STR
	
READ:	MOV AH,1H
	INT 21H
	CMP AL,0DH
	JZ REVERSE
	MOV [DI],AL
	INC DI
	JMP READ
	
REVERSE:DEC DI
	MOV DL,[DI]
	MOV AH,02H
	INT 21H
	CMP SI,DI
	JE FINISH
	JMP REVERSE 
	
FINISH:	MOV AH,4CH
	INT 21H
	 

CODE ENDS
END START