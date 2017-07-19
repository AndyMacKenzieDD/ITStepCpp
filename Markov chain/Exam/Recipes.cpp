#include "Recipes.h"
#include <iostream>

int Recipes::fileCounter = 0;

Recipes::Recipes(std::string file, int cicleCounter, int recipesCounter)
{
	recCounter = recipesCounter;
	counter = cicleCounter;
	std::ifstream in(file);

	std::string tmp1, tmp2;
	in >> tmp1;

	while (in >> tmp2)
	{
		if (tmp2[0] == '(')
		{
			std::string tmp3;
			while (tmp2[tmp2.size() - 1] != ')' && tmp2[tmp2.size() - 2] != ')')
			{
				in >> tmp3;
				tmp2 += ' ';
				tmp2 += tmp3;
			}
		}
		auto it = st.find(tmp1);
		if (it == st.end())
		{
			std::map<std::string, int> tmpM = { { tmp2, 1 } };
			st[tmp1] = std::move(tmpM);
		}
		else
		{
			auto it2 = it->second.find(tmp2);
			++st[tmp1][tmp2];
		}

		if (tmp1[tmp1.size() - 1] == '.')
		{
			starterWords.push_back(tmp2);
		}

		tmp1 = tmp2;
	}
	
	in.close();
}

Recipes::~Recipes()
{
}

void Recipes::generate() const
{
	std::string fileName = "Recipe " + std::to_string(++fileCounter) + ".txt";
	std::ofstream out(fileName);
	
	srand(time(0));

	for (int i = 0; i < recCounter; ++i)
	{
		int randInt = rand() % starterWords.size();
		std::string firstWard = starterWords[randInt];

		auto block = st.find(firstWard);
		
		for (int i = 0; i < counter; ++i)
		{
			out << block->first << " ";

			std::vector<std::string> second;
			for (auto it : block->second)
			{

				for (int i = 0; i < it.second; ++i)
				{
					second.push_back(it.first);
				}
			}

			randInt = rand() % second.size();
			block = st.find(second[randInt]);

			if (i % 10 == 0 && i != 0)
			{
				out << std::endl;
			}
		}
		int x = 0;
		out << std::endl;
		while (block->first[block->first.size() - 1] != '.')
		{
			out << block->first << " ";

			std::vector<std::string> second;
			for (auto it : block->second)
			{

				for (int i = 0; i < it.second; ++i)
				{
					second.push_back(it.first);
				}
			}

			randInt = rand() % second.size();
			block = st.find(second[randInt]);

			++x;
			if (x == 10)
			{
				x = 0;
				out << std::endl;
			}
		}
		out << block->first << std::endl;
	}
	out.close();
}
