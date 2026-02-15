DATA SEGMENT
ORG 2000H
MSG1 DB 0DH, 0AH, 'Enter a string:$'
MSG2 DB 0DH, 0AH, 'You entered :$'
BUFFER DB 20
       DB ?
       DB 20 DUP('$')
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START: MOV AX, DATA
       MOV DS, AX
       MOV AH, 09H
       LEA DX, MSG1
       INT 21H
       MOV AH, 0AH
       LEA DX, BUFFER
       INT 21H
       MOV AH, 09H
       LEA DX, MSG2
       INT 21H
       MOV AH, 09H
       LEA DX, BUFFER+2
       INT 21H
       MOV AH, 4CH
       INT 21H
CODE ENDS
END START
