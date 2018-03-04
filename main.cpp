#include <iostream>
#include <cstdio>   //for random number
#include <cstdlib>
#include <ctime>
#include "spielfeld.h"


int main() {

	/*srand(time(NULL));
	int a = rand() % 4 + 1;

	std::cout << a << std::endl;*/

	std::srand(std::time(NULL));
	int breite = std::rand() % 30 + 20;
	int laenge = std::rand() % 30 + 20;

	Spielfeld A(breite, laenge);
	A.macheZug();

	system("pause");
	return 0;
}
