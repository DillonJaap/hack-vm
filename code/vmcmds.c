// OPERATORS ASM
static char* bin_op_asm =
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@SP\n"
	"AM=M-1\n"
	"M=D%cM\n" // binary operator
	"@SP\n"
	"M=M+1\n";

static char* sub_asm =
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@SP\n"
	"AM=M-1\n"
	"M=M-D\n" // M-D instead of D-M like in bin_op_asm
	"@SP\n"
	"M=M+1\n";

static char* unary_op_asm =
	"@SP\n"
	"AM=M-1\n"
	"M=%cM\n"  // unary operator
	"@SP\n"
	"M=M+1\n";

static char* logic_op_asm =
	"@SP\n"
	"AM=M-1\n"
	"D=M \n"
	"@SP\n"
	"AM=M-1\n"
	"D=M-D\n"
	"M=-1\n"
	"@END_%s%d\n"
	"D;J%s\n"
	"@SP\n"
	"A=M\n"
	"M=0\n"
	"(END_%s%d)\n"
	"@SP\n"
	"M=M+1\n";

// PUSH ASM
// used by LCL ARG THIS THAT
// push the value pointed by the memory location + offset
static char* push_mem_asm = 
	"@%s\n" 
	"D=A\n"
	"@%s\n"
	"A=D+M\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n";

static char* push_mem_zero_asm =
	"@%s\n"
	"A=M\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n";
	
// used by POINTER STATIC
// PUSH the value, at the given memory location
static char* push_value_asm = 
	"@%s\n" 
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n";

// same as push_value, but print int instead of string
static char* push_temp_asm = 
	"@%d\n" 
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n";


static char* push_const_asm = 
	"@%s\n"
	"D=A\n" 
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n";


static char* push_zero_asm =
	"@SP\n"  // push zero onto stack
	"M=M+1\n"
	"A=M-1\n"
	"M=0\n";

static char* push_one_asm =
	"@SP\n"  // push zero onto stack
	"M=M+1\n"
	"A=M-1\n"
	"M=1\n";

// POP
// used by LCL ARG THIS THAT
// pop the value pointed by the memory location + offset
static char* pop_mem_asm =
	"@%s\n"    // offset
	"D=A\n"
	"@%s\n"    // label
	"D=D+M\n"
	"@R13\n"
	"M=D\n"
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@R13\n"
	"A=M\n"
	"M=D\n";

// used by POINTER STATIC
// pop the value, at the given memory location
static char* pop_value_asm =
	"@%s\n"
	"D=A\n"
	"@R13\n"
	"M=D\n"
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@R13\n"
	"A=M\n"
	"M=D\n";

// same as push_value, but print int instead of string
static char* pop_temp_asm =
	"@%d\n"
	"D=A\n"
	"@R13\n"
	"M=D\n"
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@R13\n"
	"A=M\n"
	"M=D\n";


static char* pop_const_asm =
	"@SP\n"
	"AM=M-1\n";

static char* label_asm =
	"(%s)\n";

static char* goto_asm =
	"@%s\n" // label to jump to
	"0;JMP\n";

static char* if_goto_asm =
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@%s\n" // label
	"D;JNE\n";

/*
static char* return_asm =
	//store LCL
	"@LCL\n"
	"D=M\n"
	"@R14\n" // end frame
	"M=D\n"

	// Repostions the return value for the caller
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@ARG\n"
	"A=M\n"
	"M=D\n"

	// Repositions SP of the caller
	"@ARG\n"
	"D=M+1\n"
	"@SP\n"
	"M=D\n"

	// Restores THAT of the caller
	"@R14\n"
	"AM=M-1\n"
	"D=M\n"
	"@THAT\n"
	"M=D\n"

	// Restores THIS of the caller
	"@R14\n"
	"AM=M-1\n"
	"D=M\n"
	"@THIS\n"
	"M=D\n"

	// Restores ARG of the caller
	"@R14\n"
	"AM=M-1\n"
	"D=M\n"
	"@ARG\n"
	"M=D\n"

	// Restores LCL of the caller
	"@R14\n"
	"AM=M-1\n"
	"D=M\n"
	"@LCL\n"
	"M=D\n"

	// gets return address
	"@R14\n"
	"AM=M-1\n"
	"A=M\n"
	// goes to return address n the caller's mode
	"0;JMP\n";
*/

// found from here: 
// https://github.com/kronosapiens/nand2tetris/blob/master/projects/07/VMtranslator.py
static char* return_asm =
	"@LCL\n"
	"D=M\n"
	"@R13\n"
	"M=D\n"
	"@R13\n"
	"D=M\n"
	"@5\n"
	"AD=D-A\n"
	"D=M\n"
	"@R14\n"
	"M=D\n"
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@ARG\n"
	"A=M\n"
	"M=D\n"
	"@ARG\n"
	"D=M\n"
	"@SP\n"
	"M=D+1\n"
	"@R13\n"
	"D=M\n"
	"@1\n"
	"AD=D-A\n"
	"D=M\n"
	"@THAT\n"
	"M=D\n"
	"@R13\n"
	"D=M\n"
	"@2\n"
	"AD=D-A\n"
	"D=M\n"
	"@THIS\n"
	"M=D\n"
	"@R13\n"
	"D=M\n"
	"@3\n"
	"AD=D-A\n"
	"D=M\n"
	"@ARG\n"
	"M=D\n"
	"@R13\n"
	"D=M\n"
	"@4\n"
	"AD=D-A\n"
	"D=M\n"
	"@LCL\n"
	"M=D\n"
	"@R14\n"
	"A=M\n"
	"0;JMP\n";

// Instead of pasting this code every time just jump to it to return
static char* generic_return_asm =
	"(...GENERIC_RETURN...)\n"
	"@LCL\n"
	"D=M\n"
	"@R13\n"
	"M=D\n"
	"@R13\n"
	"D=M\n"
	"@5\n"
	"AD=D-A\n"
	"D=M\n"
	"@R14\n"
	"M=D\n"
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@ARG\n"
	"A=M\n"
	"M=D\n"
	"@ARG\n"
	"D=M\n"
	"@SP\n"
	"M=D+1\n"
	"@R13\n"
	"D=M\n"
	"@1\n"
	"AD=D-A\n"
	"D=M\n"
	"@THAT\n"
	"M=D\n"
	"@R13\n"
	"D=M\n"
	"@2\n"
	"AD=D-A\n"
	"D=M\n"
	"@THIS\n"
	"M=D\n"
	"@R13\n"
	"D=M\n"
	"@3\n"
	"AD=D-A\n"
	"D=M\n"
	"@ARG\n"
	"M=D\n"
	"@R13\n"
	"D=M\n"
	"@4\n"
	"AD=D-A\n"
	"D=M\n"
	"@LCL\n"
	"M=D\n"
	"@R14\n"
	"A=M\n"
	"0;JMP\n";

static char* call_asm =
	// push return address
	"@%s\n" // return address 
	"D=A\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// push LCL
	"@LCL\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// push ARG
	"@ARG\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// push THIS
	"@THIS\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// push THAT
	"@THAT\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// Repositions ARG
	"@%s\n" // nArgs
	"D=A\n"
	"@5\n"
	"D=D+A\n"
	"@SP\n"
	"D=M-D\n" // SP - 5 - nArgs
	"@ARG\n"
	"M=D\n"

	// Repositions LCL
	"@SP\n"
	"D=M\n"
	"@LCL\n"
	"M=D\n"

	// transfers control to the called function
	"@%s\n" // function name
	"0;JMP\n"
	// declares a label for the return address
	"(%s)\n"; // return address

// ****************************
// GENERIC CALL
// ****************************
static char* function_header_asm =
	// push return address
	"@R13\n" // return address 
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// push LCL
	"@LCL\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// push ARG
	"@ARG\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// push THIS
	"@THIS\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// push THAT
	"@THAT\n"
	"D=M\n"
	"@SP\n"
	"M=M+1\n"
	"A=M-1\n"
	"M=D\n"

	// Repositions ARG
	"@R14\n" // nArgs
	"D=M\n"
	"@5\n"
	"D=D+A\n"
	"@SP\n"
	"D=M-D\n" // SP - 5 - nArgs
	"@ARG\n"
	"M=D\n"

	// Repositions LCL
	"@SP\n"
	"D=M\n"
	"@LCL\n"
	"M=D\n";

static char* generic_call_asm =
	// transfers control to the called function
	"@%s\n" // return address
	"D=A\n"
	"@R13\n"
	"M=D\n" 
	"@%s\n" // nArgs
	"D=A\n"
	"@R14\n"
	"M=D\n" 
	"@%s\n" // function name
	"0;JMP\n"
	// declares a label for the return address
	"(%s)\n"; // return address

static char* boot_asm = 
	"@256\n"
	"D=A\n"
	"@SP\n"
	"M=D\n"
	"@Sys.init0\n"
	"D=A\n"
	"@SP\n"
	"A=M\n"
	"M=D\n"
	"@SP\n"
	"M=M+1\n"
	"@LCL\n"
	"D=M\n"
	"@SP\n"
	"A=M\n"
	"M=D\n"
	"@SP\n"
	"M=M+1\n"
	"@ARG\n"
	"D=M\n"
	"@SP\n"
	"A=M\n"
	"M=D\n"
	"@SP\n"
	"M=M+1\n"
	"@THIS\n"
	"D=M\n"
	"@SP\n"
	"A=M\n"
	"M=D\n"
	"@SP\n"
	"M=M+1\n"
	"@THAT\n"
	"D=M\n"
	"@SP\n"
	"A=M\n"
	"M=D\n"
	"@SP\n"
	"M=M+1\n"
	"@SP\n"
	"D=M\n"
	"@5\n"
	"D=A\n"
	"@0\n"
	"D=D+A\n"
	"@SP\n"
	"D=M-D\n"
	"@ARG\n"
	"M=D\n"
	"@SP\n"
	"D=M\n"
	"@LCL\n"
	"M=D\n"
	"@Sys.init\n"
	"0;JMP\n"
	"(Sys.init0)\n";
