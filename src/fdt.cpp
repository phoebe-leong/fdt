#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "fdt.hpp"

int main(int charc, char** charv)
{
	if (charc == 1 || std::string(charv[1]) == "--help")
	{
		help(charv[0]);
		exit(0);
	}
	else if (std::string(charv[1]) == "--version")
	{
		std::cout << "Current Version: " << FDT_VERSION << "\n";
		exit(0);
	}

	// Checking that the filenames aren't the same
	for (int i = 1; i < charc; i++)
	{
		if (charv[i] != charv[1])
		{
			break;
		}
		else if (i == charc - 1)
		{
			std::cout << "Your files are the same!\n";
			exit(0);
		}
	}

	// This vector will store the first file's contents which all preceding files will be compared to
	std::vector<std::string> first;

	std::ifstream file(charv[1]);
	while (!file.eof()) first.push_back(getline(file));

	file.close();

	for (int i = 2; i < charc; i++)
	{
		file.open(charv[i]);

		for (int i = 0; !file.eof(); i++)
		{
			std::string line = getline(file);
			if (line != first[i] || (i == first.size() - 1 && !file.eof()) || (file.eof() && i != first.size() - 1))
			{
				std::cout << "Your files are not the same!\n";

				file.close();
				exit(0);
			}
		}
		file.close();
	}

	std::cout << "Your files are the same!\n";
}
