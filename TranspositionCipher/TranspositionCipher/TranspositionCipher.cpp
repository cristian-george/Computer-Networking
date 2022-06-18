#include "TranspositionCipher.h"
#include <vector>

TranspositionCipher::TranspositionCipher(const std::string& message, bool isEncrypted)
{
	this->message = message;

	if (isEncrypted == false)
	{
		Encryption();
	}
	else
	{
		Decryption();
	}
}

void TranspositionCipher::Encryption()
{
	std::vector<char> arrayMessage;
	for (char c : message)
	{
		arrayMessage.push_back(c);
	}

	size_t arraySize = arrayMessage.size();
	size_t keySize = key.length();

	char letter = 'a';

	while (arraySize % keySize != 0)
	{
		arrayMessage.push_back(letter);
		++letter;
		++arraySize;
	}

	for (char c = 'a'; c <= 'z'; ++c)
	{
		int pos = key.find(c);
		if (pos != std::string::npos)
		{
			for (int i = pos; i < arraySize; i = i + keySize)
			{
				encrypted.push_back(arrayMessage[i]);
			}
		}
	}
}

void TranspositionCipher::Decryption()
{
	std::vector<char> arrayMessage;
	for (char c : message)
	{
		arrayMessage.push_back(c);
	}

	size_t arraySize = arrayMessage.size();
	size_t keySize = key.length();

	decrypted.resize(arraySize);

	int k = 0;
	for (char c = 'a'; c <= 'z'; ++c)
	{
		int pos = key.find(c);
		if (pos != std::string::npos)
		{
			for (int i = pos; i < arraySize; i = i + keySize)
			{
				decrypted[i] = arrayMessage[k++];
			}
		}
	}
}

std::string TranspositionCipher::GetEncryptedMessage()
{
	return encrypted;
}

std::string TranspositionCipher::GetDecryptedMessage()
{
	return decrypted;
}
