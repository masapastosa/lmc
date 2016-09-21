#include <iostream>
#include <fstream>
#include "cpu.h"

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


int decode_instruction(std::string inst) {
	//TODO: Check if ADD, SUB... Have an argument
	std::size_t space_pos = inst.find(" ");
	std::string operation = inst.substr(0, 3);
	int opcode = -1;
	//Switch case and strings are not friends :)
	if (operation == "ADD") {
		opcode = ADD * 100 + std::stoi(inst.substr(space_pos));
	} else if (operation == "SUB") {
		opcode = SUB * 100 + std::stoi(inst.substr(space_pos));
	} else if (operation == "STA") {
		opcode = STA * 100 + std::stoi(inst.substr(space_pos));
	} else if (operation == "LDA") {
		opcode = LDA * 100 + std::stoi(inst.substr(space_pos));
	} else if (operation == "BRA") {
		opcode = BRA * 100 + std::stoi(inst.substr(space_pos));
	} else if (operation == "BRZ") {
		opcode = BRZ * 100 + std::stoi(inst.substr(space_pos));
	} else if (operation == "BRP") {
		opcode = BRP * 100 + std::stoi(inst.substr(space_pos));
	} else if (operation == "INP") {
		opcode = INP;
	} else if (operation == "INP") {
		opcode = OUT;
	} else if (operation == "HLT") {
		opcode = HLT;
	} 
	return opcode;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: ./lmc program" << std::endl;
		exit(1);
	}

	CPU cpu;
	std::ifstream file(argv[1]);
	if (!file) {
		std::cout << "Error opening the file" << std::endl;
	}

	int opcode;
	while(!file.eof() && opcode != HLT) {
		std::string instruction;

		getline(file, instruction);
		opcode = decode_instruction(instruction);
		if (opcode != -1) {

		}
	}
}
