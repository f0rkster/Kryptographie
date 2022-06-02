#include "chp_hash.h"


#include <iostream>
#include <vector>


long long int hash(int _x1, int _x2, int _p, int _alpha, int _beta) {
	return((pow(_alpha, _x1, _p) * pow(_beta, _x2, _p)) % _p);
}


void CHP_hash(int _p, int _alpha, int _beta)
{
	std::cout << std::endl;
	std::cout << "HASH" << std::endl;
	int q = (_p - 1) / 2;

	int x1 = 5692;
	int x2 = 144;
	long long int hash1 = hash(x1, x2, _p, _alpha, _beta);

	x1 = 1220;
	x2 = 54;
	long long int hash2 = hash(x1, x2, _p, _alpha, _beta);

	x1 = 212;
	x2 = 4214;
	long long int hash3 = hash(x1, x2, _p, _alpha, _beta);


	std::cout << hash1 << std::endl;
	std::cout << hash2 << std::endl;
	std::cout << hash3 << std::endl;
}


long long int pow(int _base, int _exp, int _p)
{
	std::vector<int> binary = {};

	int b = _exp;

	while (b)
	{
		binary.insert(binary.begin(), b % 2);
		b /= 2;
	}

	long long int result = 1;

	for (int number : binary)
	{
		switch (number)
		{
		case 0:
			result = result * result % _p;
			break;
		case 1:
			result = (result * result) % _p * _base % _p;
			break;
		}
	}

	return result;
}
