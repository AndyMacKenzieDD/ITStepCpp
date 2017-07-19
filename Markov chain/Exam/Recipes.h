#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <map>

class Recipes
{
	using chein = std::map<std::string, std::map<std::string, int>>; 
	chein st;
	static int fileCounter;
	int counter;
	int recCounter;
	std::vector<std::string> starterWords;
public:
	Recipes(std::string, int = 100, int = 1);
	~Recipes();

	void generate() const;
};

