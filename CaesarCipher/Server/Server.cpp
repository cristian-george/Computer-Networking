#include <iostream>
#include <array>
#include <sstream>

#include "../Network/TcpSocket.h"
#include "../CaesarCipher/CaesarCipher.cpp"
#include <random>

void DiffieHellmanKeyExchange(TcpSocket* socket, unsigned int p, unsigned int a, int& key)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<> distrib(1, p - 1);

	int xB = distrib(gen);
	int yB = (int)pow(a, xB) % p;

	std::array<char, 512> receiveBuffer;
	int received;
	socket->Receive(receiveBuffer.data(), receiveBuffer.size(), received);
	std::string messageReceived(receiveBuffer.begin(), receiveBuffer.begin() + received);

	int yA = atoi(messageReceived.c_str());

	std::string messageToSend = std::to_string(yB);
	socket->Send(messageToSend.c_str(), messageToSend.size());

	key = (int)pow(yA, xB) % p;
}

int main()
{
	std::cout << "Starting server" << std::endl;

	TcpSocket listener;
	listener.Listen(27015);

	std::cout << "Waiting for client to connect" << std::endl;
	TcpSocket client = listener.Accept();
	std::cout << "The client is connected" << std::endl;

	// Receive "p" and "a" from client
	std::array<char, 512> receiveBuffer;
	int received;
	client.Receive(receiveBuffer.data(), receiveBuffer.size(), received);
	std::string messageReceived(receiveBuffer.begin(), receiveBuffer.begin() + received);

	int space = messageReceived.find(' ');
	unsigned int p = atoi(messageReceived.substr(0, space).c_str());
	unsigned int a = atoi(messageReceived.substr(space).c_str());

	// Find key
	int key;
	DiffieHellmanKeyExchange(&client, p, a, key);
	std::cout << "The key is: " << key << std::endl;

	bool isSocketClosed = false;
	while (!isSocketClosed)
	{
		// receive
		std::array<char, 512> receiveBuffer;
		int received;
		client.Receive(receiveBuffer.data(), receiveBuffer.size(), received);

		std::string receivedMessage(receiveBuffer.begin(), receiveBuffer.begin() + received);
		std::cout << "Encrypted: " << receivedMessage << std::endl;

		CaesarCipher caesarCipher(receivedMessage, key, true);
		std::string decryptedMessage = caesarCipher.GetDecryptedMessage();
		std::cout << "Decrypted: " << decryptedMessage << std::endl << std::endl;

		if (decryptedMessage.find("close") != std::string::npos)
			isSocketClosed = true;
	}

	std::cout << "Closing server. Bye! :)" << std::endl;

	return 0;
}