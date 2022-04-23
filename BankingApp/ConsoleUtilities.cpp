#include "ConsoleUtilities.h"
#include <iostream>
#include <Windows.h>

void Console::clear() {
	system("cls");
}

void Console::log(const char* message) {
	std::cout << "INFO -> " << message<< '\n';
}