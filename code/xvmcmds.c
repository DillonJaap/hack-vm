static char* push_ram_asm = 
	"@%s\n"
	"D=M\n" // %c is M if ram, A if const
	"@SP\n"
	"A=M\n"
	"M=D\n"
	"@SP\n"
	"M=M+1\n";

static char* pop_ram_asm =
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@%s\n" // specified ram address
	"M=D\n";

static char* bool_asm = 
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@END_BOOL%d\n"
	"D;JEQ\n"
	"@SP\n"
	"A=M\n"
	"M=-1\n"
	"(END_BOOL%d)\n"
	"@SP\n"
	"M=M+1\n";

static char* l_not_asm = 
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	// premtively set to -1
	"@SP\n"
	"A=M\n"
	"M=-1\n"
	// if
	"@END_LNOT%d\n"
	"D;JEQ\n"
	"@SP\n"
	"A=M\n"
	"M=0\n"
	// end if
	"(END_LNOT%d)\n"
	"@SP\n"
	"M=M+1\n";

static char* l_and_asm = 
	// pop first value
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@R13\n"
	"M=D\n"
	// pop second value
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@R14\n"
	"M=D\n"

	// premtively set to 0
	"@SP\n"
	"A=M\n"
	"M=0\n"

	// if
	"@R13\n"
	"D=M\n"
	"@END_LAND%d\n"
	"D;JEQ\n"
	"@R14\n"
	"D=M\n"
	"@END_LAND%d\n"
	"D;JEQ\n"
	// set to -1
	"@SP\n"
	"A=M\n"
	"M=-1\n"
	//end if
	"(END_LAND%d)\n"
	"@SP\n"
	"M=M+1\n";

static char* l_or_asm = 
	// pop first value
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@R13\n"
	"M=D\n"
	// pop second value
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@R14\n"
	"M=D\n"

	// premtively set to -1
	"@SP\n"
	"A=M\n"
	"M=-1\n"

	// if
	"@R13\n"
	"D=M\n"
	"@END_LOR%d\n"
	"D;JNE\n"
	"@R14\n"
	"D=M\n"
	"@END_LOR%d\n"
	"D;JNE\n"
	// set to 0
	"@SP\n"
	"A=M\n"
	"M=0\n"
	//end if
	"(END_LOR%d)\n"
	"@SP\n"
	"M=M+1\n";
/*
static char* l_xor_asm = 
	// pop first item and bool it
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@XOR_BOOL_A%d\n"
	"D;JEQ\n"
	"@R13\n"
	"M=-1\n"
	"(XOR_BOOL_A%d)\n"

	// pop second item and bool it
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@XOR_BOOL_B%d\n"
	"D;JEQ\n"
	"@R14\n"
	"M=-1\n"
	"(XOR_BOOL_B%d)\n"

	// premtively set to -1
	"@SP\n"
	"A=M\n"
	"M=-1\n"

	// add items to compare
	"@R13\n"
	"D=M\n"
	"@R14\n"
	"D=D+M\n"
	"D=D+1\n"

	// if
	"@END_LXOR%d\n"
	"D;JEQ\n"
	// set to 0
	"@SP\n"
	"A=M\n"
	"M=0\n"

	// end if
	"(END_LXOR%d)\n"
	"@SP\n"
	"M=M+1\n";
	*/

static char* l_xor_asm =
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@L_XOR_FRSTTRUE_%d\n"
	"D;JNE\n"
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@L_XOR_FRSTFALSE_SCNDTRUE_%d\n"
	"D;JNE\n"
	"@SP\n"
	"A=M\n"
	"M=0\n"
	"@L_XOR_CONT_%d\n"
	"0;JMP\n"
	"(L_XOR_FRSTTRUE_%d)\n"
	"@SP\n"
	"AM=M-1\n"
	"D=M\n"
	"@L_XOR_SECONDTRUE_%d\n"
	"D;JNE\n"
	"@SP\n"
	"A=M\n"
	"M=-1\n"
	"@L_XOR_CONT_%d\n"
	"0;JMP\n"
	"(L_XOR_SECONDTRUE_%d)\n"
	"@SP\n"
	"A=M\n"
	"M=0\n"
	"@L_XOR_CONT_%d\n"
	"0;JMP\n"
	"(L_XOR_FRSTFALSE_SCNDTRUE_%d)\n"
	"@SP\n"
	"A=M\n"
	"M=-1\n"
	"(L_XOR_CONT_%d)\n"
	"@SP\n"
	"M=M+1\n";
