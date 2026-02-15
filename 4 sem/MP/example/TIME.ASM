DATA SEGMENT
MSG DB 0DH, 0AH, 'The current time is: $'
HR DB ?
MIN DB ?
SEC DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START: MOV AX, DATA
       MOV DS, AX
       MOV AH, 09H
       LEA DX, MSG
       INT 21H
       MOV AH, 2CH
       INT 21H
       MOV HR, CH
       MOV MIN, CL
       MOV SEC, DH
       MOV AL, HR
       CALL UNPACK_DISP
       MOV DL, ':'
       MOV AH, 02H
       INT 21H
       MOV AL, MIN
       CALL UNPACK_DISP
       MOV DL, ':'
       MOV AH, 02H
       INT 21H
       MOV AL, SEC
       CALL UNPACK_DISP
       MOV AH, 4CH
       INT 21H

UNPACK_DISP PROC NEAR
       AAM
       MOV BX, AX
       ADD BH, 30H
       MOV AH, 02H
       MOV DL, BH
       INT 21H
       ADD BL, 30H
       MOV AH, 02H
       MOV DL, BL
       INT 21H
       RET
UNPACK_DISP ENDP

CODE ENDS
END START
