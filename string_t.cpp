#include "string_t.h"
#include <ctype.h>
#include <string.h>
#include <iostream>

#define STR_INITIAL_SIZE 128
#define STR_EQUAL 0
#define STR_LESS_THEN_PARAM 1
#define STR_GREATER_THEN_PARAM 2

using namespace std;

//FIXME add checks

int String_t::m_numOfStrings = 0;

String_t::String_t()
{
	//FIXME CreateString()
	m_chars = new char[STR_INITIAL_SIZE];
	m_chars[0] = 0;
	m_currSize = STR_INITIAL_SIZE;
	++m_numOfStrings;
}

String_t::String_t(const char* _str)
{
	int strLen = strlen(_str);
	m_chars = new char[strLen + 1];
	strcpy(m_chars, _str);
	m_currSize = strLen;
	++m_numOfStrings;
}

String_t::String_t(const String_t& _str)
{
	int strLen = _str.length();
	m_chars = new char[strLen + 1];
	//FIXME can address private members here since it's the same class
	strcpy(m_chars, _str.getString());
	m_currSize = strLen;
	++m_numOfStrings;
}

String_t::~String_t()
{
	delete[] m_chars;
	m_chars = 0;
	++m_numOfStrings;
}

const String_t& String_t::operator=(const String_t& _str)
{
	if(&_str != this)
	{
		ReallocIfNeed(_str.length() + 1);
		
		strcpy(m_chars, _str.getString());
	}
	
	return *this;
}

int String_t::length() const
{
	return strlen(m_chars);
}

void String_t::setString(const char* _str)
{
	ReallocIfNeed(strlen(_str) + 1);
	strcpy(m_chars, _str); 
}

const char* String_t::getString() const
{
	return m_chars;
}

int String_t::compare(const String_t& _str) const
{
	int res = strcmp(this->m_chars, _str.getString());
	
	//FIXME ternary here
	if(res == 0)
	{
		return 0;
	}
	else if(res > 0)
	{
		return STR_GREATER_THEN_PARAM;
	}
	else // if(res < 0)
	{
		return STR_LESS_THEN_PARAM;
	}
}

void String_t::print() const
{
	cout << m_chars;
}

void String_t::toUpper() 
{
	for(int i = 0, n = strlen(m_chars); i < n; i++)
	{
		m_chars[i] = toupper(m_chars[i]);
	}
}

void String_t::toLower()
{
	for(int i = 0, n = strlen(m_chars); i < n; i++)
	{
		m_chars[i] = tolower(m_chars[i]);
	}
}

const String_t& String_t::operator+=(const String_t& _str)
{	
	char* newChars = new char[strlen(m_chars) + strlen(_str.m_chars) + 1];
	
	strcpy(newChars, m_chars);
	strcat(newChars, _str.m_chars);
	delete[] m_chars;
	m_chars = newChars;
	
	return *this;
}

void String_t::prepend(const String_t& _str)
{
	return prepend(_str.m_chars);
}

void String_t::prepend(const char* _str)
{
	char* newChars = new char[strlen(m_chars) + strlen(_str) + 1];
	
	strcpy(newChars, _str);
	strcat(newChars, m_chars);
	delete[] m_chars;
	m_chars = newChars;
}

bool String_t::operator>(const String_t& _str) const
{
	return strcmp(m_chars, _str.m_chars) > 0 ? true : false;
}

bool String_t::operator<(const String_t& _str) const
{
	return strcmp(m_chars, _str.m_chars) < 0 ? true : false;
}

bool String_t::operator>=(const String_t& _str) const
{
	return strcmp(m_chars, _str.m_chars) >= 0 ? true : false;
}

bool String_t::operator<=(const String_t& _str) const
{
	return strcmp(m_chars, _str.m_chars) <= 0 ? true : false;
}

bool String_t::operator==(const String_t& _str) const
{
	return strcmp(m_chars, _str.m_chars) == 0 ? true : false;
}

bool String_t::operator!=(const String_t& _str) const
{
	return strcmp(m_chars, _str.m_chars) != 0 ? true : false;
}

bool String_t::contains(const String_t& _str) const
{
	return strstr(m_chars, _str.m_chars) == NULL ? false : true;
}

bool String_t::contains(const char* _str) const
{
	return strstr(m_chars, _str) == NULL ? false : true;
}

char String_t::operator[](int i) const
{
	if(i < (int)strlen(m_chars))
	{
		return m_chars[i];
	}
	else
	{
		return 0;
	}
}

ostream& operator<<(ostream& _os, const String_t& _str)
{
	_os << _str.getString();
	
	return _os;
}

istream& operator>>(istream& _is, String_t& _str)
{
	char chars[128];//FIXME
	
	_is >> chars;
	
	_str.setString(chars);
	
	return _is;
}

int String_t::getNumOfStrings()
{
	return m_numOfStrings;
}

void String_t::ReallocIfNeed(int _newSize)
{
	if(_newSize > m_currSize)
	{
		delete[] m_chars;
		m_chars = new char[_newSize + 1];
		m_currSize = _newSize + 1;
	}
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
