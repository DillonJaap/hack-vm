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
// function Sys.init 0      
(Sys.init)
// push constant 4000      
@4000
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop pointer 0      
@THIS
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push constant 5000      
@5000
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop pointer 1      
@THAT
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// call Sys.main 0      
@Sys.main.return.0
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
@Sys.main
0;JMP
(Sys.main.return.0)
// pop temp 1      
@6
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// label LOOP       
(Sys.LOOP)
// goto LOOP       
@Sys.LOOP
0;JMP
// function Sys.main 5      
(Sys.main)
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
// push constant 4001      
@4001
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop pointer 0      
@THIS
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push constant 5001      
@5001
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop pointer 1      
@THAT
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push constant 200      
@200
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop local 1      
@1
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
// push constant 40      
@40
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop local 2      
@2
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
// push constant 6      
@6
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop local 3      
@3
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
// push constant 123      
@123
D=A
@SP
A=M
M=D
@SP
M=M+1
// call Sys.add12 1      
@Sys.add12.return.1
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
@Sys.add12
0;JMP
(Sys.add12.return.1)
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
// push local 0      
@0
D=A
@LCL
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// push local 1      
@1
D=A
@LCL
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// push local 2      
@2
D=A
@LCL
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// push local 3      
@3
D=A
@LCL
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// push local 4      
@4
D=A
@LCL
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// add        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
M=M+1
// add        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
M=M+1
// add        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
M=M+1
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
// function Sys.add12 0      
(Sys.add12)
// push constant 4002      
@4002
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop pointer 0      
@THIS
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push constant 5002      
@5002
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop pointer 1      
@THAT
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
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
// push constant 12      
@12
D=A
@SP
A=M
M=D
@SP
M=M+1
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