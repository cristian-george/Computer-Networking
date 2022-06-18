#include "CyclicRedundancyCheck.h"
#include "Helper.h"

int main()
{
	std::string message, polynomialCoefficients;
	std::cout << "Initial message: ";
	std::getline(std::cin, message);

	std::cout << "Generator polynomial: ";
	std::getline(std::cin, polynomialCoefficients);
	std::cout << std::endl;

	if (Helper::VerifyInput(message, polynomialCoefficients))
	{
		CyclicRedundancyCheck CRC(message, polynomialCoefficients);
		CRC.PrintInitialMessage();
		CRC.PrintGeneratorPolynomial();

		CRC.ComputeFinalMessage();
		CRC.PrintFinalMessage();
	}
	return 0;
}