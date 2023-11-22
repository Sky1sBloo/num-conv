#include "conversion.h"


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

void decimalToBase(long double value, int base, int decimalPrecision)
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

void baseToDecimal(std::string& value, int base)
{
	// For the integer part of value
	std::string intValue = value;
	int intAns = 0;
	size_t decPos = value.find(".");
	if (decPos != std::string::npos)
		intValue = value.substr(0, decPos);

	std::reverse(intValue.begin(), intValue.end());
	for (int digit = 0; digit < static_cast<int>(intValue.length()); digit++)
	{
		int digitAns = (intValue[digit] - '0') * static_cast<int>(std::pow(base, digit));
		intAns += digitAns;

		std::cout << intValue[digit] << " * " << base << "^" << digit << " = " << digitAns << std::endl;
	}
	std::cout << "Answer Int: " << intAns << std::endl;

	// For decimal part of value
	long double decAns = 0;
	if (decPos != std::string::npos)
	{		
		long double decValue = std::stold(value.substr(decPos, value.length() - 1));
		std::cout << "Dec value = " << decValue << std::endl;
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
	
		
	}
	printSeparator();	
	std::cout << "Final Answer: " << std::to_string(decAns + intAns) << std::endl;
}
