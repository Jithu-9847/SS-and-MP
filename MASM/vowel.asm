ASSUME DS: DATA, CS: CODE

DATA SEGMENT
    INP DB 0AH, 0DH, 'ENTER THE STRING: $'
    MSG DB 0AH, 0DH, 'THE NUMBER OF VOWELS: $'
    VOWEL DB 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', '$'
    DATABUF DB 100, 0, 100 DUP('$')
DATA ENDS

CODE SEGMENT
    START:
        MOV AX, DATA
        MOV DS, AX

        LEA DX, INP
        MOV AH, 09H
        INT 21H

        LEA DX, DATABUF
        MOV AH, 0AH
        INT 21H
        MOV SI, DX

        LEA DX, MSG
        MOV AH, 09H
        INT 21H

        MOV BL, 00H
    CHECK:
        LEA DI, VOWEL
        MOV CX, 000AH
        MOV AL, [SI]
    CONT:
        CMP AL, [DI]
        JE FOUND
        INC DI
        LOOP CONT
        JMP NEXT
    FOUND:
        INC BL
    NEXT:
        INC SI
        CMP DATABUF[SI], 0AH
        JNE CHECK

        MOV DL, BL
        ADD DL, 30H
        MOV AH, 02H
        INT 21H

        MOV AH, 4CH
        INT 21H
CODE ENDS
END START
