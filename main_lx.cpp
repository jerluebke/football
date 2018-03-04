#include <iostream>
#include <cstdio>   //for random number
#include <cstdlib>
#include <ctime>
#include "spielfeld.h"


int main() {

	std::srand(std::time(NULL));
	int breite = std::rand() % 30 + 20;
	int laenge = std::rand() % 30 + 20;

	Spielfeld A(breite, laenge, 'l');
	A.macheZug();

	// system("pause");
	return 0;
}
