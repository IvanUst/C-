#include <iostream>
#include "String.h"


//CONSTRUCTORS
//default (1)	
M_String::M_String()
{	
	str = new char[1];
	str[0] = (char)NULL;
	str_size = 0;
}

//copy (2)	
M_String::M_String(const M_String & arg)
{
	str_size = arg.length();
	str = new char[str_size];
	full_copy(str, arg.str, str_size);
}

//sub M_String (3)	
M_String::M_String (const M_String& arg, size_t pos, size_t len)
{
	if (len == -1)
	{
		str_size = arg.length() + 1 - pos;
		str = new char[str_size];
		for (size_t i = 0; i < str_size; ++i)
		{
			str[i] = arg.str[i+pos];
		}
	}else
	{
		str_size = len + 1;
		str = new char[str_size];
		for (size_t i = 0; i < str_size - 1; ++i)
		{
			str[i] = arg.str[i+pos];
		}
		str[str_size - 1] = (char)NULL;
	}
}

//from c-M_String (4)	
M_String::M_String (const char* s)
{	
	str_size = c_M_String_length(s);
	str = new char[str_size + 1];
	full_copy(str, s, str_size);
	str[str_size] = char(NULL);
}	

//from buffer (5)	
M_String::M_String (const char* s, size_t n)
{
	str = new char[n+1];
	full_copy(str, s, n);
	str[n] = (char)NULL;
	str_size = n;
}

//fill (6)	
M_String::M_String (size_t n, char c)
{
	str = new char[n];
	for (size_t i = 0; i < n; ++i)
	{
		str[i] = c;	
	}
	str[n] = char(NULL);
	str_size = n;
}

//DESTRUCTOR
M_String::~M_String()
{	
	if(this->str_size == 0)
		delete str;
	else
		delete []str;
}

//OPERATORS
////Operator=
	//string (1)	
	M_String& M_String::operator= (const M_String& arg)
	{
		delete [] this->str;
		this->str_size = arg.length();
		this->str = new char[this->str_size+1];
		full_copy(this->str, arg.str, this->str_size+1);
		return *this;
	}
	//c-string (2)	
	M_String& M_String::operator= (const char* s)
	{
		this->str_size = c_M_String_length(s);
		delete [] this->str;
		this->str = new char[this->str_size + 1];
		full_copy(this->str, s, this->str_size +1);	
		return *this;
	}
	//character (3)	
	M_String& M_String::operator= (char c)
	{
		delete [] this->str;
		this->str_size = 1;
		this->str = new char[2];
		this->str[0] = c;
		this->str[1] = char(NULL);
		return *this;
	}

std::ostream& operator<<(std::ostream & os, const M_String & arg)
{	
	os << arg.str;		
	return os;				
}

std::istream& operator>> (std::istream& is, M_String& arg)
{	
	char tmp[256];
	is >> tmp;
	arg  = tmp;
	return is;
}
//Capacity:
	size_t M_String::length() const
	{
		return this->str_size;
	}

	size_t M_String::size() const
	{
		return this->str_size;
	}

	size_t M_String::max_size() const
	{
		return 184467;
	}

	void M_String::resize (size_t n, char c)
	{	
		if(n == this->str_size)
			return;
		char* tmp_str;
		if(n < this->str_size)
		{
			tmp_str = new char[n+1];
			full_copy(tmp_str, this->str, n);
			delete [] this->str;
			this->str = tmp_str;
			this->str[n] = char(NULL);
			this->str_size = n;
			return;
		}else
		{
			tmp_str = new char[n+1];
			full_copy(tmp_str, this->str, this->str_size);
			delete []str;
			this->str = tmp_str;
			size_t i = this->str_size;
			while(i < n)
			{

				this->str[i] = c;
				i++;
			}	
			this->str[n] = char(NULL);
			this->str_size = n;
		}
	}

	size_t M_String::capacity() const
	{
		return sizeof(*this);
	}
	void M_String::clear()
	{
		delete [] this->str;
		this->str = new char[1];
		this->str[0] = char(NULL);
		this->str_size = 0;
	}
	bool M_String::empty() const
	{
		return bool(!this->str_size);
	}

//Element access
	char& M_String::operator[] (size_t pos)
	{	
		if(pos < this->str_size)
			return this->str[pos];
	}
	char& M_String::at (size_t pos)
	{	
		if(pos < this->str_size)
			return this->str[pos];
	}
	char& M_String::back()
	{
		return this->str[this->str_size - 1];
	}
	char& M_String::front()
	{
		return this->str[0];
	}
//Modifiers
	//operator+=
	//string (1)	
	M_String& M_String::operator+= (const M_String& arg)
	{
		size_t i = this->str_size;
		size_t j = 0;
		this->resize(this->str_size + arg.str_size);
		while(i < this->str_size)
		{
			this->str[i] = arg.str[j];
			i++;
			j++;
		}
		return *this;
	}
	//c-string (2)	
	M_String& M_String::operator+= (const char* s)
	{
		size_t i = this->str_size;
		size_t j = 0;
		this->resize(this->str_size + c_M_String_length(s));
		while(i < this->str_size)
		{
			this->str[i] = s[j];
			i++;
			j++;
		}
		this->str[this->str_size] = char(NULL); 
		return *this;
	}
	//character (3)	
	M_String& M_String::operator+= (char c)
	{
		this->resize(this->str_size + 1, c);
		return *this;
	}

	//insert()
	//string (1)	
	M_String& M_String::insert (size_t pos, const M_String& str)
	{	
		char tmp_left[pos+1];
		tmp_left[pos] = char(NULL);
		char tmp_rigth[this->str_size - pos + 1];
		tmp_rigth[this->str_size - pos] = char(NULL);
		this->copy(tmp_left, pos);
		this->copy(tmp_rigth, this->str_size - pos, pos);
		this->clear();
		*this += tmp_left;
		//std::cout << "*this = " << *this << std::endl;
		*this += str;
		//std::cout << "*this = " << *this << std::endl;
		*this += tmp_rigth;
		//std::cout << "*this = " << *this << std::endl;

		return *this;
	}
	//c-string (2)	
	M_String& M_String::insert (size_t pos, const char* s)
	{
		char tmp_left[pos+1];
		tmp_left[pos] = char(NULL);
		char tmp_rigth[this->str_size - pos + 1];
		tmp_rigth[this->str_size - pos] = char(NULL);
		this->copy(tmp_left, pos);
		this->copy(tmp_rigth, this->str_size - pos, pos);
		this->clear();
		//std::cout << "*this = " << *this << std::endl;
		*this += tmp_left;
		//std::cout << "*this = " << *this << std::endl;
		*this += s;
		//std::cout << "*this = " << *this << std::endl;
		*this += tmp_rigth;
		return *this;
	}

	//erase
	M_String& M_String::erase (size_t pos, size_t len)
	{
		if(pos > this->str_size)
		{
			return *this;
		}

		char tmp_left[pos+1];
		tmp_left[pos] = (char)NULL; 


		size_t right_size = 0;

		if(len <= this->str_size - pos)
			right_size = this->str_size - pos - len;
		
		char tmp_rigth[right_size + 1];
		tmp_rigth[right_size] = (char)NULL;
		
		this->copy(tmp_left, pos);
		this->copy(tmp_rigth, right_size + 1, pos + len);
		this->clear();
		//std::cout << "*this = " << *this << std::endl;
		*this += tmp_left;
		//std::cout << "*this = " << *this << std::endl;
		*this += tmp_rigth;
		//std::cout << "*this = " << *this << std::endl;
		return *this;
	}

//String operations:
	const char* M_String::c_str() const
	{
		return this->str;
	}

	size_t M_String::copy (char* s, size_t len, size_t pos) const
	{
		size_t i = 0;
		while((i < len) && (pos+i < this->str_size))
		{
			s[i] = this->str[pos+i];
			i++;
		}
		return i;
	}

	void swap (M_String& x, M_String& y)
	{
		char *tmp;
		size_t tmp_size;
		tmp = x.str;
		tmp_size = x.str_size;
		x.str = y.str;
		x.str_size = y.str_size;
		y.str = tmp;
		y.str_size = tmp_size;
	}