#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>


class Complex
{
	float m_re;
	float m_im;
public:
//Демонстрация
	friend std::ostream & operator<<(std::ostream & os, const Complex & arg);
//Переопредеелние
	void set(); 
	void set(float re, float im);
//Конструктоыры
	Complex(float re = 0,  float im = 0);
	Complex(const Complex & prot);
	
//Арифметические операторы
	//Присваивание a = b
		const Complex & operator=(const Complex &);
	//Сложение a + b
		const Complex operator+(const Complex &)const;
	//Вычитание
		const Complex operator-(const Complex &)const;
	//Сопряжение
		const Complex & mate();
	//Умножение
		const Complex operator*(const Complex &)const;
	//Деление
		const Complex operator/(const Complex &)const;
//Составное присваивание
	// a += b
		const Complex & operator+=(const Complex &);
	// a -= b
		const Complex & operator-=(const Complex &);
	// a *= b
		const Complex & operator*=(const Complex &);
	// a /= b
		const Complex & operator /=(const Complex &);
};	
#endif