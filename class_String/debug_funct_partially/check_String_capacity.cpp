#include "String.cpp"

int main(int argc, char const *argv[])
{
	M_String ex1 ("Test string");

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "ex1.length() = " << ex1.length() << std::endl << std::endl;

	ex1 = "Test string1";
	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "ex1.size() = " << ex1.size() << std::endl << std::endl;

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "After  ex1.resize(ex1.size()+3, 'z');"<< std::endl;
	ex1.resize(ex1.size()+3, 'z');
	std::cout << "ex1 = " << ex1 << std::endl << std::endl;


	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "ex1.capacity() = " << ex1.capacity() << std::endl << std::endl;

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "After ex1.clear()" << std::endl;
	ex1.clear();
	std::cout << "ex1 = " << ex1 << std::endl << std::endl;


	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "ex1.empty() = " << ex1.empty() << std::endl << std::endl;
	
	return 0;
}