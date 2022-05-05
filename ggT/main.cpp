#include <iostream>
#include <string>

#include "frequency_analysis.h"
#include "ggT.h"
#include "vigenere_code.h"
#include "blumblumshub.h"
#include "utility.h"
#include "permutation.h"

/*
lesson 1 = ggT
lesson 2 = vigenere_code + frequency_analysis
lesson 3 = blumblumshub
lesson 4 = permutation
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


	std::string input64 = "0000000100100011010001010110011110001001101010111100110111101111";
	std::string key64   = "0001001100110100010101110111100110011011101111001101111111110001";

	std::string permutation= "0000000000000000000000000000000000000000000000000000000000000000";
		
	startPermutation(input64, permutation);

	return 1;
}