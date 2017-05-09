#include <iostream>
#include <fstream>
#include "frecuency.cpp"


int main(int argc, char const *argv[])
{
	std::vector<str_int> frecuency = GetSortedVector("text_for_stemming.txt", "stop_list.txt");
	
	std::ofstream frecuency_txt("frecuency.txt");

	int i = 0;
	for (auto  j = frecuency.begin(); j < frecuency.end(); ++j)
	{
		frecuency_txt << i+1 << ".	" << frecuency[i].first << " (" << frecuency[i].second << ")"<< std::endl;
		
		if(i<10)
		std::cout << i+1 << ".	" <<frecuency[i].first << " (" << frecuency[i].second << ")"<< std::endl;
		i++;
	}
	frecuency_txt.close();

	return 0;
}