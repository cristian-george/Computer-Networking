#pragma once
#include <iostream>
#include <string>

class Computer
{
public:
	Computer() = default;
	Computer(const std::string& address, int code);

	void SetBuffer(const std::string& message);
	void SetAddress(const std::string& address);
	void SetCode(int code);

	std::string GetBuffer();
	std::string GetIPAddress();
	int GetCode();

	friend std::ostream& operator<<(std::ostream& out, const Computer& computer);

private:
	std::string m_buffer;
	std::string m_address;
	int m_code;
};