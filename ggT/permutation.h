#pragma once

#include <string>

void permutation();

void startPermutation(std::string _x, std::string _y);

void expansionPermutation(std::string _vertex);

std::string keyShift(std::string _Input, int _Index);

std::string shift(std::string _Input, int _Index);

std::string keyPermutation(std::string _Key);

std::string keyCompression(std::string _Key);

void sBoxSubstitution(std::string _Input);