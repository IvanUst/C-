#include "String.cpp"

int main(int argc, char const *argv[])
{
	M_String ex1();
	std::cout << "ex1 = " << ex1 << std::endl;

	char s[] = "Hello!";
	M_String ex4("Hello man");
	std::cout << "ex4 = " << ex4 << std::endl;

	M_String ex2(ex4);
	std::cout << "ex2 = " << ex2 << std::endl;

	M_String ex3(ex4, 3, 2);
	std::cout << "ex3 = " << ex3 << std::endl;

	M_String ex5(s, 3);
	std::cout << "ex5 = " << ex5 << std::endl;

	M_String ex6(5, 'z');
	std::cout << "ex6 = " << ex6 << std::endl;


	return 0;
}