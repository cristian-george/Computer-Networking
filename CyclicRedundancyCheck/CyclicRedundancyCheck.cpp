#include "CyclicRedundancyCheck.h"
#include "Helper.h"

CyclicRedundancyCheck::CyclicRedundancyCheck(const std::string& message, const std::string& polynomialCoefficients)
{
	InitCRC(message, polynomialCoefficients);
}

std::vector<bool> CyclicRedundancyCheck::FindRemainder()
{
	std::vector<bool> intermediateMessage = initialMessage;

	std::cout << "\nIntermediate steps: \n";
	while (intermediateMessage.size() >= generatorPolynomial.size())
	{
		for (size_t index = 0; index < generatorPolynomial.size(); ++index)
			intermediateMessage[index] = intermediateMessage[index] ^ generatorPolynomial[index];

		intermediateMessage = Helper::RemoveRedundantZeros(intermediateMessage);
		if (intermediateMessage.empty())
		{
			intermediateMessage.push_back(0);
			Helper::PrintVector(std::cout, intermediateMessage);
			break;
		}

		Helper::PrintVector(std::cout, intermediateMessage);
	}

	return intermediateMessage;
}

void CyclicRedundancyCheck::ComputeFinalMessage()
{
	std::vector<bool> intermediateMessage = FindRemainder();

	finalMessage = initialMessage;

	for (size_t index = initialMessage.size() - intermediateMessage.size(); index < initialMessage.size(); ++index)
		finalMessage[index] = initialMessage[index] ^ intermediateMessage[initialMessage.size() - index - 1];
}

void CyclicRedundancyCheck::PrintInitialMessage()
{
	std::cout << "Initial extended message: ";
	Helper::PrintVector(std::cout, initialMessage);
}

void CyclicRedundancyCheck::PrintGeneratorPolynomial()
{
	std::cout << "Generator polynomial: ";
	Helper::PrintVector(std::cout, generatorPolynomial);
}

void CyclicRedundancyCheck::PrintFinalMessage()
{
	std::cout << "Final extended message: ";
	Helper::PrintVector(std::cout, finalMessage);
}

void CyclicRedundancyCheck::InitCRC(const std::string& message, const std::string& polynomialCoefficients)
{
	initialMessage = Helper::ConvertStringToVector(message);
	generatorPolynomial = Helper::ConvertStringToVector(polynomialCoefficients);

	for (size_t index = 0; index < generatorPolynomial.size() - 1; ++index)
		initialMessage.push_back(0);
}
