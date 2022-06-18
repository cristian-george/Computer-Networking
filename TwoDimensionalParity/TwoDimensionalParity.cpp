#include "TwoDimensionalParity.h"
#include "Helper.h"

TwoDimensionalParity::TwoDimensionalParity(const std::string& message)
{
	InitParityMatrix(message);
}

void TwoDimensionalParity::SetRowsParity()
{
	for (size_t row = 0; row < parityMatrix.size(); ++row)
	{
		SetRowParity(row);
	}
}

void TwoDimensionalParity::SetColumnsParity()
{
	std::vector<bool> lastRow;
	for (size_t column = 0; column < parityMatrix[0].size(); ++column)
	{
		SetColumnParity(column, lastRow);
	}

	parityMatrix.push_back(lastRow);
}

void TwoDimensionalParity::Corruption()
{
	size_t randomRow = Helper::GetRandomNumberInRange(0, parityMatrix.size() - 2);
	size_t randomColumn = Helper::GetRandomNumberInRange(0, parityMatrix[0].size() - 2);

	std::cout << "Generated corrupted bit at position: " << randomRow << " " << randomColumn << std::endl;
	parityMatrix[randomRow][randomColumn] = !parityMatrix[randomRow][randomColumn];
}

std::pair<size_t, size_t> TwoDimensionalParity::GetCorruptedBit()
{
	size_t corruptedRow, corruptedColumn;

	for (size_t row = 0; row < parityMatrix.size() - 1; ++row)
	{
		if (GetRowParity(row, parityMatrix[row].size() - 1) != parityMatrix[row][parityMatrix[row].size() - 1])
		{
			corruptedRow = row;
			break;
		}
	}

	for (size_t column = 0; column < parityMatrix[0].size() - 1; ++column)
	{
		if (GetColumnParity(column, parityMatrix.size() - 1) != parityMatrix[parityMatrix.size() - 1][column])
		{
			corruptedColumn = column;
			break;
		}
	}

	return std::pair<size_t, size_t>(corruptedRow, corruptedColumn);
}


void TwoDimensionalParity::InitParityMatrix(const std::string& message)
{
	const std::vector<bool> initRow = { 0, 0, 0, 0, 0, 0, 0 };

	parityMatrix.resize(message.length());

	for (size_t index = 0; index < message.length(); ++index)
	{
		parityMatrix[index] = initRow;

		size_t binaryNumber = Helper::ConvertDecimalToBinary(message[index]), counter = 0;
		while (binaryNumber)
		{
			parityMatrix[index][initRow.size() - counter - 1] = binaryNumber % 10;
			binaryNumber /= 10;
			++counter;
		}
	}
}

void TwoDimensionalParity::SetRowParity(size_t row)
{
	bool parity = GetRowParity(row, parityMatrix[row].size());
	parityMatrix[row].push_back(parity);
}

void TwoDimensionalParity::SetColumnParity(size_t column, std::vector<bool>& lastRow)
{
	bool parity = GetColumnParity(column, parityMatrix.size());
	lastRow.push_back(parity);
}

bool TwoDimensionalParity::GetRowParity(size_t row, size_t rowSize)
{
	bool parity = parityMatrix[row][0];

	for (size_t column = 1; column < rowSize; ++column)
		parity ^= parityMatrix[row][column];

	return parity;
}

bool TwoDimensionalParity::GetColumnParity(size_t column, size_t columnSize)
{
	bool parity = parityMatrix[0][column];

	for (size_t row = 1; row < columnSize; ++row)
		parity ^= parityMatrix[row][column];

	return parity;
}

std::ostream& operator<<(std::ostream& out, const TwoDimensionalParity& obj)
{
	for (size_t row = 0; row < obj.parityMatrix.size(); ++row)
	{
		for (size_t column = 0; column < obj.parityMatrix[row].size(); ++column)
		{
			out << obj.parityMatrix[row][column] << " ";
		}
		out << std::endl;
	}

	return out;
}