#include <iostream>
#include "Recipes.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	Recipes r("recipes.txt");
	r.generate();

	return 0;
}