#include "complex.cpp"


int main(int argc, char const *argv[])
{	
	std::cout << "Конструирование объектов класса Complex:" << std::endl; 
	
	std::cout << "\t";
	std::cout << "Конструктор по умолчанию" << std::endl;
	Complex object1;
	std::cout << "\t";
	std::cout << "object1 = "; 
	std::cout << object1;

	std::cout << "\n\t";
	std::cout << "Конструктор инициализация(re, im)" << std::endl;
	Complex object2(1,1);
	std::cout << "\t";
	std::cout << "object2 = "; 
	std::cout << object2;

	std::cout << "\n\t";
	std::cout << "Конструктор копирования" << std::endl;
	Complex object3(object2);
	std::cout << "\t";
	std::cout << "object3 = "; 
	std::cout << object3;

	std::cout << "\n\nПереопределение\n";
	std::cout << "\t";
	std::cout << "object3 = "; 
	std::cout << object3;
	std::cout << "\n";
	object3.set(2,2);
	std::cout << "\t";
	std::cout << "object3 = "; 
	std::cout << object3;
	std::cout << std::endl;

//Арифметические операции
	std::cout  << "\n\t\tАрифметические операции" << std::endl;

	std::cout  << "Сложение:\t";
	std::cout << object2;
	std::cout << "  +  ";
	std::cout << object3;
	object1 = object2 + object3;
	std::cout << "  =  ";
	std::cout << object1; 
	std::cout << std::endl;

	std::cout << "Вычитание:\t";
	std::cout << object2;
	std::cout << "  -  ";
	std::cout << object3;
	object1 = object2 - object3;
	std::cout << "  =  ";
	std::cout << object1; 
	std::cout << std::endl;

	std::cout << "Сопряжение:\t";
	std::cout << object1;
	std::cout << " ---> ";
	object1.mate();
	std::cout << object1; 
	std::cout << std::endl;

	std::cout << "Умножение:\t";
	std::cout << object1;
	std::cout << "  *  ";
	std::cout << object3;
	object2 = object1 * object3;
	std::cout << "  =  ";
	std::cout << object2; 
	std::cout << std::endl;

	std::cout << "Деление:\t";
	std::cout << object3;
	std::cout << "  /  ";
	std::cout << object2;
	object1 = object3 / object2;
	std::cout << "  =  ";
	std::cout << object1; 
	std::cout << std::endl;

//Составное присваивание
	std::cout  << "\n\t\tСоставное присваивание" << std::endl;
	
	std::cout << "a += b:\t";
	std::cout << object1;
	std::cout << "  +=  ";
	std::cout << object2;
	object1 += object2;
	std::cout << " \t a =  ";
	std::cout << object1; 
	std::cout << std::endl;	

	std::cout << "a -= b:\t";
	std::cout << object3;
	std::cout << "  -=  ";
	std::cout << object2;
	object3 -= object2;
	std::cout << " \t a =  ";
	std::cout << object3; 
	std::cout << std::endl;	

	std::cout << "a *= b:\t";
	std::cout << object3;
	std::cout << "  *=  ";
	std::cout << object1;
	object3 *= object1;
	std::cout << " \t a =  ";
	std::cout << object3; 
	std::cout << std::endl;

	std::cout << "a /= b:\t";
	std::cout << object1;
	std::cout << "  /=  ";
	std::cout << object3;
	object1 /= object3;
	std::cout << " \t a =  ";
	std::cout << object1; 
	std::cout << std::endl;		
	return 0;	
}