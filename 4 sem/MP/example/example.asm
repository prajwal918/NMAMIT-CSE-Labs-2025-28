.MODEL SMALL
.STACK 100H

.DATA
    BUF      DB 64 DUP(?)
    FILE     DB 'MYFILE.TXT', 0
    MSG      DB 'WELCOME TO MICROPROCESSOR LAB'
    MSG_LEN  EQU ($ - MSG)

.CODE
START:
    MOV AX, @DATA
    MOV DS, AX

    ; Create file
    LEA DX, FILE
    MOV CX, 0
    MOV AH, 3CH
    INT 21H
    JC EXIT_FAIL
    MOV BX, AX

    ; Write text into file
    LEA DX, MSG
    MOV CX, MSG_LEN
    MOV AH, 40H
    INT 21H
    JC CLOSE_CREATED_AND_FAIL

    ; Close created file handle
    MOV AH, 3EH
    INT 21H

    ; Open file for reading
    LEA DX, FILE
    MOV AL, 00H
    MOV AH, 3DH
    INT 21H
    JC EXIT_FAIL
    MOV BX, AX

    ; Read file content into buffer
    LEA DX, BUF
    MOV CX, 63
    MOV AH, 3FH
    INT 21H
    JC CLOSE_OPENED_AND_FAIL

    ; AX = bytes read, add '$' so INT 21H/AH=09 can display it
    MOV SI, AX
    MOV BYTE PTR BUF[SI], '$'

    ; Close opened file handle
    MOV AH, 3EH
    INT 21H

    ; Display content
    LEA DX, BUF
    MOV AH, 09H
    INT 21H
    JMP EXIT_OK

CLOSE_CREATED_AND_FAIL:
    MOV AH, 3EH
    INT 21H
    JMP EXIT_FAIL

CLOSE_OPENED_AND_FAIL:
    MOV AH, 3EH
    INT 21H

EXIT_FAIL:
    MOV AH, 4CH
    MOV AL, 01H
    INT 21H

EXIT_OK:
    MOV AH, 4CH
    MOV AL, 00H
    INT 21H

END START
