#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>


void printSeparator()
{
	std::cout << "=======================================" << std::endl;
}

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
	std::cout << "Answer Int: " <<  answer << std::endl;


	// The ff code is for the decimal part of the value
	long double decimal = value - std::floor(value);
	
	std::string ansDecimal = "";
	int currentLoop = 0; // To prevent infinite looping on irrational numbers

	while (decimal != 0 && currentLoop < decimalPrecision)
	{
		long double newDecimal = decimal * base;
		char intAnswer;
		if (newDecimal >= 10)
			intAnswer = std::floor(newDecimal) + 'A' - 10;
		else
			intAnswer = std::floor(newDecimal) + '0';

		ansDecimal += intAnswer;
		std::cout << decimal << " * " << base << " = " << newDecimal << std::endl;
		decimal = newDecimal - std::floor(newDecimal);
		currentLoop++;
	}

	// Decimal part
	std::cout << "Answer Decimal: " << ansDecimal << std::endl;
	printSeparator();

	// Final answer
	std::cout << "Final Answer: " << answer << "." << ansDecimal << std::endl;
}

void baseToDecimal(long double value, int base)
{
	// For the integer part of value
	int intValue = std::floor(value);
	int intAns = 0;
	for (int digit = 0; digit < std::floor(std::log10(intValue)) + 1; digit++)
	{
		int digitValue = static_cast<int>(std::floor(intValue / std::pow(10, digit))) % 10;  // Returns the digit from intValue
		int digitAns = digitValue * static_cast<int>(std::pow(base, digit));

		intAns += digitAns;
		std::cout << digitValue << " * 10^" << digit << " = " << 
			digitAns << std::endl;
	}
	std::cout << "Answer Int: " << intAns << std::endl;

	// For the decimal part of value
	long double decValue = value - intValue;
	long double decAns = 0;


	if (decValue != 0)
	{
		std::string stringDecValue = std::to_string(decValue);
		stringDecValue.erase(0, 2);  // Removes the "0." from decimal
		
		
		int decLength = stringDecValue.length();
		for (int digit = 0; digit < decLength; digit++)
		{
			int digitValue =  stringDecValue[digit] - '0';
			long double digitAns = digitValue * std::pow(base, -(digit + 1));
			decAns += digitAns;

			std::cout << digitValue << " * 10^" << -(digit + 1) << " = " << digitAns << std::endl; 
		}

		// Since decAns currently appends to int convert it to decimal
		std::cout << "Answer Decimal: " << decAns << std::endl;
	}

	printSeparator();
	
	std::cout << "Final Answer: " << intAns + decAns << std::endl;
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
			std::cout << "-COMMANDS-\n" << 
			"	--dec2base [decimal] [base] -p [precision]\n" << 
			"		Converts a decimal to base, precision can be ommited (default 8)\n" <<
			"	--dec2base [decimal] [base]\n" <<
			"		Converts a decimal to base with set precision (default 8)\n" <<
			"	--base2dec [decimal] [base]\n" <<
			"		Converts a base to decimal" << std::endl;
		}
		else if (command == "--dec2base")
		{
			if (std::string(argv[i + 3]) == "-p")
			{
				decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]), std::stoi(argv[i + 4]));	
				i += 4;
			}
			else
			{
				decimalToBase(std::stold(argv[i + 1]), std::stoi(argv[i + 2]));	
				i +=2;
			}
		}
		else if (command == "--base2dec")
		{
			baseToDecimal(std::stold(argv[i + 1]), std::stoi(argv[i + 2]));
			i += 2;
		}
		else
		{
			std::cout << "num-conv: Invalid Command: Type --help to view commands" << std::endl;
			break;
		}
	}
}
