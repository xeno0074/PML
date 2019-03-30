#include "interface.h"

int WIDTH = 12;

int main() {
	Interface::INTERFACE interface;
	interface.CmdInterface();
	/*
	std::cout << interface.CheckIdentifier("Z3rjfd35_") << std::endl;
	std::cout << interface.CheckIdentifier("_A3rjfd35_") << std::endl;
	std::cout << interface.CheckIdentifier("z2A3rjfd35_") << std::endl;
	std::cout << interface.CheckIdentifier("13rjfd35_") << std::endl;
	std::cout << interface.CheckIdentifier("a!3rjfd35_") << std::endl;
	std::cout << interface.CheckIdentifier("Z+3rjfd35_") << std::endl;
	std::cin.get();
	//*/
	return 0;
}