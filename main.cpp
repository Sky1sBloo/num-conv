#include <iostream>
#include "conversion.h"


void printInvalidInput()
{
	std::cout << "num-conv: Invalid Command: Type --help to view commands" << std::endl;
}


int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "num-conv: Type --help to view commands" << std::endl;
	}

	for(int i = 1; i < argc; i++)
	{
		std::string command = argv[i];
		if (command == "--help")
		{
			std::cout << "num-conv: COMMANDS\n" << 
			"	--dec2base [decimal] [base]\n" <<
			"		Converts a decimal to base with precision 8\n" <<
			"	--dec2base [decimal] [base] -p [precision]\n" << 
			"		Converts a decimal to base with set precision\n" <<
			"	--base2dec [value] [base]\n" <<
			"		Converts a base to decimal" << std::endl;
		}
		else if (command == "--dec2base")
		{
			try
			{
				if (std::string(argv[i + 3]) == "-p")
				{
					decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]), std::stoi(argv[i + 4]));	
					i += 4;
				}
				else
				{
					decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]));	
					i += 2;
				}
			}
			catch (...)
			{
				printInvalidInput();
				break;
			}
		}
		else if (command == "--base2dec")
		{
			try
			{
				std::string value = argv[i + 1];
				baseToDecimal(value, std::stoi(argv[i + 2]));
				i += 2;
			}
			catch (...)
			{
				printInvalidInput();
				break;
			}
		}
		else
		{
			printInvalidInput();
			break;
		}
	}
}
