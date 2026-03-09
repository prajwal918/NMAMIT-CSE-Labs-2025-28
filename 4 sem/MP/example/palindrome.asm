Data Segment
Str1  DB  50 DUP(?)
Str2  DB  50 DUP(?)
n     DB  ?
M1    DB  0DH,0AH, ' Enter a String: $'
M2    DB  0DH,0AH, ' It is palindrome $'
M3    DB  0DH,0AH, ' It is not a palindrome$'
Data ends

Code Segment
Assume cs:code, ds:Data
Start: MOV AX, DATA
       MOV DS, AX
       CALL MSG1
       LEA SI, Str1
       LEA DI, Str2
       CALL Readstring
       MOV n, CL
       DEC SI
       CALL Reverse
       LEA SI, Str1
       LEA DI, Str2
       CALL Check
       MOV AH, 4CH
       INT 21H

MSG1 Proc Near
     MOV AH, 09H
     LEA DX, M1
     INT 21H
     RET
MSG1 ENDP

Readstring Proc Near
     MOV CL, 00
UP:  CMP CL, 50
     JZ Stop
     MOV AH, 01H
     INT 21H
     CMP AL, 0DH
     JZ Stop
     MOV [SI], AL
     INC SI
     INC CL
     JMP UP
Stop: Ret
Readstring ENDP

Reverse Proc Near
      MOV CL, 00
UP1:  CMP CL, n
      JZ Stop1
      MOV BL, [SI]
      MOV [DI], BL
      INC DI
      DEC SI
      INC CL
      JMP UP1
Stop1: Ret
Reverse Endp

Check proc Near
      MOV CL, 00
Up2:  CMP CL, n
      JZ Pal
      MOV BL, [DI]
      CMP [SI], BL
      JNE NotPal
      INC SI
      INC DI
      INC CL
      JMP Up2
Pal:  MOV AH, 09H
      LEA DX, M2
      INT 21H
      JMP Exit
NotPal: MOV AH, 09H
        LEA DX, M3
        INT 21H
Exit: Ret
Check Endp

Code ends
End Start
