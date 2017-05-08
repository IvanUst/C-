#include "String.cpp"

int main(int argc, char const *argv[])
{
	M_String ex1 ("Test string");
	M_String ex2 ("gnirts tseT");

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "ex2 = " << ex2 << std::endl;
	std::cout << "After ex1 += ex2" << std::endl;
	ex1 += ex2;
	std::cout << "ex1 = " << ex1 << std::endl << std::endl;

	std::cout << "ex2 = " << ex2 << std::endl;
	char s[] = "!!!";
	std::cout << "s = " << s << std::endl;
	std::cout << "After ex2 += s" << std::endl;
	ex2 += s;
	std::cout << "ex2 = " << ex2 << std::endl << std::endl;

	std::cout << "ex2 = " << ex2 << std::endl;
	std::cout << "After ex2 += 'z'" << std::endl;
	ex2 += 'z';
	std::cout << "ex2 = " << ex2 << std::endl << std::endl;

	M_String ex3 ("()");

	std::cout << "ex2 = " << ex2 << std::endl;
	std::cout << "ex3 = " << ex3 << std::endl;
	std::cout << "After ex3.insert(1, ex2)" << std::endl;
	ex3.insert(1, ex2);
	std::cout << "ex3 = " << ex3 << std::endl << std::endl;

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "s = " << s << std::endl;
	std::cout << "After ex1.insert(11, s)" << std::endl;
	ex1.insert(11, s);
	std::cout << "ex1 = " << ex1 << std::endl << std::endl;

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "After ex1.erase(11, 20)" << std::endl;
	ex1.erase(11, 20);
	std::cout << "ex1 = " << ex1 << std::endl << std::endl;
	
	return 0;
}