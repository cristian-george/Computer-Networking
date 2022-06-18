#include "TwoDimensionalParity.h"

void TwoDimensionalParityOperations(TwoDimensionalParity& matrix)
{
	matrix.SetRowsParity();
	matrix.SetColumnsParity();
	std::cout << "Matrix after setting rows and columns parities:" << std::endl;
	std::cout << matrix << std::endl;

	matrix.Corruption();
	std::cout << "Matrix after one bit corruption: " << std::endl;
	std::cout << matrix << std::endl;

	auto position = matrix.GetCorruptedBit();
	std::cout << "Corrupted bit position: " << position.first << " " << position.second << std::endl;
}

int main()
{
	std::string message;
	std::cout << "Message to send: ";
	std::getline(std::cin, message);
	std::cout << std::endl;

	TwoDimensionalParity matrix(message);
	std::cout << "Initial matrix: " << std::endl;
	std::cout << matrix << std::endl;

	TwoDimensionalParityOperations(matrix);
	return 0;
}