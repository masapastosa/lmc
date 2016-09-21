#pragma once

const int MEM_SIZE = 100;

/*
HLT         halt the program
ADD [loc]   add  value at location to register value
SUB [loc]   subtract value at location from register value
STA [loc]   store register value at memory location
LDA [loc]   load value from memory to register
BRA [loc]   set pc to value
BRZ [loc]   set pc to value if register is 0
BRP [loc]   set pc to value if positive
INP         read input as byte to register
OUT         print register value as ascii
*/
enum op {
	HLT,
	ADD,
	SUB,
	STA,
	LDA,
	BRA,
	BRZ,
	BRP,
	INP = 901,
	OUT = 902
};

class CPU {
public:
	bool exec_op(int opcode);
private:
	int m_register         = 0;     // Register
	int m_memory[MEM_SIZE] = {};    // Memory array
	int m_pc               = 0;     // Program counter
	bool sf                = false; // Sign flag, positive is turned on for a positive OR a zero result
};
