#ifndef _STRING_H_
#define _STRING_H_

#include <cstring>

class String
{
public:

	String() : str(nullptr), num_chars(0) {}


	String(const char *string) : num_chars(strlen(string)), str(new char[num_chars + 1])
	{
		strcpy_s(str, num_chars + 1, string);
	}


	String(const String &string) : num_chars(string.num_chars), str(new char[num_chars + 1])
	{
		strcpy_s(str, num_chars + 1, string.str);
	}

	~String()
	{
		delete[] str;
	}

public:

	bool empty() const
	{
		return num_chars == 0;
	}

	unsigned int size() const
	{
		return num_chars;
	}

	void clear()
	{
		delete[] str;
		str = nullptr;
		num_chars = 0;
	}

	const char *return_string() const
	{
		return str;
	}

public:

	void operator= (const String &string)
	{
		delete[] str;
		num_chars = string.num_chars;
		str = new char[num_chars + 1];
		strcpy_s(str, num_chars + 1, string.str);
	}

	void operator+= (const String &string)
	{
		int new_num_chars = num_chars + string.num_chars;
		char *new_str = new char[new_num_chars + 1];

		strcpy_s(new_str, new_num_chars + 1, str);
		strcat_s(new_str, new_num_chars + 1, string.str);

		delete[] str;
		num_chars = new_num_chars;
		str = new_str;
	}
	 
	String operator+ (const String &string) const
	{
		String stringsum(str);
		stringsum += string;
		return stringsum;
	}

	bool operator== (const String &string)
	{
		return strcmp(str, string.str) == 0;
	}

	bool operator!= (const String &string)
	{
		return strcmp(str, string.str) != 0;
	}

private:

	unsigned int num_chars = 0;
	char *str = nullptr;
};

#endif // _STRING_H_