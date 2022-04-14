#include "ggT.h"

int ggT(int _a, int _b)
{
	int rest = -1;

	int newA = _a;
	int newB = _b;

	while (rest != 0)
	{
		rest = newA % newB;
		newA = newB;
		newB = rest;
	}
	return newA;
}

int ggTExtended(int _a, int _b)
{
	int xOld = 1;
	int x = 0;
	int yOld = 0;
	int y = 1;

	int a = _b;
	int aOld = _a;

	int q    = -1;
	int aNew = -1;
	int xNew = -1;
	int yNew = -1;

	while (aNew != 0)
	{
		q = aOld / a;
		aNew = aOld - q * a;
		xNew = xOld - q * x;
		yNew = yOld - q * y;

		aOld = a;
		xOld = x;
		yOld = y;

		a = aNew;
		x = xNew;
		y = yNew;
	}

	return aOld;
}
