#include "complex.h"

std::ostream & operator<<(std::ostream & os, const Complex & arg)

{
	os << arg.m_re << " + ";
	os << arg.m_im << "i";
	return os;
}

//Constructors
Complex::Complex(float re, float im)
{
	m_re = re;
	m_im = im;
}

Complex::Complex(const Complex & prot)
{
	m_re = prot.m_re;
	m_im = prot.m_im;
}

void Complex::set()
{	
	std::cout << "Enter complex number\n\tRe = ";
	std::cin >> this->m_re;
	std::cout << "\tIm = ";
	std::cin >> this->m_im;
}

void Complex::set(float re, float im)
{	
	this->m_re = re;
	this->m_im = im;
}

//Arithmetic operations
	// a = b
		const Complex & Complex::operator =(const Complex & arg)
		{	
			this->m_re = arg.m_re;
			this->m_im = arg.m_im;
			return *this;			
		}	
	// a + b
		const Complex Complex::operator +(const Complex & arg)const
		{
			Complex tmp;
			tmp.m_re = this->m_re + arg.m_re;
			tmp.m_im = this->m_im + arg.m_im;
			return tmp;			
		}
	//subtraction
		const Complex Complex::operator -(const Complex & arg)const
		{
			Complex tmp;
			tmp.m_re = this->m_re - arg.m_re;
			tmp.m_im = this->m_im - arg.m_im;
			return tmp;			
		}
	
	//mate
		const Complex & Complex::mate()
		{
			this->m_im = -this->m_im;
			return *this;
		}
	//multiplication
		const Complex Complex::operator *(const Complex & arg)const
		{
			Complex tmp;
			tmp.m_re = (this->m_re * arg.m_re) - (this->m_im * arg.m_im);
			tmp.m_im = ((this->m_re * arg.m_im) + (arg.m_re * this->m_im));
			return tmp;
		}
	//devision
		const Complex Complex::operator /(const Complex & arg)const
		{
			Complex tmp = arg;
			tmp = *this * (tmp.mate());
			tmp.m_re = tmp.m_re/(arg.m_re*arg.m_re + arg.m_im*arg.m_im);
			tmp.m_im = tmp.m_im/(arg.m_re*arg.m_re + arg.m_im*arg.m_im);
			return tmp;
		}

//Составное присваивание
	// a += b
		const Complex & Complex::operator +=(const Complex & arg)
		{
			*this = *this + arg;
			return *this;
		}
	// a -= b
		const Complex & Complex::operator -=(const Complex & arg)
		{
			*this = *this - arg;
			return *this;
		}
	// a *= b
		const Complex & Complex::operator *=(const Complex & arg)
		{
			*this = *this * arg;
			return *this;
		}
	// a /= b
		const Complex & Complex::operator /=(const Complex & arg)
		{
			*this = *this / arg;
			return *this;
		}
