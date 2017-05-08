#include "String.cpp"

int main(int argc, char const *argv[])
{
	M_String ex1 ("Test string");
	M_String ex2 ("gnirts tseT");
	const char *s;

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "s = ex1.c_str()" << std::endl;
	s = ex1.c_str();
	std::cout << "s = " << '"' << s << '"' << std::endl << std::endl;

	char s_buff[11];
	ex1 = "()";

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "After ex1.copy(s_buff, 2, 0)" << std::endl;
	ex1.copy(s_buff, 2, 0);
	std::cout << "s_buff = " << '"' << s_buff << '"' << std::endl << std::endl;

	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "ex2 = " << ex2 << std::endl;
	std::cout << "After swap(ex1, ex2)" << std::endl;
	swap(ex1, ex2);
	std::cout << "ex1 = " << ex1 << std::endl;
	std::cout << "ex2 = " << ex2 << std::endl << std::endl;


	return 0;
}