#include <gtest/gtest.h>
#include "conversion.h"

// NOTE: When changing datatypes of "decValue" within decimalToBase() please update default values
TEST(CONVERSION_TESTS, DECIMAL_TO_BASE)
{
	// Binary test
	std::string intBinary = decimalToBase("123456789", 2);
	std::string decBinary = decimalToBase("0.123456789", 2);
	std::string decBinaryPrecision = decimalToBase("0.123456789", 2, 16);
	std::string realBin = decimalToBase("123456789.123456789", 2, 16);

	EXPECT_EQ(intBinary, "111010110111100110100010101");
	EXPECT_EQ(decBinary, "0.00011111");
	EXPECT_EQ(decBinaryPrecision, "0.0001111110011010");
	EXPECT_TRUE(realBin == "111010110111100110100010101.0001111110011010"); 


	// Octal test
	std::string intOctal = decimalToBase("123456789", 8);
	std::string decOctal = decimalToBase("0.123456789", 8);
	std::string decOctalPrecision = decimalToBase("0.123456789", 8, 16);
	std::string realOctal = decimalToBase("123456789.123456789", 8, 16);

	// PLEASE NOTE THAT THESE LAST 2 ARE NOT PRECISE
	EXPECT_EQ(intOctal, "726746425");
	EXPECT_EQ(decOctal, "0.07715334");
	EXPECT_EQ(decOctalPrecision, "0.0771533443734157");
	EXPECT_EQ(realOctal, "726746425.0771533443734157");

	std::string intHexadecimal = decimalToBase("123456789", 16);
	std::string decHexadecimal = decimalToBase("0.123456789", 16);
	std::string decHexadecimalPrecision = decimalToBase("0.123456789", 16, 16);
	std::string realHexadecimal = decimalToBase("123456789.123456", 16, 16);
	std::cout << realHexadecimal << std::endl;

	EXPECT_EQ(intHexadecimal, "75BCD15");
	EXPECT_EQ(decHexadecimal, "0.1F9ADD9C");
	EXPECT_EQ(decHexadecimalPrecision, "0.1F9ADD9C27E95315");
	EXPECT_EQ(realHexadecimal, "75BCD15.1F9ACFFA7EB6BF44");
}

TEST(CONVERSION_TESTS, BASE_TO_DECIMAL)
{
	// Binary test
	std::string intBinary = baseToDecimal("1001101011111", 2);
	std::string decBinary = baseToDecimal("0.111000010101", 2);
	std::string realBinary = baseToDecimal("1001101011111.111000010101", 2);

	EXPECT_EQ(intBinary, "4959"); 
	EXPECT_EQ(decBinary, "0.880127");
	EXPECT_EQ(realBinary, "4959.880127");
	
	// Octal test
	std::string intOctal = baseToDecimal("7654321", 8);
	std::string decOctal = baseToDecimal("0.7654321", 8);
	std::string realOctal = baseToDecimal("7654321.7654321", 8);

	EXPECT_EQ(intOctal, "2054353");	
	EXPECT_EQ(decOctal, "0.979592");
	EXPECT_EQ(realOctal, "2054353.979592");

	// Hexadecimal test
	std::string intHexadecimal = baseToDecimal("ABCDEF", 16);
	std::string decHexadecimal = baseToDecimal("0.123456789ABCDEF", 16);
	std::string realHexadecimal = baseToDecimal("ABCDEF.123456789ABCDEF", 16);
	
	EXPECT_EQ(intHexadecimal, "11259375");
	EXPECT_EQ(decHexadecimal, "0.071111");
	EXPECT_EQ(realHexadecimal, "11259375.071111");
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
