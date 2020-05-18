#pragma once
#include "GraczClass.h"
using namespace std;

class Kard {
	string Nazwa;
	string effect;
	unsigned int count;
	unsigned int numb;
public:
	void kardget();
	unsigned int kardcountget();
	void karduse();
};
