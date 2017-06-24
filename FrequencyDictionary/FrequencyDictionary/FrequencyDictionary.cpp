#include "FrequencyDictionary.h"

FrequencyDictionary::FrequencyDictionary() :
	getCommonCounter(0),
	getRareCounter(0),
	getWithRankCounter(0),
	getRankCounter(0),
	getWordsInRangeCounter(0),
	getInfoPartOfSpeechCounter(0),
	getStatCounter(0),
	getCommonName("getCommon"),
	getRareName("getRare"),
	getWithRankName("getWithRank"),
	getRankName("getRank"),
	getWordsInRangeName("getWordsInRange"),
	getInfoPartOfSpeechName("getInfoPartOfSpeech"),
	getStatName("getStat")
{


	std::ifstream in("dictionary.txt");
	int tmp0;
	std::string tmp1;
	while (in >> tmp0)
	{

		in >> tmp1;
		vec.push_back(tmp1);
		in >> tmp1;
		vec.push_back(tmp1);
		in >> tmp1;
		vec.push_back(tmp1);
		in >> tmp1;
		vec.push_back(tmp1);
		in >> tmp1;
		vec.push_back(tmp1);
		in >> tmp1;
		vec.push_back(tmp1);
		in >> tmp1;
		vec.push_back(tmp1);
		in >> tmp1;
		vec.push_back(tmp1);
		in >> tmp1;
		vec.push_back(tmp1);

		dic.insert({ tmp0, vec });
		vec.clear();
	}
	in.close();
}

FrequencyDictionary::~FrequencyDictionary()
{
}

void FrequencyDictionary::getCommon()
{
	std::string fileName = getCommonName + std::to_string(getCommonCounter++) + ".txt";
	std::ofstream out(fileName);
	out << dic.begin()->first << " " << dic.begin()->second[0] << " " << dic.begin()->second[1] << " " << dic.begin()->second[2] << std::endl;
	out.close();
}

void FrequencyDictionary::getRare()
{
	std::string fileName = getRareName + std::to_string(getRareCounter++) + ".txt";
	std::ofstream out(fileName);
	out << (--dic.end())->first << " " << (--dic.end())->second[0] << " " << (--dic.end())->second[1] << " " << (--dic.end())->second[2] << std::endl;
	out.close();
}

void FrequencyDictionary::getWithRank(const int rank)
{
	std::string fileName = getWithRankName + std::to_string(getWithRankCounter++) + ".txt";
	std::ofstream out(fileName);
	auto it = dic.find(rank);
	out << it->first << " " << it->second[0] << " " << it->second[1] << " " << it->second[2] << std::endl;
	out.close();
}

void FrequencyDictionary::getRank(const std::string word)
{
	std::string fileName = getRankName + std::to_string(getRankCounter++) + ".txt";
	std::ofstream out(fileName);

	for (auto it : dic)
	{
		if (it.second[0] == word)
		{
			out << it.first << " " << it.second[0] << " " << it.second[1] << " " << it.second[2] << std::endl;
		}
	}

	out.close();
}

void FrequencyDictionary::getWordsInRange(const int start, const int finish)
{
	std::string fileName = getWordsInRangeName + std::to_string(getWordsInRangeCounter++) + ".txt";
	std::ofstream out(fileName);

	for (auto it = dic.find(start); it != (++dic.find(finish)); ++it)
	{
			out << it->first << " " << it->second[0] << " " << it->second[1] << " " << it->second[2] << std::endl;
	}

	out.close();
}

void FrequencyDictionary::getInfoPartOfSpeech(const std::string partOfSpeech, const int rank)
{
	std::string fileName = getInfoPartOfSpeechName + std::to_string(getInfoPartOfSpeechCounter++) + ".txt";
	std::ofstream out(fileName);

	for (auto it : dic)
	{
		if(it.second[1] == partOfSpeech && it.first >= rank)
		out << it.first << " " << it.second[0] << " " << it.second[1] << " " << it.second[2] << std::endl;
	}

	out.close();
}

void FrequencyDictionary::getStat()
{
	std::string fileName = getStatName + std::to_string(getStatCounter++) + ".txt";
	std::ofstream out(fileName);

	int aCounter = 0;
	int advCounter = 0;
	int advproCounter = 0;
	int anumCounter = 0;
	int aproCounter = 0;
	int conjCounter = 0;
	int intjCounter = 0;
	int numCounter = 0;
	int partCounter = 0;
	int prCounter = 0;
	int sCounter = 0;
	int sproCounter = 0;
	int vCounter = 0;

	double aAvg = 0;
	double advAvg = 0;
	double advproAvg = 0;
	double anumAvg = 0;
	double aproAvg = 0;
	double conjAvg = 0;
	double intjAvg = 0;
	double numAvg = 0;
	double partAvg = 0;
	double prAvg = 0;
	double sAvg = 0;
	double sproAvg = 0;
	double vAvg = 0;

	for (auto it : dic)
	{
		if (it.second[1] == "a")
		{
			++aCounter;
			aAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "adv")
		{
			++advCounter;
			advAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "advpro")
		{
			++advproCounter;
			advproAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "anum")
		{
			++anumCounter;
			anumAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "apro")
		{
			++aproCounter;
			aproAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "conj")
		{
			++conjCounter;
			conjAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "intj")
		{
			++intjCounter;
			intjAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "num")
		{
			++numCounter;
			numAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "part")
		{
			++partCounter;
			partAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "pr")
		{
			++prCounter;
			prAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "s")
		{
			++sCounter;
			sAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "spro")
		{
			++sproCounter;
			sproAvg += atof(it.second[2].c_str());
		}
		else if (it.second[1] == "v")
		{
			++vCounter;
			vAvg += atof(it.second[2].c_str());
		}
	}

	aAvg /= aCounter;
	advAvg /= advCounter;
	advproAvg /= advproCounter;
	anumAvg /= anumCounter;
	aproAvg /= aproCounter;
	conjAvg /= conjCounter;
	intjAvg /= intjCounter;
	numAvg /= numCounter;
	partAvg /= partCounter;
	prAvg /= prCounter;
	sAvg /= sCounter;
	sproAvg /= sproCounter;
	vAvg /= vCounter;

	out << "a " << aCounter << " " << aAvg << std::endl;
	out << "adv " << advCounter << " " << advAvg << std::endl;
	out << "advpro " << advproCounter << " " << advproAvg << std::endl;
	out << "anum " << anumCounter << " " << anumAvg << std::endl;
	out << "apro " << aproCounter << " " << aproAvg << std::endl;
	out << "conj " << conjCounter << " " << conjAvg << std::endl;
	out << "intj " << intjCounter << " " << intjAvg << std::endl;
	out << "num " << numCounter << " " << numAvg << std::endl;
	out << "part " << partCounter << " " << partAvg << std::endl;
	out << "pr " << prCounter << " " << prAvg << std::endl;
	out << "s " << sCounter << " " << sAvg << std::endl;
	out << "spro " << sproCounter << " " << sproAvg << std::endl;
	out << "v " << vCounter << " " << vAvg << std::endl;

	out.close();
}