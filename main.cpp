#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "spielfeld.h"


int main() {

	/*srand(time(NULL));
	int a = rand() % 4 + 1;

	std::cout << a << std::endl;*/

	Spielfeld A;
	A.print_Spielfeld();

	system("pause");
	return 0;
}
