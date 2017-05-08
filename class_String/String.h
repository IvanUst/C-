#ifndef String_H_
#define String_H_

class M_String
{
	char* str;
	size_t str_size;
public:
//CONSTRUSTORS

	//default (1)
	//Constructs an empty string, with a length of zero characters.	
	M_String();

	//copy (2)
	//Constructs a copy of str.
	M_String (const M_String& str);

	//subM_String (3)	
	//Copies the portion of str that begins at the character position pos and spans len characters 
	//(or until the end of str, if either str is too short or if len is string::npos).
	M_String (const M_String& str, size_t pos, size_t len = -1);

	//from c-M_String (4)
	//Copies the null-terminated character sequence (C-string) pointed by s.	
	M_String (const char* s);

	//from buffer (5)
	//Copies the first n characters from the array of characters pointed by s.	
	M_String (const char* s, size_t n);

	//fill (6)	
	//Fills the string with n consecutive copies of character c.
	M_String (size_t n, char c);
//DESTRUCTOR
	~M_String();
//OPERATORS
	//Operator=
	//Assigns a new value to the string, replacing its current contents.
	
	//string (1)	
	M_String& operator= (const M_String& str);
	
	//c-string (2)	
	M_String& operator= (const char* s);
	
	//character (3)	
	M_String& operator= (char c);

//INPUT/OUTPUT
	friend std::ostream& operator<<(std::ostream & os, const M_String & arg);
	friend std::istream& operator>> (std::istream& is, M_String& str);

//Capacity:
	size_t length() const; 
	//Returns the length of the string, in terms of bytes.
	
	size_t size() const;
	//The same as length
	
	size_t max_size() const;
	//Returns the maximum length the string can reach.
	
	void resize (size_t n, char c = char(NULL));
	//Resizes the string to a length of n characters(if n <str.length str become shorter)
	
	size_t capacity() const;
	//Return size of allocated storage

	void reserve (size_t n = 0);
	//Request a change in capacity
	
	void clear();
	//Erases the contents of the string, which becomes an empty string (with a length of 0 characters).

	bool empty() const;
	//Returns whether the string is empty 

//Element access:
	char& operator[] (size_t pos);
	//Returns a reference to the character at position pos in the string.
	
	char& at (size_t pos);
	//Returns a reference to the character at position pos in the string.
	
	char& back();
	//Returns a reference to the last character of the string.
	
	char& front();
	//Returns a reference to the first character of the string.

//Modifiers:
	//operator+=
	//Extends the string by appending additional characters at the end of its current value:

	//string (1)	
	M_String& operator+= (const M_String& str);
	//c-string (2)	
	M_String& operator+= (const char* s);
	//character (3)	
	M_String& operator+= (char c);

	//insert()
	//Inserts additional characters into the string right before the character indicated by pos (or p):

	//string (1)	
	M_String& insert (size_t pos, const M_String& str);
	//c-string (3)	
	M_String& insert (size_t pos, const char* s);

	//erase
	//Erases the portion of the string value that begins at the character position pos and spans len characters 
	//(or until the end of the string, if either the content is too short or if len is string::npos.
	M_String& erase (size_t pos = 0, size_t len = -1);

//String operations:
	const char* c_str() const;
	//Returns a pointer to an array that contains a null-terminated sequence of characters
	size_t copy (char* s, size_t len, size_t pos = 0) const;

	friend void swap (M_String& x,M_String& y);
	//Exchanges the content of the container by the content of str, which is another string object. Lengths may differ.
};

//Subsidiary fuctions
//Copy in_size characters from one char* to another
void full_copy(char* in, const char* out, const size_t& in_size)
{
	for (size_t i = 0; i < in_size; ++i)
	{
		in[i] = out[i];
	}
}
//Find the length on NULL-terminated char* 
size_t c_M_String_length(const char* s)
{
	size_t size = 0;
	while(s[size] != (char)NULL)
		size++;
	return size;
}



#endif