#include "frequency_analysis.h"

#include <iostream>

struct SLetter {
	char m_Letter;
	int m_Count = 0;
};

void decodeInput(SLetter* _frAna, std::string _Input) {
	//regular topList 
	//char topList[] = {'E', 'N', 'I', 'S', 'R', 'A', 
	//					'T', 'D', 'H', 'U', 'L', 
	//					'C', 'G', 'M', 'O', 'B', 
	//					'W', 'F', 'K', 'Z', 'P', 
	//					'V', 'J', 'Y', 'X', 'Q'};

	//this topList
	char topList[] = {'E', 'N', 'I', 'S', 'R', 'T', 
						'A', 'U', 'H', 'L', 'D', 
						'C', 'O', 'M', 'G', 'P', 
						'F', 'B', 'K', 'V', 'Z', 
						'W', 'Q', 'Y', 'X', 'J'};
	SLetter index[26][2] = {0};
	SLetter temp;

	for (int i = 0; i < 26; i++)
	{
		// Sort _frAna array desc
		for (int j = i + 1; j < 26; j++)
		{
			if (_frAna[i].m_Count < _frAna[j].m_Count)
			{
				temp = _frAna[j];
				_frAna[j] = _frAna[i];
				_frAna[i] = temp;
			}
		}

		// fills index array with the toplist and the matched letter
		for (int j = 0; j < 2; j++)
		{
			switch (j)
			{
			case 0:
				index[i][j].m_Letter = _frAna[i].m_Letter;
				index[i][j].m_Count = _frAna[i].m_Count;
				break;
			case 1:
				index[i][j].m_Letter = topList[i];
				break;
			default:
				std::cout << "ERROR" << std::endl;
				return;
				break;
			}
		}
		std::cout << "(" << index[i][0].m_Count << ")\t" << index[i][0].m_Letter << " = " << index[i][1].m_Letter << std::endl;
	}

	// generates decrypted output
	for (char& letter : _Input)
	{
		bool hasMatched = false;
		for (int i = 0; i < 26; i++) {
			if (letter == index[i][0].m_Letter)
			{
				std::cout << index[i][1].m_Letter;
				hasMatched = true;
				break;
			}
		}
		if (!hasMatched) std::cout << letter;
	}
}

void frequencyAnalysis(std::string _Input)
{
	std::string chiffre = _Input;
	SLetter alphabet[26] = { 0 };
	int offset = 65;

	for (int i = 0; i < 26; i++)
	{
		alphabet[i].m_Letter = (char)(i + offset);
	}


	for (char& letter : chiffre)
	{
		if ((letter - offset < 26) && (letter - offset >= 0))
			alphabet[letter - offset].m_Count ++;
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << alphabet[i].m_Letter << " = " << alphabet[i].m_Count << std::endl;
	}

	decodeInput(alphabet, _Input);
}
