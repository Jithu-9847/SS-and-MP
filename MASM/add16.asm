; 16 BIT ADDTION IN MASM
; OUTPUT FORMAT: CARRY - FIRST_DIGIT - SECOND_DIGIT

ASSUME DS: DATA , CS: CODE
DATA SEGMENT
    MSG1 DB 13,10, "ENTER FIRST NUMBER: $"
    MSG2 DB 13,10, "ENTER SECOND NUMBER: $" 
    MSG3 DB 13,10, "SUM: $"
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
           MOV AH, 00H ; CLEAR
           ADD AL,CL
           AAA

           ADD AX, 3030H
           MOV BL, AL ; LOWER VALUE OF RESULT

           MOV AL, AH ; MOVE CARRY TO AL BEFORE AAA

           MOV AH, 00H;  CLEAR
           ADD AL, BH
           ADD AL, CH
           AAA
           ADD AX, 3030H
           MOV BH, AL
           MOV CL, AH

           LEA DX, MSG3
           MOV AH, 09H
           INT 21H ; PRINT "SUM: "

           MOV DL, CL
           MOV AH, 02H
           INT 21H ; PRINT CARRY

           MOV DL, BH
           MOV AH, 02H
           INT 21H ; PRINT NEXT DIGIT

           MOV DL, BL
           MOV AH, 02H
           INT 21H ; PRINT LAST DIGIT

           MOV AH, 4CH
           INT 21H

    CODE ENDS
    END START
