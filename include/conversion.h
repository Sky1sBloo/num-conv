#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <optional>

/**
 * Converts a specified decimal to base
 *
 * @param value Decimal to be converted
 * @param base Resulting value will be converted to the specified base
 * @param decimalPrecision Sets the maximum precision the conversion will perform
 * @param isPrint Function will print all its processed steps if isPrint is true
 *
 * @returns The converted value
 */
std::string decimalToBase(long double value, int base, int decimalPrecision = 8, bool isPrint = false);


std::string decimalToBase(const std::string& value, int base, int decimalPrecision = 8, bool isPrint = false);

/**
 * Converts a specified base to decimal
 *
 * @param value Base value to be converted
 * @param base The current base of value
 * @param isPrint Function will print its processed steps if isPrint is true
 *
 * @returms The decimal version of value
 */
std::string baseToDecimal(const std::string& value, int base, bool isPrint = false);

/**
 * Converts a binary to the specified base
 *
 * @param value Binary value to be converted
 * @param base The base value output
 * @param isPrint Function will print its processed steps if isPrint is true
 *
 * @returns The converted value of binary
 */
std::optional<std::string> binaryToBase(const std::string& value, int base, bool isPrint = false);

/**
 * Converts a specified base to binary
 *
 * @param value Base value to be converted to binary
 * @param base The current base of value
 * @param isPrint Function will print its processed steps if isPrint is true
 */

std::optional<std::string> baseToBinary(const std::string& value, int base, bool isPrint = false);
