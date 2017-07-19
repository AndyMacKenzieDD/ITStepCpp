#include <iostream>
#include "Recipes.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	Recipes r("recipes.txt", 100, 1);
	r.generate();

	return 0;
}