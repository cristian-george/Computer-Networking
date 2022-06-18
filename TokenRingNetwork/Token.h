#pragma once
#include <string>
class Token
{
public:
	Token();

	void SetSourceAddress(const std::string& sourceAddress);
	void SetDestinationAddress(const std::string& destinationAddress);
	void SetMessage(const std::string& message);
	void SetIsFree(bool isFree);

	void SetSourceCode(int sourceCode);
	void SetDestinationCode(int destinationCode);
	void SetPrevious(int previous);

	std::string GetIPSourceAddress();
	std::string GetIPDestinationAddress();
	std::string GetMessage();
	bool IsFree();

	int GetSourceCode();
	int GetDestinationCode();
	int GetPrevious();

private:
	std::string m_sourceAddress;
	std::string m_destinationAddress;
	std::string m_message;
	bool m_isFree;
	int m_sourceCode, m_destinationCode, m_previous;
};