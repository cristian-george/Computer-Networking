#pragma once
#include <vector>
#include <string>

class CyclicRedundancyCheck
{
public:
	CyclicRedundancyCheck(const std::string& message, const std::string& polynomialCoefficients);

	std::vector<bool> FindRemainder();
	void ComputeFinalMessage();

	void PrintInitialMessage();
	void PrintGeneratorPolynomial();
	void PrintFinalMessage();

private:
	void InitCRC(const std::string& message, const std::string& polynomialCoefficients);

private:
	std::vector<bool> initialMessage;
	std::vector<bool> finalMessage;
	std::vector<bool> generatorPolynomial;
};