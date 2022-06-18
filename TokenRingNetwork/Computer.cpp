#include "Computer.h"

Computer::Computer(const std::string& address, int code) : m_address(address), m_code(code)
{
	m_buffer = "null";
}

void Computer::SetBuffer(const std::string& message)
{
	m_buffer = message;
}

void Computer::SetAddress(const std::string& address)
{
	m_address = address;
}

void Computer::SetCode(int code)
{
	m_code = code;
}

std::string Computer::GetBuffer()
{
	return m_buffer;
}

std::string Computer::GetIPAddress()
{
	return m_address;
}

int Computer::GetCode()
{
	return m_code;
}

std::ostream& operator<<(std::ostream& out, const Computer& computer)
{
	out << 'C' << computer.m_code << " (" << computer.m_address << ") -> " << computer.m_buffer;
	return out;
}
