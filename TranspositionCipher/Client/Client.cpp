#include <iostream>
#include <array>

#include "../Network/TcpSocket.h"
#include "../TranspositionCipher/TranspositionCipher.cpp"

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

	bool isSocketClosed = false;
	while (!isSocketClosed)
	{
		std::string message;
		std::cout << "Type your message: ";
		std::getline(std::cin, message);

		if (message == "close")
			isSocketClosed = true;

		//send
		TranspositionCipher tc(message, false);
		std::string encryptedMessage = tc.GetEncryptedMessage();
		socket.Send(encryptedMessage.c_str(), encryptedMessage.size());
	}

	return 0;
}