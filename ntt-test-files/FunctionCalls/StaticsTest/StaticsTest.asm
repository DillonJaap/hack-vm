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
// function Class1.set 0      
(Class1.set)
// push argument 0      
@0
D=A
@ARG
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop static 0      
@Class1.0
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push argument 1      
@1
D=A
@ARG
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop static 1      
@Class1.1
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push constant 0      
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// return        
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
// function Class1.get 0      
(Class1.get)
// push static 0      
@Class1.0
D=M
@SP
A=M
M=D
@SP
M=M+1
// push static 1      
@Class1.1
D=M
@SP
A=M
M=D
@SP
M=M+1
// sub        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=M-D
@SP
M=M+1
// return        
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
// function Class2.set 0      
(Class2.set)
// push argument 0      
@0
D=A
@ARG
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop static 0      
@Class2.0
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push argument 1      
@1
D=A
@ARG
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop static 1      
@Class2.1
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push constant 0      
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// return        
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
// function Class2.get 0      
(Class2.get)
// push static 0      
@Class2.0
D=M
@SP
A=M
M=D
@SP
M=M+1
// push static 1      
@Class2.1
D=M
@SP
A=M
M=D
@SP
M=M+1
// sub        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=M-D
@SP
M=M+1
// return        
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
// function Sys.init 0      
(Sys.init)
// push constant 6      
@6
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 8      
@8
D=A
@SP
A=M
M=D
@SP
M=M+1
// call Class1.set 2      
@Class1.set.return.0
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
@2
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
@Class1.set
0;JMP
(Class1.set.return.0)
// pop temp 0      
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
// push constant 23      
@23
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 15      
@15
D=A
@SP
A=M
M=D
@SP
M=M+1
// call Class2.set 2      
@Class2.set.return.1
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
@2
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
@Class2.set
0;JMP
(Class2.set.return.1)
// pop temp 0      
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
// call Class1.get 0      
@Class1.get.return.2
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
@0
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
@Class1.get
0;JMP
(Class1.get.return.2)
// call Class2.get 0      
@Class2.get.return.3
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
@0
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
@Class2.get
0;JMP
(Class2.get.return.3)
// label WHILE       
(Sysss2.WHILE)
// goto WHILE       
@Sysss2.WHILE
0;JMP
