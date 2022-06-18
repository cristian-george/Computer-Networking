#include <iostream>
#include <string>
#include <thread>
#include <random>

using namespace std::chrono_literals;

bool FIN;
int F;
std::string substrToSend;

std::vector<int> Fs;

void SourceSliding(const std::string& message)
{
	int lastSize = 0;
	std::string substrRemaining = message;

	while (!FIN)
	{
		if (lastSize != Fs.size())
		{
			lastSize = Fs.size();

			if (F != 0)
			{
				std::this_thread::sleep_for(500ms);

				if (F >= substrRemaining.size())
				{
					substrToSend = substrRemaining;
					FIN = true;
				}
				else
				{
					substrToSend = substrRemaining.substr(0, F);
					substrRemaining = substrRemaining.substr(F);
				}

				std::cout << "The source sent: " << substrToSend << std::endl;
			}
		}
	}
}

void DestinationSliding()
{
	std::string messageReceived;

	while (!FIN)
	{
		std::random_device rd;
		std::mt19937_64 gen(rd());
		std::uniform_int_distribution<> distrib(0, 5);

		F = distrib(gen);
		Fs.push_back(F);
		std::cout << "F = " << F << std::endl;

		std::this_thread::sleep_for(1000ms);

		if (F == 0)
		{
			std::this_thread::sleep_for(1000ms);
		}
		else
		{
			messageReceived += substrToSend;
		}
	}

	std::cout << "The destination received: " << messageReceived << std::endl;
}

int main()
{
	std::string message;
	std::cout << "Type a message: ";
	std::getline(std::cin, message);

	std::thread source(SourceSliding, message);
	std::thread destination(DestinationSliding);

	source.join();
	destination.join();

	return 0;
}