#include "frequency_analysis.h"

#include <iostream>

void encryptInput(int* _frAna, std::string _Input) {

}

void frequencyAnalysis(std::string _Input)
{
	std::string chiffre = _Input;
	int alphabet[26] = { 0 };
	int offset = 65;

	for (char& letter : chiffre)
	{
		if ((letter - offset < 26) && (letter - offset >= 0))
			alphabet[letter - offset] ++;
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << (char)(i+offset) << " = " << alphabet[i] << std::endl;
	}

	encryptInput(alphabet, _Input);

}
