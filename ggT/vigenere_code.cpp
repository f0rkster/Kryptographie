#include "vigenere_code.h"

#include <iostream>



std::string vigenereEncode(std::string _Input, std::string _Key)
{
	std::string chiffre = _Input;
	std::string temp;

	int keyLength = _Key.length();
	int keyIndex = 0;

	for (char& letter : chiffre) {
		int offset = 65;
		int delta = _Key[keyIndex] - offset;

		//Encode
		letter = letter + delta ;
		//Handle out of bounce
		if ((int)letter > (offset+26)) letter = letter - 26;
		
		keyIndex < keyLength-1  ? keyIndex++ : keyIndex = 0;
	}

	return chiffre;
}
