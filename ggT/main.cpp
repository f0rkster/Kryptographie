#include <iostream>
#include <string>

#include "frequency_analysis.h"
#include "ggT.h"
#include "vigenere_code.h"
#include "blumblumshub.h"
#include "utility.h"
#include "permutation.h"
#include "rsa.h"
#include "chp_hash.h"

/*
lesson 1 = ggT
lesson 2 = vigenere_code + frequency_analysis
lesson 3 = blumblumshub
lesson 4 = permutation
lesson 5 = RSA
lesson 6 = CHP-Hash
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


	permutation();

	p = 13;
	q = 23;
	int M = 212;

	RSA(p, q, M);

	p = 12347;
	float alpha = 2;
	float beta = 8461;

	CHP_hash(p, alpha, beta);
	


	return 1;
}