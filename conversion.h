#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

void printDecimalEq(int& prevQuotient, int& base, std::string& answer);

void decimalToBase(long double value, int base, int decimalPrecision = 8);

void baseToDecimal(std::string& value, int base);
