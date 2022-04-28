#include <iostream>
#include <string>

#include "frequency_analysis.h"
#include "ggT.h"
#include "vigenere_code.h"
#include "blumblumshub.h"
#include "utility.h"

/*
lesson 1 = ggT
lesson 2 = vigenere_code + frequency_analysis
lesson 3 = blumblumshub
*/

int main() {
	std::cout << "ggT = " << ggT(93, 42) << std::endl;

	std::string input = "HALLO";
	std::string key = "KEY";
	std::string chiffre = vigenereEncode(input, key);
	std::cout << chiffre << std::endl;

	//frequencyAnalysis(loadTxtIntoString("../Data/chiffre.txt"));
	int p = 7;
	int q = 19;
	int s = 2;
	blumblumshub(p, q, s);

	p = 47;
	q = 67;
	s = 6;
	blumblumshub(p, q, s);

	return 1;
}