DATA SEGMENT
ARR DB 10H, 20H, 30H, 40H, 50H
KEY DB 40H
LEN DB $ - ARR
MSG1 DB 0DH, 0AH, ' Key found $'
MSG2 DB 0DH, 0AH, ' Key not found $'
MID  DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START: MOV AX, DATA
       MOV DS, AX
       LEA SI, ARR
       MOV AL, LEN
       DEC AL
       MOV AH, 00
       ADD AX, SI
       MOV DI, AX
       MOV CL, KEY
UP:    CMP SI, DI
       JG Notfound
       MOV AX, SI
       ADD AX, DI
       SHR AX, 01
       MOV BX, AX
       MOV MID, BX
       CMP CL, [BX]
       JZ Found
       JB lefthalf
       INC WORD PTR MID
       MOV SI, MID
       JMP UP
lefthalf: DEC WORD PTR MID
          MOV DI, MID
          JMP UP
Notfound: Lea DX, MSG2
          MOV AH, 09H
          INT 21H
          JMP Exit
found:    Lea DX, MSG1
          MOV AH, 09H
          INT 21H
Exit:     MOV AH, 4CH
          INT 21H
CODE ENDS
END START
