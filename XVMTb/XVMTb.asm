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
// function Test.test 2      
(Test.test)
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
// push constant 8      
@8
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop static 42      
@Test.42
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
// push constant 0      
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 42      
@42
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop constant 0      
@SP
AM=M-1
// push constant 0      
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// eq        
@SP
AM=M-1
D=M 
@SP
AM=M-1
D=M-D
M=-1
@END_EQ0
D;JEQ
@SP
A=M
M=0
(END_EQ0)
@SP
M=M+1
// pop ram 3001      
@SP
AM=M-1
D=M
@3001
M=D
// push ram 3      
@3
D=M
@SP
A=M
M=D
@SP
M=M+1
// push pointer 0      
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
// eq        
@SP
AM=M-1
D=M 
@SP
AM=M-1
D=M-D
M=-1
@END_EQ1
D;JEQ
@SP
A=M
M=0
(END_EQ1)
@SP
M=M+1
// pop this 2      
@2
D=A
@THIS
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push constant 42      
@42
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop ram 3003      
@SP
AM=M-1
D=M
@3003
M=D
// push ram 0      
@0
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop this 4      
@4
D=A
@THIS
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push ram 4      
@4
D=M
@SP
A=M
M=D
@SP
M=M+1
// push pointer 1      
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
// eq        
@SP
AM=M-1
D=M 
@SP
AM=M-1
D=M-D
M=-1
@END_EQ2
D;JEQ
@SP
A=M
M=0
(END_EQ2)
@SP
M=M+1
// pop this 5      
@5
D=A
@THIS
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push constant 32767      
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop ram 3006      
@SP
AM=M-1
D=M
@3006
M=D
// push ram 3006      
@3006
D=M
@SP
A=M
M=D
@SP
M=M+1
// neg        
@SP
AM=M-1
M=-M
@SP
M=M+1
// pop ram 3007      
@SP
AM=M-1
D=M
@3007
M=D
// push ram 3006      
@3006
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop temp 7      
@12
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push ram 12      
@12
D=M
@SP
A=M
M=D
@SP
M=M+1
// push ram 3007      
@3007
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
// pop ram 3008      
@SP
AM=M-1
D=M
@3008
M=D
// call Sys.output 0      
@Sys.output.return.0
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
@Sys.output
0;JMP
(Sys.output.return.0)
// pop local 0      
@0
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
// push static 42      
@Test.42
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
// add        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
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
// push constant 3000      
@3000
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop static 42      
@Sys.42
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push static 42      
@Sys.42
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 1      
@1
D=A
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
// push constant 0      
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop that 0      
@0
D=A
@THAT
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push that 0      
@0
D=A
@THAT
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop that 1      
@1
D=A
@THAT
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// call Sys.output 0      
@Sys.output.return.1
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
@Sys.output
0;JMP
(Sys.output.return.1)
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
// push static 42      
@Sys.42
D=M
@SP
A=M
M=D
@SP
M=M+1
// call Test.test 1      
@Test.test.return.2
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
@Test.test
0;JMP
(Test.test.return.2)
// pop that 2      
@2
D=A
@THAT
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// call Sys.output 0      
@Sys.output.return.3
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
@Sys.output
0;JMP
(Sys.output.return.3)
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
// label TRAP       
(Sys.TRAP)
// goto TRAP       
@Sys.TRAP
0;JMP
// push temp 0      
@5
D=M
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
// function Sys.output 0      
(Sys.output)
// push static 42      
@Sys.42
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 1      
@1
D=A
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
// push that 0      
@0
D=A
@THAT
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 1      
@1
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
// pop that 0      
@0
D=A
@THAT
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push that 1      
@1
D=A
@THAT
A=D+M
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 1      
@1
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
// pop that 1      
@1
D=A
@THAT
D=D+M
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// push that 0      
@0
D=A
@THAT
A=D+M
D=M
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
