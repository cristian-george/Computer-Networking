#pragma once
#include <string>

class CaesarCipher
{
public:
	CaesarCipher(const std::string& message, int key, bool isEncrypted = false);

	void Encryption(int key);
	void Decryption(int key);

	std::string GetEncryptedMessage();
	std::string GetDecryptedMessage();

private:
	std::string message;
	std::string encrypted;
	std::string decrypted;
};

