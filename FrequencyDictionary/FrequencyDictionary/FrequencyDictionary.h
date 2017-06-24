#pragma once
#include<map>
#include<string>
#include<vector>
#include<fstream>

class FrequencyDictionary
{
	std::vector<std::string> vec;
	std::map<int, std::vector<std::string>> dic;
	std::string getCommonName;
	std::string getRareName;
	std::string getWithRankName;
	std::string getRankName;
	std::string getWordsInRangeName;
	std::string getInfoPartOfSpeechName;
	std::string getStatName;
	int getCommonCounter;
	int getRareCounter;
	int getWithRankCounter;
	int getRankCounter;
	int getWordsInRangeCounter;
	int getInfoPartOfSpeechCounter;
	int getStatCounter;
public:
	FrequencyDictionary();
	~FrequencyDictionary();
	void getCommon();
	void getRare();
	void getWithRank(const int);
	void getRank(const std::string);
	void getWordsInRange(const int, const int);
	void getInfoPartOfSpeech(const std::string, const int = 0);
	void getStat();
};

