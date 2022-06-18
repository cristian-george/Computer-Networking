#include "Helper.h"

bool Helper::ContainsOnlyBits(const std::string& message)
{
	for (const auto& character : message)
	{
		if (character != '0' && character != '1')
			return false;
	}

	return true;
}

bool Helper::VerifyInput(const std::string& message, const std::string& polynomialCoefficients)
{
	if (message.length() <= polynomialCoefficients.length())
	{
		std::cout << "Message length is less than the number of polynomial coefficients. \n";
		return false;
	}

	if (!ContainsOnlyBits(message) or !ContainsOnlyBits(polynomialCoefficients))
	{
		std::cout << "The strings must contain only binary digits. \n";
		return false;
	}

	return true;
}

void Helper::PrintVector(std::ostream& out, const std::vector<bool> vect)
{
	for (const auto& value : vect)
	{
		out << value << " ";
	}
	out << std::endl;
}

std::vector<bool> Helper::ConvertStringToVector(const std::string& str)
{
	std::vector<bool> vect;

	for (const auto& chr : str)
	{
		vect.push_back(chr - '0');
	}

	return vect;
}

std::vector<bool> Helper::RemoveRedundantZeros(const std::vector<bool>& vect)
{
	std::vector<bool> newVect;

	size_t index = 0;
	while (index < vect.size() && !vect[index])
		++index;

	for (; index < vect.size(); ++index)
		newVect.push_back(vect[index]);

	return newVect;
}
