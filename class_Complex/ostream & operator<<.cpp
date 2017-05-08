#include <iostream>
#include <ostream>

class Complex
{
	float m_re;
	float m_im;
public:
//Демонстрация
	friend std::ostream & operator<<(std::ostream & os, const Complex & arg);
	Complex(float re = 0,  float im = 0);
};	

std::ostream & operator<<(std::ostream & os, const Complex & arg)

{
	os << arg.m_re << " + ";
	os << arg.m_im << "i";
	return os;
}

//Констукторы
Complex::Complex(float re, float im)
{
	m_re = re;
	m_im = im;
}

int main(int argc, char const *argv[])
{
	Complex c1(1,1);
	std::cout << c1;
	return 0;
}
