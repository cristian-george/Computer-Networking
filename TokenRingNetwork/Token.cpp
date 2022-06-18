#include "Token.h"

Token::Token() : m_isFree(true)
{
	m_sourceCode = m_destinationCode = m_previous = -1;
}

void Token::SetSourceAddress(const std::string& sourceAddress)
{
	m_sourceAddress = sourceAddress;
}

void Token::SetDestinationAddress(const std::string& destinationAddress)
{
	m_destinationAddress = destinationAddress;
}

void Token::SetMessage(const std::string& message)
{
	m_message = message;
}

void Token::SetIsFree(bool isFree)
{
	m_isFree = isFree;
}

void Token::SetSourceCode(int sourceCode)
{
	m_sourceCode = sourceCode;
}

void Token::SetDestinationCode(int destinationCode)
{
	m_destinationCode = destinationCode;
}

void Token::SetPrevious(int previous)
{
	m_previous = previous;
}

std::string Token::GetIPSourceAddress()
{
	return m_sourceAddress;
}

std::string Token::GetIPDestinationAddress()
{
	return m_destinationAddress;
}

std::string Token::GetMessage()
{
	return m_message;
}

bool Token::IsFree()
{
	return m_isFree;
}

int Token::GetSourceCode()
{
	return m_sourceCode;
}

int Token::GetDestinationCode()
{
	return m_destinationCode;
}

int Token::GetPrevious()
{
	return m_previous;
}
