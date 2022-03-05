#pragma once
#include <iostream>
#include <fstream>

#define FDT_VERSION "1.0"

void help(const std::string executable)
{
	std::cout << "**--------- HELP ---------**\n";
	std::cout << "Usage: " << executable << " <file-one> <file-two...\n\n";
	std::cout << "At least two files must be passed as parameters so they can be compared\n";
}

std::string getline(std::ifstream& stream)
{
	std::string buffer;
	std::getline(stream, buffer);

	return buffer;
}
