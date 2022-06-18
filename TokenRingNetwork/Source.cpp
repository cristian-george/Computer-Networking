#include <iostream>
#include "Token.h"
#include "Computer.h"
#include <vector>
#include <thread>
#include <mutex>

using namespace std::chrono_literals;
constexpr size_t NUMBER_OF_COMPUTERS = 10;

std::string GenerateIPAddress()
{
	std::string address;

	for (size_t index = 0; index < 4; ++index)
	{
		int number = std::rand() % 256;
		address += std::to_string(number) + '.';
	}

	address.pop_back();
	return address;
}

void ComputersInitialize(std::vector<Computer>& computers)
{
	for (size_t index = 0; index < NUMBER_OF_COMPUTERS; ++index)
	{
		std::string IPAddress = GenerateIPAddress();
		Computer computer(IPAddress, index);
		computers.push_back(computer);
	}
}

void ShiftingSourceToDestination(int source, int destination)
{
	if (source != destination && source != -1 && destination != -1)
	{
		for (int index = source; index != destination; index = (index + 1) % NUMBER_OF_COMPUTERS)
		{
			std::cout << 'C' << index << ": Muta jetonul \n";
		}
	}
}

void SourceToDestination(Token& token, std::vector<Computer>& computers, int& completed)
{
	int source = token.GetSourceCode();
	int destination = token.GetDestinationCode();

	if (source != -1 && destination != -1)
	{
		std::cout << std::endl;
		std::cout << "Source: " << source << std::endl;
		std::cout << "Destination: " << destination << std::endl;

		if (token.GetPrevious() != -1)
		{
			ShiftingSourceToDestination(token.GetPrevious(), source);
			std::cout << 'C' << source << ": Am preluat jetonul \n";
		}

		ShiftingSourceToDestination(source, destination);
		std::cout << 'C' << destination << ": Am ajuns la destinatie \n";

		ShiftingSourceToDestination(destination, source);
		std::cout << 'C' << source << ": Am ajuns inapoi \n\n";

		token.SetPrevious(source);
		computers[destination].SetBuffer(token.GetMessage());

		for (auto& computer : computers)
		{
			if (computer.GetBuffer() != "null")
			{
				++completed;
			}

			std::cout << computer << std::endl;
		}
	}
}

std::mutex mutex;

void MoveToken(Token& token, std::vector<Computer>& computers, int& completed)
{
	int source = token.GetSourceCode();
	int destination = token.GetDestinationCode();

	if (source == destination or (source == -1 or destination == -1))
	{
		token.SetSourceAddress("");
		token.SetSourceCode(-1);
		token.SetDestinationAddress("");
		token.SetDestinationCode(-1);
		token.SetIsFree(true);
	}
	else
	{
		mutex.lock();

		SourceToDestination(token, computers, completed);
		token.SetSourceAddress("");
		token.SetSourceCode(-1);
		token.SetDestinationAddress("");
		token.SetDestinationCode(-1);
		token.SetIsFree(true);

		mutex.unlock();
	}
}

void SetComputerThread(Token& token, Computer& computer, std::vector<Computer>& computers)
{
	bool isClose = false;
	while (!isClose)
	{
		int completed = 0;

		if (token.IsFree() && token.GetIPSourceAddress().empty())
		{
			token.SetSourceAddress(computer.GetIPAddress());
			token.SetSourceCode(computer.GetCode());
		}
		else
			if (token.IsFree() && token.GetIPDestinationAddress().empty() &&
				token.GetIPSourceAddress() != computer.GetIPAddress())
			{
				token.SetDestinationAddress(computer.GetIPAddress());
				token.SetDestinationCode(computer.GetCode());
				token.SetIsFree(false);
			}

		if (!token.IsFree())
		{
			MoveToken(token, computers, completed);
		}

		if (completed == NUMBER_OF_COMPUTERS)
		{
			exit(0);
		}

		std::this_thread::sleep_for(50ms);
	}
}

int main()
{
	Token token;
	std::vector<Computer> computers;
	std::vector<std::thread> threads;

	std::string message;
	std::cout << "Type the message: ";
	std::getline(std::cin, message);

	token.SetMessage(message);
	ComputersInitialize(computers);

	for (const auto& computer : computers)
	{
		std::cout << computer << std::endl;
	}

	for (size_t index = 0; index < NUMBER_OF_COMPUTERS; ++index)
	{
		threads.push_back(
			std::thread(SetComputerThread, std::ref(token), std::ref(computers[index]), std::ref(computers))
		);
	}

	for (auto& thread : threads)
		thread.join();

	return 0;
}