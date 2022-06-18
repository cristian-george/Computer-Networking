#include <iostream>
#include <array>
#include <unordered_set>
#include <random>

#include "../Network/TcpSocket.h"
#include "../CaesarCipher/CaesarCipher.cpp"

bool IsValid(unsigned int p, unsigned int a)
{
	if (p < 2 or p > 2 && p % 2 == 0)
		return false;

	for (int d = 3; d * d < p; d += 2)
		if (p % d == 0)
			return false;

	std::unordered_set<int> values;
	for (int index = 1; index <= p - 1; ++index)
	{
		values.insert((int)pow(a, index) % p);
	}

	for (int value = 1; value <= p - 1; ++value)
		if (values.find(value) == values.end())
			return false;

	return true;
}

void ReadInput(unsigned int& p, unsigned int& a)
{
	bool ok = false;

	while (!ok)
	{
		std::cout << "p = ";
		std::cin >> p;

		std::cout << "a = ";
		std::cin >> a;

		if (IsValid(p, a))
		{
			ok = true;
			std::cout << "The values are correct !" << std::endl;
			std::cin.get();
		}
		else
		{
			std::cout << "The values are incorrect, provide other values !" << std::endl;
		}
	}
}

void DiffieHellmanKeyExchange(TcpSocket* socket, unsigned int p, unsigned int a, int& key)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<> distrib(1, p - 1);

	int xA = distrib(gen);
	int yA = (int)pow(a, xA) % p;

	std::string messageToSend = std::to_string(yA);
	socket->Send(messageToSend.c_str(), messageToSend.size());

	std::array<char, 512> receiveBuffer;
	int received;
	socket->Receive(receiveBuffer.data(), receiveBuffer.size(), received);
	std::string messageReceived(receiveBuffer.begin(), receiveBuffer.begin() + received);

	int yB = atoi(messageReceived.c_str());

	key = (int)pow(yB, xA) % p;
}

int main(int argc, char* argv[])
{
	// Validate the parameters
	if (argc != 2) {
		std::cerr << "usage: " << argv[0] << " server-name" << std::endl;
		return 1;
	}

	std::cout << "Starting client" << std::endl;

	TcpSocket socket;
	std::cout << "Connecting to server at: " << argv[1] << std::endl;
	socket.Connect("192.168.2.114", 27015);

	// Read prime number "p" and primitive root "a"
	unsigned int p, a;
	ReadInput(p, a);

	std::string primeNumber = std::to_string(p);
	std::string primitiveRoot = std::to_string(a);

	// Send "p" and "a" to the server
	std::string messageToSend = primeNumber + " " + primitiveRoot;
	socket.Send(messageToSend.c_str(), messageToSend.size());

	// Find key
	int key;
	DiffieHellmanKeyExchange(&socket, p, a, key);
	std::cout << "The key is: " << key << std::endl;

	bool isSocketClosed = false;
	while (!isSocketClosed)
	{
		std::string message;
		std::cout << "Type your message: ";
		std::getline(std::cin, message);

		if (message == "close")
			isSocketClosed = true;

		// Send
		CaesarCipher caesarCipher(message, key, false);
		std::string encryptedMessage = caesarCipher.GetEncryptedMessage();
		socket.Send(encryptedMessage.c_str(), encryptedMessage.size());
	}

	return 0;
}