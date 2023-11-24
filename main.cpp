#include <iostream>
#include "conversion.h"


void printInvalidInput(const std::string& errorMessage = "")
{
	if (errorMessage == "")
		std::cout << "num-conv: Invalid Command: Type --help to view commands" << std::endl;
	else
		std::cout << "num-conv: " + errorMessage << std::endl;
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
			"		Converts a base to decimal\n" <<
			"	--binary2base [value] [base]\n" << 
			"		Does a direct conversion from binary to the specified base" << std::endl;
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
					std::cout << decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]), std::stoi(argv[i + 4]), isPrint) << std::endl;	
					i += 4;
				}
				else
				{
					if (argv[i + 1] == nullptr || argv[i + 2] == nullptr)
						throw std::invalid_argument("");
					std::cout << std::string(decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]), 8, isPrint)) << std::endl;	
					i += 2;
				}
			}
			catch (std::invalid_argument& e)
			{
				printInvalidInput();
				return 1;
			}
		}
		else if (command == "--base2dec")
		{
			try
			{
				std::string value = argv[i + 1];
				std::cout << baseToDecimal(value, std::stoi(argv[i + 2]), isPrint) << std::endl;
				i += 2;
			}
			catch (std::invalid_argument& arg)
			{
				printInvalidInput();
				return 1;
			}
		}
		else if (command == "--binary2base")
		{
			try
			{
				if (argv[i + 1] == nullptr || argv[i + 2] == nullptr)
					throw std::invalid_argument("");


				std::string value = argv[i + 1];
				std::optional<std::string> answer = binaryToBase(value, std::stoi(argv[i + 2]), isPrint);

				if (!answer.has_value())
					throw std::invalid_argument("Invalid base argument to direct conversion");

				std::cout << answer.value() << std::endl;
				i += 2;
			}
			catch (std::invalid_argument& e)
			{
				printInvalidInput(e.what());
				return 1;
			}
		}
		else
		{
			printInvalidInput();
			return 1;
		}
	}

	return 0;
}
