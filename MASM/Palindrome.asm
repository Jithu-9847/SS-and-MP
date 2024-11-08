ASSUME DS: DATA, CS: CODE

DATA SEGMENT 
    MSG1 DB 10,13, "ENTER THE STRING: $"
    MSG2 DB 10,13, "THE STRING IS A PALINDROME$"
    MSG3 DB 10,13,"THE STRING IS NOT A PALINDROME$"
    STR1 DB 50 DUP(0)
DATA ENDS

CODE SEGMENT 
    START: MOV AX, DATA
           MOV DS, AX

           LEA DX, MSG1
           MOV AH, 09H
           INT 21H

           LEA SI, STR1
           LEA DI, STR1 

           MOV AH, 01H
    NEXT:  
           INT 21H
           CMP AL, 0DH ; 0D IS FOR ENTER 
           JE TERMINATE
           MOV [DI], AL
           INC DI
           JMP NEXT

    TERMINATE: 
           MOV AL,'$'
           MOV [DI], AL

    DOTHIS:
           DEC DI
           MOV AL,[SI]
           CMP [DI],AL
           JNE NOTPALINDROME

           INC SI
           CMP SI,DI
           JL DOTHIS

    PALINDROME: 
           MOV AH,09H
           LEA DX, MSG2
           INT 21H
           JMP EXIT

    NOTPALINDROME: 
           LEA DX, MSG3
           MOV AH, 09H
           INT 21H
           

    EXIT:    
           MOV AH,4CH
           INT 21H

CODE ENDS
END START



           
