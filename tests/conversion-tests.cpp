#include <gtest/gtest.h>
#include "conversion.h"

TEST(CONVERSION_TESTS, DECIMAL_TO_BASE)
{
	// Binary test
	std::string intBinary = decimalToBase(123456789, 2);
	std::string decBinary = decimalToBase(0.123456789, 2);
	std::string decBinaryPrecision = decimalToBase(0.123456789, 2, 16);
	std::string realBinary = decimalToBase(123456789.123456789, 2, 16);

	EXPECT_EQ(intBinary, "111010110111100110100010101");
	EXPECT_EQ(decBinary, "0.00011111");
	EXPECT_EQ(decBinaryPrecision, "0.0001111110011010");
	EXPECT_EQ(realBinary, "111010110111100110100010101.0001111110011010");

	// Octal test
	std::string intOctal = decimalToBase(123456789, 8);
	std::string decOctal = decimalToBase(0.123456789, 8);
	std::string decOctalPrecision = decimalToBase(0.123456789, 8, 16);
	std::string realOctal = decimalToBase(123456789.123456789, 8, 16);

	EXPECT_EQ(intOctal, "726746425");
	EXPECT_EQ(decOctal, "0.07715335");
	EXPECT_EQ(decOctalPrecision, "0.0771533515634543");
	EXPECT_EQ(realOctal, "726746425.0771533515634");

	// Hexadecimal test
	std::string intHexadecimal = decimalToBase(123456789, 16);
	std::string decHexadecimal = decimalToBase(0.123456789, 16);
	std::string decHexadecimalPrecision = decimalToBase(0.123456789, 16, 16);
	std::string realHexadecimal = decimalToBase(123456789.123456789, 16, 16);

	EXPECT_EQ(intHexadecimal, "75BCD15");
	EXPECT_EQ(decOctal, "0.1F9ADD37");
	EXPECT_EQ(decOctalPrecision, "0.1F9ADD3739635F31");
	EXPECT_EQ(realHexadecimal, "75BCD15.1F9ADD3738");
}

TEST(CONVERSION_TESTS, BASE_TO_DECIMAL)
{
	// Binary test
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
