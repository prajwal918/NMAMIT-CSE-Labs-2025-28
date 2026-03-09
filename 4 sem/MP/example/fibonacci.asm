DATA SEGMENT
F1 DB 00
F2 DB 01
F3 DB ?
N DB 10
MI DB 0DH, 0AH, 'the fibonaci seriesis : $'
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START : MOV AX, DATA
        MOV DS, AX
        MOV AH, 09H
        LEA DX, MI
        INT 21H
        MOV BL, F1
        CALL DISPHEX
        MOV DL, ' '
        MOV AH, 02H
        INT 21H
        MOV BL, F2
        CALL DISPHEX
        MOV DL, ' '
        MOV AH, 02H
        INT 21H
        MOV CL, 00
        SUB N, 02
UP :    CMP CL, N
        JZ EXIT
        MOV AL, F1
        ADD AL, F2
        MOV BL, AL
        CALL DISPHEX
        MOV DL, ' '
        MOV AH, 02H
        INT 21H
        MOV F3, BL
        MOV AL, F2
        MOV F1, AL
        MOV AL, F3
        MOV F2, AL
        INC CL
        JMP UP
EXIT :  MOV AH, 4CH
        INT 21H

DISPHEX PROC NEAR
        MOV DL, BL
        MOV CL, 04
        SHR DL, CL
        CMP DL, 09H
        JBE DOWN
        ADD DL, 07H
DOWN :  ADD DL, 30H
        MOV AH, 02H
        INT 21H
        MOV DL, BL
        AND DL, 0FH
        CMP DL, 09H
        JBE DOWN1
        ADD DL, 07H
DOWN1 : ADD DL, 30H
        MOV AH, 02H
        INT 21H
        RET
DISPHEX ENDP
CODE ENDS
END START
