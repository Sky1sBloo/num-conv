#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

void printDecimalEq(int& prevQuotient, int& base, std::string& answer, bool isPrint = false);

void decimalToBase(long double value, int base, int decimalPrecision = 8, bool isPrint = false);

void baseToDecimal(const std::string& value, int base, bool isPrint = false);
