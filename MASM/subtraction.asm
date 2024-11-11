ASSUME DS: DATA , CS: CODE

DATA SEGMENT
    MSG1 DB 13,10, "ENTER FIRST NUMBER: $"
    MSG2 DB 13,10, "ENTER SECOND NUMBER: $" 
    MSG3 DB 13,10, "DIFFERENCE: $"
    MSG4 DB 13,10, "NEGATIVE NUMBER: $"
DATA ENDS

CODE SEGMENT

    START: MOV AX, DATA
           MOV DS, AX

           LEA DX, MSG1
           MOV AH, 09H
           INT 21H

           MOV AH, 01H
           INT 21H
           MOV BH, AL 
           
           MOV AH, 01H
           INT 21H 
           MOV BL, AL

           LEA DX, MSG2
           MOV AH, 09H
           INT 21H

           MOV AH, 01H
           INT 21H
           MOV CH, AL
           MOV AH, 01H
           INT 21H
           MOV CL, AL

           MOV AL,BL
           
           LEA DX,MSG3
           MOV AH,09H
           INT 21H
           
           CMP BH,CH
           JL SWAP
           JE CHECK
           JMP GO
           
CHECK:	
           CMP BL,CL
           JG GO
           JL SWAP
           
SWAP:
           MOV AL,BH
           MOV BH,CH
           MOV CH,AL
           MOV AL,BL
           MOV BL,CL
           MOV CL,AL
           LEA DX,MSG4
           MOV AH,09H
           INT 21H
GO:	
           MOV AL,BL
           SUB AL,CL
           JC CARRY
           AAS
           ADD AL,30H
           MOV BL,AL
           
           MOV AL,BH
           SUB AL,CH
           ADD AL,30H
           
           MOV DL,AL
           MOV AH,02H
           INT 21H
           
           MOV DL,BL
           MOV AH,02H
           INT 21H
           JMP FINISH
           
CARRY:	   
           AAS
           ADD AL,30H
           MOV BL,AL
           
           DEC BH
           MOV AL,BH
           SUB AL,CH
           ADD AL,30H
           
           MOV DL,AL
           MOV AH,02H
           INT 21H
           
           MOV DL,BL
           MOV AH,02H
           INT 21H
           
FINISH:    MOV AH, 4CH
           INT 21H


CODE ENDS
END START
