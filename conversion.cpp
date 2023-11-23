#include "conversion.h"


// Used for printing commands dependent on the --print flag
void printProcess(const std::string& value, bool isPrint, bool endln = true)
{
	if (!isPrint) return;
	std::cout << value;

	if (endln)
		std::cout << std::endl;
}

void printSeparator(bool isPrint)
{
	printProcess("====================================", isPrint);
}


// Helper function for decimalToBase (do not call directly)
void printDecimalEq(int& prevQuotient, int& base, std::string& answer, bool isPrint)
{
	printProcess(std::to_string(base) + "|" + std::to_string(prevQuotient) + " - ", isPrint, false);

	int remainder = prevQuotient % base;
	std::string remainderStr = std::to_string(remainder);

	// Used for handling the characters of remainders above 9
	if (remainder >= 10) {
		remainderStr = remainder - 10 + 'A';
	}
	answer += remainderStr;

	prevQuotient = std::floor(prevQuotient / base);
	printProcess(remainderStr, isPrint);
}

void decimalToBase(long double value, int base, int decimalPrecision, bool isPrint)
{
	// The following code is for the integer part of the value
	int prevQuotient = std::floor(value);
	std::string answer = "";
	while (prevQuotient >= base)
	{
		printDecimalEq(prevQuotient, base, answer, isPrint);
	}
	printDecimalEq(prevQuotient, base, answer, isPrint);

	// Reverse to get the correct answer
	std::reverse(answer.begin(), answer.end());
	printProcess("Answer Int: " + answer, isPrint);


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

		printProcess(std::to_string(decimal) + " * " + std::to_string(base) + " = " + 
			std::to_string(newDecimal), isPrint);

		decimal = newDecimal - std::floor(newDecimal);
		currentLoop++;
	}

	// Decimal part
	printProcess("Answer Decimal: " + ansDecimal, isPrint);

	printSeparator(isPrint);
	// Final answer
	std::cout << answer << "." << ansDecimal << std::endl;
}

void baseToDecimal(const std::string& value, int base, bool isPrint)
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

		printProcess(std::to_string(intValue[digit]) + " * " + std::to_string(base) + "^" + 
			std::to_string(digit) + " = " + std::to_string(digitAns), isPrint);
	}
	printProcess("Answer Int: " + std::to_string(intAns), isPrint);

	// For decimal part of value
	long double decAns = 0;
	if (decPos != std::string::npos)
	{		
		long double decValue = std::stold(value.substr(decPos, value.length() - 1));
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
	
				printProcess(std::to_string(digitValue) + " * 10^" + std::to_string(-(digit + 1)) + 
					" = " + std::to_string(digitAns), isPrint);
			}

			// Since decAns currently appends to int convert it to decimal
			printProcess("Answer Decimal: " + std::to_string(decAns), isPrint);
		}
	
		
	}
	printSeparator(isPrint);
	std::cout << std::to_string(decAns + intAns) << std::endl;
}

