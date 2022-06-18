#include <iostream>
#include <array>
#include <sstream>

#include "../Network/TcpSocket.h"
#include "../TranspositionCipher/TranspositionCipher.cpp"

int main()
{
	std::cout << "Starting server" << std::endl;

	TcpSocket listener;
	listener.Listen(27015);

	std::cout << "Waiting for client to connect" << std::endl;
	TcpSocket client = listener.Accept();
	std::cout << "The client is connected" << std::endl;

	bool isSocketClosed = false;
	while (!isSocketClosed)
	{
		// receive
		std::array<char, 512> receiveBuffer;
		int received;
		client.Receive(receiveBuffer.data(), receiveBuffer.size(), received);

		std::string receivedMessage(receiveBuffer.begin(), receiveBuffer.begin() + received);
		std::cout << "Encrypted: " << receivedMessage << std::endl;

		TranspositionCipher tc(receivedMessage, true);
		std::string decryptedMessage = tc.GetDecryptedMessage();
		std::cout << "Decrypted: " << decryptedMessage << std::endl << std::endl;

		if (decryptedMessage.find("close") != std::string::npos)
			isSocketClosed = true;
	}

	std::cout << "Closing server. Bye! :)" << std::endl;

	return 0;
}