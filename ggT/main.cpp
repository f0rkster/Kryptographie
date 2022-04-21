#include <iostream>
#include <string>

#include "frequency_analysis.h"
#include "ggT.h"
#include "vigenere_code.h"
#include "utility.h"

int main() {
	std::cout << "ggT = " << ggT(93, 42) << std::endl;

	std::string input = "HALLO";
	std::string key = "KEY";
	std::string chiffre = vigenereEncode(input, key);
	std::cout << chiffre << std::endl;

	frequencyAnalysis(loadTxtIntoString("../Data/chiffre.txt"));


	return 1;
}