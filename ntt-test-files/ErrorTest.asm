// poopy label 2      
// pop4 thing       
// _pop_ thing       
// push. okay       
// and$        
// $or        
// pop temp       
@5
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// pop temp 5 okay     
@10
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push temp       
@5
D=M
@SP
A=M
M=D
@SP
M=M+1
// push        
// function epic 5 5     
(epic)
@SP
A=M
M=0
@SP
M=M+1
@SP
A=M
M=0
@SP
M=M+1
@SP
A=M
M=0
@SP
M=M+1
@SP
A=M
M=0
@SP
M=M+1
@SP
A=M
M=0
@SP
M=M+1
// add 5 6      
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
M=M+1
// sub 3       
@SP
AM=M-1
D=M
@SP
AM=M-1
M=M-D
@SP
M=M+1
// and 1 1 1 1 1 1  
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D&M
@SP
M=M+1
// push fake 69      
// pop fake 69      
// push constant -666      
@-666
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop local -1      
@-1
D=A
@LCL
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push this -1      
@-1
D=A
@THIS
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// push that -1      
@-1
D=A
@THAT
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop constat NAN      
// pop aCap inYoButt      
// push constant 42069420      
@42069420
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop temp 8      
@13
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// pop local 32768      
@32768
D=A
@LCL
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// pop argument 32768      
@32768
D=A
@ARG
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push pointer 2      
// pop pointer 2      
// push static 240      
@ErrorTest.240
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop static 240      
@ErrorTest.240
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push ram 32768      
// pop ram 32768      
// label %okay%       
(%okay%)
// label (okay)       
((okay))
// goto 123dk       
@123dk
0;JMP
// if-goto YEET*&       
@SP
AM=M-1
D=M
@YEET*&
D;JNE
// goto doesNotExist       
@doesNotExist
0;JMP
// if-goto doesNotExist       
@SP
AM=M-1
D=M
@doesNotExist
D;JNE
// function %okay% 1      
(%okay%)
@SP
A=M
M=0
@SP
M=M+1
// function (okay) 1      
((okay))
@SP
A=M
M=0
@SP
M=M+1
// function 123dk 1      
(123dk)
@SP
A=M
M=0
@SP
M=M+1
// function YEET*& 1      
(YEET*&)
@SP
A=M
M=0
@SP
M=M+1
// call %okay% 1      
@%okay%.return1
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@1
D=A
@5
D=D+A
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@%okay%
0;JMP
(%okay%.return1)
// call (okay) 1      
@(okay).return1
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@1
D=A
@5
D=D+A
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@(okay)
0;JMP
((okay).return1)
// call 123dk 1      
@123dk.return1
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@1
D=A
@5
D=D+A
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@123dk
0;JMP
(123dk.return1)
// call YEET*& 1      
@YEET*&.return1
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@1
D=A
@5
D=D+A
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@YEET*&
0;JMP
(YEET*&.return1)
// function okay -5      
(okay)
// call okay -5      
@okay.return-5
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@-5
D=A
@5
D=D+A
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@okay
0;JMP
(okay.return-5)
