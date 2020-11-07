// push constant 17      
@17
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 17      
@17
D=A
@SP
M=M+1
A=M-1
M=D
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
// push constant 17      
@17
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 16      
@16
D=A
@SP
M=M+1
A=M-1
M=D
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
// push constant 16      
@16
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 17      
@17
D=A
@SP
M=M+1
A=M-1
M=D
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
// push constant 892      
@892
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 891      
@891
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
// push constant 891      
@891
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 892      
@892
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
@END_LT1
D;JLT
@SP
A=M
M=0
(END_LT1)
@SP
M=M+1
// push constant 891      
@891
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 891      
@891
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
@END_LT2
D;JLT
@SP
A=M
M=0
(END_LT2)
@SP
M=M+1
// push constant 32767      
@32767
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 32766      
@32766
D=A
@SP
M=M+1
A=M-1
M=D
// gt        
@SP
AM=M-1
D=M 
@SP
AM=M-1
D=M-D
M=-1
@END_GT0
D;JGT
@SP
A=M
M=0
(END_GT0)
@SP
M=M+1
// push constant 32766      
@32766
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 32767      
@32767
D=A
@SP
M=M+1
A=M-1
M=D
// gt        
@SP
AM=M-1
D=M 
@SP
AM=M-1
D=M-D
M=-1
@END_GT1
D;JGT
@SP
A=M
M=0
(END_GT1)
@SP
M=M+1
// push constant 32766      
@32766
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 32766      
@32766
D=A
@SP
M=M+1
A=M-1
M=D
// gt        
@SP
AM=M-1
D=M 
@SP
AM=M-1
D=M-D
M=-1
@END_GT2
D;JGT
@SP
A=M
M=0
(END_GT2)
@SP
M=M+1
// push constant 57      
@57
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 31      
@31
D=A
@SP
M=M+1
A=M-1
M=D
// push constant 53      
@53
D=A
@SP
M=M+1
A=M-1
M=D
// add        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
M=M+1
// push constant 112      
@112
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
// neg        
@SP
AM=M-1
M=-M
@SP
M=M+1
// and        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D&M
@SP
M=M+1
// push constant 82      
@82
D=A
@SP
M=M+1
A=M-1
M=D
// or        
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D|M
@SP
M=M+1
// not        
@SP
AM=M-1
M=!M
@SP
M=M+1
