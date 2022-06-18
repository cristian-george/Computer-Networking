#pragma once
#include <string>

const std::string key = "tenis";

class TranspositionCipher
{
public:
	TranspositionCipher(const std::string& message, bool isEncrypted = false);

	void Encryption();
	void Decryption();

	std::string GetEncryptedMessage();
	std::string GetDecryptedMessage();

private:
	std::string message;
	std::string encrypted;
	std::string decrypted;
};

