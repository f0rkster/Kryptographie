#include "permutation.h"
#include <iostream>

void startPermutation(std::string _x, std::string _y)
{
	std::cout << std::endl << "START PERMUTATION" << std::endl;
	
	int initialPermutation[64] = {
	58,50,42,34,26,18,10,2,
	60,52,44,36,28,20,12,4,
	62,54,46,38,30,22,14,6,
	64,56,48,40,32,24,16,8,
	57,49,41,33,25,17,9,1,
	59,51,43,35,27,19,11,3,
	61,53,45,37,29,21,13,5,
	63,55,47,39,31,23,15,7
	};

	for (int index = 0; index < 64; index++)
	{
		_y[index] = _x[initialPermutation[index]-1];
	}

	char left[32] = {};
	_y.copy(left, 32, 0);	
	char right[32] = {};
	_y.copy(right, 32, 32);


}

void expansionPermutation()
{
	std::cout << std::endl << "EXPANSION PERMUTATION" << std::endl;

	int expansionMatrix[48] = {
	31,0,1,2,3,4,
	3,4,5,6,7,8,
	7,8,9,10,11,12,
	11,12,13,14,15,16,
	15,16,17,18,19,20,
	19,20,21,22,23,24,
	23,24,25,26,27,28,
	27,28,29,30,31,0
	};

}