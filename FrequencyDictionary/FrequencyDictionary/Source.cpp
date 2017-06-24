#include "FrequencyDictionary.h"

void test()
{
	FrequencyDictionary dictionary;
	dictionary.getCommon();
	dictionary.getRare();
	dictionary.getWithRank(5);
	dictionary.getRank("два");
	dictionary.getRank("день");
	dictionary.getWordsInRange(10, 20);
	dictionary.getWordsInRange(100, 2000);
	dictionary.getInfoPartOfSpeech("s");
	dictionary.getInfoPartOfSpeech("anum", 10000);
	dictionary.getStat();
	dictionary.getStat();
}

int main()
{
	test();


	return 0;
}