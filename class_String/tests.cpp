#include "String.cpp"
#include <string>
#include <cstring>
#include <gtest/gtest.h>

//CONSTRUSTORS 
// Tests the default c'tor. 
/*TEST(MStringConstructor, DefaultConstructor) {
  	M_String ex();
	//Value test (NULL)
	EXPECT_STREQ(NULL, ex.c_str());
	//Size test (0)
	EXPECT_EQ(0, ex.size());
}*/

// Tests the c'tor that accepts a C string.
const char char_liter[] = "Hello, world!";

TEST(MStringConstructor, ConstructorFromCString) {
  const M_String ex(char_liter);
  EXPECT_EQ(0, strcmp(ex.c_str(), char_liter));
  EXPECT_EQ(sizeof(char_liter)/sizeof(char_liter[0]) - 1, ex.length());
  std::cout << std::endl;
}

// Tests the copy c'tor.
TEST(MStringConstructor, CopyConstructor) {
  M_String s1(char_liter);
  M_String s2(s1);
  s2 = char_liter;
  EXPECT_EQ(0, strcmp(s2.c_str(), s1.c_str()));
  EXPECT_EQ(0, s2.size() - s1.size());
}

//MEMBER FUNCTIONS

class MStringTest : public ::testing::Test
{
  protected:
  M_String mystring1;
  M_String mystring2;
  M_String mystringtmp;

  virtual void SetUp()
  {      
    mystring1 = "0123456789";
   	mystring2 = "|||||";  
    mystringtmp = "";
  }

  virtual void TearDown()
  {
  }
};

//Operator=
TEST_F(MStringTest, OperatorEquasion) {
	//string (1)	
 	mystringtmp = mystring1;
  	EXPECT_EQ(0, strcmp(mystringtmp.c_str(), mystring1.c_str()));
  	EXPECT_EQ(mystringtmp.size(), mystring1.size());

  	//c-string (2)	
  	const char s[] = "Hello";
  	mystringtmp = s;
  	EXPECT_EQ(0, strcmp(mystringtmp.c_str(), s));
  	EXPECT_EQ(mystringtmp.size(), c_M_String_length(s));

  	//character (3)
  	mystringtmp = 'z';
  	EXPECT_EQ(1, mystringtmp.c_str()[0] == 'z');
  	EXPECT_EQ(mystringtmp.size(), 1);
  	std::cout << std::endl;
}

//Capacity:
TEST_F(MStringTest, capacity) {
	//lemgth	
  	EXPECT_EQ(10, mystring1.length());

  	//size
  	EXPECT_EQ(5, mystring2.size());

  	//character (3)
  	mystring1.clear();
  	EXPECT_EQ(1, mystring1.c_str()[0] == (char)NULL);
	EXPECT_EQ(mystring1.size(), 0);
	EXPECT_EQ(mystring1.empty(), 1);
	std::cout << std::endl;
}

//Element access
TEST_F(MStringTest, Elementaccess) {
	//operator[]
  	EXPECT_EQ(1, mystring1[2] == '2');
  	EXPECT_EQ(1, mystring1[7] == '7');  	

  	//at
  	EXPECT_EQ(1, mystring1.at(3) == '3');
  	EXPECT_EQ(1, mystring1.at(9) == '9');  

  	//back
  	EXPECT_EQ(1, mystring1.back() == '9');

  	//front
	EXPECT_EQ(1, mystring1.front() == '0');
	std::cout << std::endl;
}

//Modifiers

TEST_F(MStringTest, Modifiers) {
	//operator +=
	mystring2 += mystring1;
  	EXPECT_EQ(0, strcmp(mystring2.c_str(), "|||||0123456789"));
  
  	//insert
  	mystring2 = "()";
  	mystring2.insert(1, mystring1);
  	EXPECT_EQ(0, strcmp(mystring2.c_str(), "(0123456789)"));

  	//erase
  	mystring2.erase(3, 7);
  	EXPECT_EQ(0, strcmp(mystring2.c_str(), "(019)"));
  	std::cout << std::endl;
}

//String_operation
TEST_F(MStringTest, StringOperation) {
	//c_str
  	EXPECT_EQ(0, strcmp(mystring2.c_str(), "|||||"));
  
  	//copy
  	char buff[6];
  	buff[5] = (char)NULL;
  	EXPECT_EQ(5, mystring1.copy(buff, 5));
  	EXPECT_EQ(0, strcmp(buff, "01234"));
  	std::cout << std::endl;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

