#include "String.cpp"

int main(int argc, char const *argv[])
{
	M_String ex1 ("Test string");

	std::cout << "ex1[2] " << ex1[2] << std::endl;
	std::cout << "ex1.at(7) = " << ex1.at(7) << std::endl;
	std::cout << "ex1.back() = " << ex1.back() << std::endl;
	std::cout << "ex1.front() = " << ex1.front() << std::endl << std::endl;

	std::cout << "After ex1[0] = 't'" << std::endl;
	ex1[0] = 't';
	std::cout << "ex1 = " << ex1 << std::endl << std::endl;

	std::cout << "After ex1.at(0) = 'T' and ex1.at(10) = 'G'" << std::endl;
	ex1.at(0) = 'T';
	ex1.at(10) = 'G';
	std::cout << "ex1 = " << ex1 << std::endl << std::endl;

	std::cout << "After ex1.front() = '!'" << std::endl;
	ex1.front() = '!';
	std::cout << "ex1 = " << ex1 << std::endl << std::endl;

	std::cout << "After ex1.back() = '!'" << std::endl;
	ex1.back() = '!';
	std::cout << "ex1 = " << ex1 << std::endl << std::endl;

	return 0;
}