// BOOT CODE
@256
D=A
@SP
M=D
@Sys.init0
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
@SP
D=M
@5
D=A
@0
D=D+A
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@Sys.init
0;JMP
(Sys.init0)
// Generic Return
(...GENERIC_RETURN...)
@LCL
D=M
@R13
M=D
@R13
D=M
@5
AD=D-A
D=M
@R14
M=D
@SP
AM=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M
@SP
M=D+1
@R13
D=M
@1
AD=D-A
D=M
@THAT
M=D
@R13
D=M
@2
AD=D-A
D=M
@THIS
M=D
@R13
D=M
@3
AD=D-A
D=M
@ARG
M=D
@R13
D=M
@4
AD=D-A
D=M
@LCL
M=D
@R14
A=M
0;JMP
// function Main.fibonacci 0      
(Main.fibonacci)
// push argument 0      
@ARG
A=M
D=M
@SP
M=M+1
A=M-1
M=D
// push constant 2      
@2
D=A
@SP
M=M+1
A=M-1
M=D
// lt        
@SP
AM=M-1
D=M 
@SP
AM=M-1
D=M-D
M=-1
@END_LT0
D;JLT
@SP
A=M
M=0
(END_LT0)
@SP
M=M+1
// if-goto IF_TRUE       
@SP
AM=M-1
D=M
@Main.Main.fibonacci.IF_TRUE
D;JNE
// goto IF_FALSE       
@Main.IF_FALSE
0;JMP
// label IF_TRUE       
(Main.Main.fibonacci.IF_TRUE)
// push argument 0      
@ARG
A=M
D=M
@SP
M=M+1
A=M-1
M=D
// return        
@...GENERIC_RETURN...
0;JMP
// label IF_FALSE       
(Main.IF_FALSE)
// push argument 0      
@ARG
A=M
D=M
@SP
M=M+1
A=M-1
M=D
// push constant 2      
@2
D=A
@SP
M=M+1
A=M-1
M=D
// sub        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=M-D
@SP
M=M+1
// call Main.fibonacci 1      
@Main.fibonacci.return.0
D=A
@SP
M=M+1
A=M-1
M=D
@LCL
D=M
@SP
M=M+1
A=M-1
M=D
@ARG
D=M
@SP
M=M+1
A=M-1
M=D
@THIS
D=M
@SP
M=M+1
A=M-1
M=D
@THAT
D=M
@SP
M=M+1
A=M-1
M=D
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
@Main.fibonacci
0;JMP
(Main.fibonacci.return.0)
// push argument 0      
@ARG
A=M
D=M
@SP
M=M+1
A=M-1
M=D
// push constant 1      
@1
D=A
@SP
M=M+1
A=M-1
M=D
// sub        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=M-D
@SP
M=M+1
// call Main.fibonacci 1      
@Main.fibonacci.return.1
D=A
@SP
M=M+1
A=M-1
M=D
@LCL
D=M
@SP
M=M+1
A=M-1
M=D
@ARG
D=M
@SP
M=M+1
A=M-1
M=D
@THIS
D=M
@SP
M=M+1
A=M-1
M=D
@THAT
D=M
@SP
M=M+1
A=M-1
M=D
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
@Main.fibonacci
0;JMP
(Main.fibonacci.return.1)
// add        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
M=M+1
// return        
@...GENERIC_RETURN...
0;JMP
// function Sys.init 0      
(Sys.init)
// push constant 4      
@4
D=A
@SP
M=M+1
A=M-1
M=D
// call Main.fibonacci 1      
@Main.fibonacci.return.2
D=A
@SP
M=M+1
A=M-1
M=D
@LCL
D=M
@SP
M=M+1
A=M-1
M=D
@ARG
D=M
@SP
M=M+1
A=M-1
M=D
@THIS
D=M
@SP
M=M+1
A=M-1
M=D
@THAT
D=M
@SP
M=M+1
A=M-1
M=D
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
@Main.fibonacci
0;JMP
(Main.fibonacci.return.2)
// label WHILE       
(Sys.Sys.init.WHILE)
// goto WHILE       
@Sys.Sys.init.WHILE
0;JMP
