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

	bool isPrint = false;

	for(int i = 1; i < argc; i++)
	{
		std::string command = argv[i];
		if (command == "--help")
		{
			std::cout << "num-conv: COMMANDS\n" << 
			"	--print [conversion] ...\n" <<
			"		A modifier of printing the operations during the conversion processes \n" <<
			"	--dec2base [decimal] [base]\n" <<
			"		Converts a decimal to base with precision 8\n" <<
			"	--dec2base [decimal] [base] -p [precision]\n" << 
			"		Converts a decimal to base with set precision\n" <<
			"	--base2dec [value] [base]\n" <<
			"		Converts a base to decimal" << std::endl;
		}
		else if (command == "--print")
		{
			isPrint = true;	
		}
		else if (command == "--dec2base")
		{
			try
			{
				if (argv[i + 3] != nullptr && argv[i + 3] ==std::string("-p"))
				{
					if (argv[i + 1] == nullptr || argv[i + 2] == nullptr || argv[i + 4] == nullptr)
						throw std::invalid_argument("");
					decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]), std::stoi(argv[i + 4]), isPrint);	
					i += 4;
				}
				else
				{
					if (argv[i + 1] == nullptr || argv[i + 2] == nullptr)
						throw std::invalid_argument("");
					decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]), 8, isPrint);	
					i += 2;
				}
			}
			catch (std::invalid_argument& e)
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
				baseToDecimal(value, std::stoi(argv[i + 2]), isPrint);
				i += 2;
			}
			catch (std::invalid_argument& arg)
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
