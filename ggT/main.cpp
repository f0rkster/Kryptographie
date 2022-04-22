#include <iostream>
#include <string>

#include "frequency_analysis.h"
#include "ggT.h"
#include "vigenere_code.h"
#include "utility.h"

/*
lesson 1 = ggT
lesson 2 = vigenere_code + frequency_analysis
*/

int main() {
	std::cout << "ggT = " << ggT(93, 42) << std::endl;

	std::string input = "HALLO";
	std::string key = "KEY";
	std::string chiffre = vigenereEncode(input, key);
	std::cout << chiffre << std::endl;

	frequencyAnalysis(loadTxtIntoString("../Data/chiffre.txt"));


	return 1;
}