#pragma once
#include <iostream>
#include <string>
#include <vector>

class Helper
{
public:
	Helper() = default;

	static bool ContainsOnlyBits(const std::string& message);
	static bool VerifyInput(const std::string& message, const std::string& polynomialCoefficients);
	static void PrintVector(std::ostream& out, const std::vector<bool> vect);

	static std::vector<bool> ConvertStringToVector(const std::string& str);
	static std::vector<bool> RemoveRedundantZeros(const std::vector<bool>& vect);
};