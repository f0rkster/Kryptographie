#include "blumblumshub.h"
#include <iostream>
#include <math.h>

void blumblumshub(int _p, int _q, int _s)
{
	std::cout << "\nBLUMBLUMSHUB" << std::endl;
    int n = _p * _q;
    int x0 = (_s * _s) % n;
	int ITERATIONS = 100;

	for (int i = 1; i < ITERATIONS; i++)
	{
		int xi = (x0 * x0) % n;
		int bi = xi % 2;

		/*std::cout << "xi = " << xi << std::endl;
		std::cout << "bi = " << bi << std::endl;*/

		std::cout << bi;

		x0 = xi;
	}

	std::cout << std::endl;
}
