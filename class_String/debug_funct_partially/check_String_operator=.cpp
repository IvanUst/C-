#include "String.cpp"

int main(int argc, char const *argv[])
{	
	M_String ex1 = M_String("Prototipe\0");
	//std::cout << "ex1 = " << ex1 << std::endl;
	M_String ex2;
	std::cout << "ex2 = " << ex2 << std::endl;
	//Operator=
	//string (1)	
	//*
	ex2 = ex1;
	std::cout << "After ex2 = ex1: ex2 = " << ex2 << std::endl;
	//c-string (2)	
	char s[] = "Hello";
	ex2 = s;
	std::cout << "After ex2 = Hello: ex2 = " << ex2 << std::endl;
	//character (3)	
	ex2 = 'c';
	std::cout << "After ex2 = 'c': ex2 = " << ex2 << std::endl;
	
	//ex1.M_String::~M_String();
	//ex2.M_String::~M_String();
	return 0;
}