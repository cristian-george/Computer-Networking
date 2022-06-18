#pragma once
#include <iostream>
#include <vector>
#include <string>

class TwoDimensionalParity
{
public:
	TwoDimensionalParity(const std::string& message);

	friend std::ostream& operator<<(std::ostream& out, const TwoDimensionalParity& obj);

	void SetRowsParity();
	void SetColumnsParity();
	void Corruption();
	std::pair<size_t, size_t> GetCorruptedBit();

private:
	void InitParityMatrix(const std::string& message);
	void SetRowParity(size_t row);
	void SetColumnParity(size_t column, std::vector<bool>& lastRow);

	bool GetRowParity(size_t row, size_t rowSize);
	bool GetColumnParity(size_t column, size_t columnSize);

private:
	std::vector<std::vector<bool>> parityMatrix;
};
