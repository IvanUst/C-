#include "mask.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

typedef  std::pair<std::string, size_t> str_int;

//Reсeive text to the string (data)
std::string GetText(const char * filename)
{
	std::ifstream in(filename);
	std::string data;
	data.assign((std::istreambuf_iterator<char>(in.rdbuf())), std::istreambuf_iterator<char>());
	in.close();
	return data;
}

std::map<std::string, size_t> GetFrequencyMap(const char * filename) 
{
	std::map<std::string, size_t> result;
	std::string text = GetText(filename);

	std::stringstream inputStringStream(text);

	std::string word;
	while (inputStringStream >> word) 
		result[word]++; 

	return result;
}

//Comparator to q_sort
class str_int_cmp 
{
public:
	bool operator()(const str_int strInt1, const str_int strInt2)
	{
		return strInt1.second > strInt2.second;
	}
};

//The list of bunned words
std::set<std::string> StopDictionary(const char * filename)  
{
	std::ifstream inStream(filename);
	std::set<std::string> result; 
	std::string word;

	for (; !inStream.eof(); inStream >> word)
		result.insert(word);
	inStream.close();
	return result;
}

std::vector<str_int> GetSortedVector(const char * filename, const char * StopD) 
{
	std::map<std::string, size_t> map = GetFrequencyMap(filename);
	std::set<std::string> stopD = StopDictionary(StopD);
	std::vector<str_int> result;
	
	for (auto it = map.begin(); it != map.end(); ++it)
	{
		bool finded = stopD.find(it->first) != stopD.end();
		if (!finded) 
			result.push_back(*it); 
	}

	std::sort(result.begin(), result.end(), str_int_cmp());
	

	return result;
}