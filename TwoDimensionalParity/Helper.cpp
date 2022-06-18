#include "Helper.h"
#include <random>

size_t Helper::ConvertDecimalToBinary(size_t decimalNumber)
{
	size_t binaryNumber = 0, power = 1;

	while (decimalNumber)
	{
		binaryNumber += (decimalNumber % 2) * power;
		power *= 10;
		decimalNumber /= 2;
	}

	return binaryNumber;
}

size_t Helper::GetRandomNumberInRange(size_t inf, size_t sup)
{
	std::random_device dev;
	std::mt19937 generator(dev());
	std::uniform_int_distribution<std::mt19937::result_type> random(inf, sup);

	return random(generator);
}
