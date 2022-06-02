#include "permutation.h"
#include <iostream>

void permutation()
{
	std::string input64 = "0000000100100011010001010110011110001001101010111100110111101111";
	std::string key64 = "0001001100110100010101110111100110011011101111001101111111110001";

	std::string permutation = "0000000000000000000000000000000000000000000000000000000000000000";

	startPermutation(input64, permutation);

	std::string cKey56 = keyPermutation(key64);

	std::string left  = cKey56.substr(0, 28);
	std::string right = cKey56.substr(28, 28);
	std::cout << std::endl;
	for (int i = 0; i < 16; i++)
	{
		cKey56 = keyShift(cKey56, i);
		std::string ccKey48 = keyCompression(cKey56);
		std::cout << ccKey48 << std::endl;
	}
}

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

	std::string left = _y.substr(0, 32);
	std::string right = _y.substr(32, 64);


	std::cout << left;
	std::cout << std::endl;
	std::cout << right;

	expansionPermutation((std::string)right);

}

void expansionPermutation(std::string _vertex)
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

	std::string permutation = "000000000000000000000000000000000000000000000000";

	for (int index = 0; index < 48; index++)
	{
		permutation[index] = _vertex[expansionMatrix[index]];
	}

	std::cout << permutation;

}

std::string keyShift(std::string _Input, int _Index)
{
	int half = _Input.length() / 2;

	std::string left  = _Input.substr(0, half);
	std::string right = _Input.substr(half, half);

	left  = shift(left, _Index);
	right = shift(right, _Index);

	std::string result = left + right;
	return result;
}

std::string shift(std::string _Input, int _Index)
{
	int shiftPattern[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

	std::string result = _Input;
	std::string temp  = "";

	switch (shiftPattern[_Index]) {
	case 1:
		temp = result.substr(0, 1);

		result = result.erase(0, 1);
		result.push_back(temp[0]);
		break;
	case 2:
		temp = result.substr(0, 2);

		result = result.erase(0, 2);
		result.push_back(temp[0]);
		result.push_back(temp[1]);
		break;
		// std::cout << "\t SHIFT:" << result << "\t SHIFTED BY " << shifter << std::endl;
	}
	return result;
}


std::string keyPermutation(std::string _Key)
{
	std::cout << std::endl << "PERMUTED KEY" << std::endl;

	int keyPermutation[56] = {
		57,49,41,33,25,17,9,
		1,58,50,42,34,26,18,
		10,2,59,51,43,35,27,
		19,11,3,60,52,44,36,
		63,55,47,39,31,23,15,
		7,62,54,46,38,30,22,
		14,6,61,53,45,37,29,
		21,13,5,28,20,12,4
	};

	std::string cKey = "00000000000000000000000000000000000000000000000000000000";

	for (int index = 0; index < 56; index++)
	{
		cKey[index] = _Key[keyPermutation[index]-1];
	}

	return cKey;
}

std::string keyCompression(std::string _Key)
{
	std::cout << std::endl << "COMPRESSED KEY" << std::endl;

	int keyCompression[48] = {
		14,17,11,24,1,5,
		3,28,15,6,21,10,
		23,19,12,4,26,8,
		16,7,27,20,13,2,
		41,52,31,37,47,55,
		30,40,51,45,33,48,
		44,49,39,56,34,53,
		46,42,50,36,29,32
	};

	std::string cKey = "00000000000000000000000000000000000000000000000";

	for (int index = 0; index < 48; index++)
	{
		cKey[index] = _Key[keyCompression[index] - 1];
	}

	return cKey;
}

void sBoxSubstitution(std::string _Input) {
	int substitionBoxes[8][4][16] =
	{ {
		{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
		{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
		{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
		{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
	},
	{
		{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
		{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
		{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
		{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
	},
	{
		{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
		{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
		{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
		{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
	},
	{
		{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
		{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
		{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
		{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
	},
	{
		{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
		{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
		{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
		{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
	},
	{
		{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
		{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
		{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
		{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
	},
	{
		{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
		{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
		{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
		{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
	},
	{
		{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
		{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
		{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
		{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
	} };


}