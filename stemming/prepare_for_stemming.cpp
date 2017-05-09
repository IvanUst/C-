#include "mask.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <cctype> 
#include <locale>

//Reсeive text to the string (data)
std::string GetText(const char * filename)
{
	std::ifstream in(filename);
	std::string data;
	data.assign((std::istreambuf_iterator<char>(in.rdbuf())), std::istreambuf_iterator<char>());
	in.close();
	return data;
}

//Transform chars in string to lower registrer 
inline void transform_lregister(std::string & data)
{
	 std::transform(data.begin(), data.end(), data.begin(), ::tolower);
}

char illigalchar_to_transfer(char & elem)
{
	if (!isalpha(elem))
		return '\n';
	return elem;	
}

//Transform space in string to '\n' 
void transform_illigalchar_to_transfer(std::string & data)
{
	 std::transform(data.begin(), data.end(), data.begin(), illigalchar_to_transfer);
}


int	main(int argc, char const *argv[])
{	
	setlocale(LC_ALL, "");	
	//Reсeive text to the string (text)
	std::string text = GetText("test_text.txt");
	//Transform chars in string(text) to lower registrer
	transform_lregister(text);

	//Replace inconvenient simbols with "mask.cpp" value(space in this case)
	//std::stringstream inputStringStream(text);
	//inputStringStream.imbue(std::locale(inputStringStream.getloc(), std::unique_ptr<ReplaceList>(new ReplaceList).release()));
	//std::cout << text << std::endl;

	//Replace illigal characters with \n 
	transform_illigalchar_to_transfer(text);

	//Create the text_for_stemming.txt
	std::ofstream data_out("text_for_stemming.txt");
  	data_out << text;
    data_out.close(); // закрываем файл
	return 0;
}