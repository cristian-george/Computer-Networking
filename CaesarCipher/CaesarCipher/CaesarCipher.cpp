#include "CaesarCipher.h"
#include <vector>

CaesarCipher::CaesarCipher(const std::string& message, int key, bool isEncrypted)
{
	this->message = message;

	if (isEncrypted == false)
	{
		Encryption(key);
	}
	else
	{
		Decryption(key);
	}
}

void CaesarCipher::Encryption(int key)
{
	for (const auto& ch : message)
		if (isalpha(ch))
		{
			char newCh = ch + key;
			if (newCh > 'z')
				newCh = 'a' + newCh - 'z' - 1;

			encrypted.push_back(newCh);
		}
		else
			encrypted.push_back(ch);
}

void CaesarCipher::Decryption(int key)
{
	for (const auto& ch : message)
		if (isalpha(ch))
		{
			char newCh = ch - key;
			if (newCh < 'a')
				newCh = 'z' + newCh - 'a' + 1;

			decrypted.push_back(newCh);
		}
		else
			decrypted.push_back(ch);
}

std::string CaesarCipher::GetEncryptedMessage()
{
	return encrypted;
}

std::string CaesarCipher::GetDecryptedMessage()
{
	return decrypted;
}
