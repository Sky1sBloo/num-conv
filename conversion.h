#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <optional>

std::string decimalToBase(long double value, int base, int decimalPrecision = 8, bool isPrint = false);

std::string baseToDecimal(const std::string& value, int base, bool isPrint = false);

std::optional<std::string> binaryToBase(const std::string& value, int base, bool isPrint);
