#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>


// Helper function for decimalToBase (do not call directly)
void printDecimalEq(int& prevQuotient, int& base, std::string& answer)
{
	std::cout << base << "|" <<prevQuotient << "  ";

	int remainder = prevQuotient % base;
	std::string remainderStr = std::to_string(remainder);

	// Used for handling the characters of remainders above 9
	if (remainder >= 10) {
		remainderStr = remainder - 10 + 'A';
	}
	answer += remainderStr;

	prevQuotient = std::floor(prevQuotient / base);
	std::cout << remainderStr;
	std::cout << std::endl;
}

void decimalToBase(long double value, int base, int decimalPrecision = 8)
{
	// The following code is for the integer part of the value
	int prevQuotient = std::floor(value);
	std::string answer = "";
	while (prevQuotient >= base)
	{
		printDecimalEq(prevQuotient, base, answer);
	}
	printDecimalEq(prevQuotient, base, answer);

	// Reverse to get the correct answer
	std::reverse(answer.begin(), answer.end());
	std::cout << answer << std::endl;

	// The ff code is for the decimal part of the value
	long double decimal = value - std::floor(value);
	
	std::string ansDecimal = "";
	int currentLoop = 0; // To prevent infinite looping on irrational numbers

	while (decimal != 0 && currentLoop < 8)
	{
		long double newDecimal = decimal * base;
		ansDecimal += std::to_string((int)std::floor(newDecimal));
		std::cout << decimal << " * " << base << " = " << newDecimal << std::endl;
		decimal = newDecimal - std::floor(newDecimal);
		currentLoop++;
	}

	// Decimal part
	std::cout << ansDecimal << std::endl;

	// Final answer
	std::cout << answer << "." << ansDecimal << std::endl;
}

int main(int argc, char* argv[])
{
	for(int i = 0; i < argc; i++)
	{
		std::string command = argv[i];
		if (command == "--help")
		{
			std::cout << "-COMMANDS-\n" << 
			"--decimalToBase [decimal] [base] -precision [precision] " << 
			"| Converts a decimal to base, -precision can be ommited (default 8)\n";

		}
		else if (command == "--decimalToBase")
		{
			if (argv[i + 3] == "-precision")
			{
				decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]), std::stoi(argv[i + 4]));	
				i+= 4;
			}
			else
			{
				decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]));	
			}
			break;
		}
	}
}
