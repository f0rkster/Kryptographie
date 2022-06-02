#include "rsa.h"

#include <iostream>
#include <math.h>
#include <vector>
#include "ggT.h"

void RSA(int _p, int _q, int _M)
{
	std::cout << "\n\nRSA\n";

	int n = _p * _q;
	int phi = (_p - 1) * (_q - 1);

	int e = 3;
	bool correctE = false;
	while (!correctE)
	{
		if (ggT(e, phi) == 1)
		{
			correctE = true;
			break;
		}
		e += 2;
	}

	int d = ggTExtendedX(e, phi);

	if (d < 0) {
		d += phi;
	}
	std::cout << "d = " << d << std::endl;

	int C = square(_M, e) % n;
	std::cout << "C = " << C << std::endl;

	int M = square(C, d) % n;
	std::cout << "M = " << M << std::endl;

}

long long int square(int _base, int _exp)
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
			result = result * result;
			break;
		case 1:
			result = (result * result) * _base;
			break;
		}
	}

	return result;
}
