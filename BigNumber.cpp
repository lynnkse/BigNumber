#include "BigNumber.h"
#include "string_t.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define MAX_INT_LEN 11
#define DECIMAL 10

using namespace std;

BigNumber::BigNumber():m_num("0")
{}

BigNumber::BigNumber(const char* _num):m_num(_num)
{}

BigNumber::BigNumber(int _num)
{
	char buffer[MAX_INT_LEN];
	sprintf(buffer, "%d", _num);
	m_num.setString(buffer);
}

BigNumber::BigNumber(const BigNumber& _num):m_num(_num.m_num)
{}

BigNumber::~BigNumber()
{}

const BigNumber& BigNumber::operator=(const BigNumber& _num)
{
	m_num.setString(_num.m_num.getString());

	return *this;
}

const BigNumber& BigNumber::operator=(int _num)
{
	char buffer[MAX_INT_LEN];
	sprintf(buffer, "%d", _num);
	m_num.setString(buffer);

	return *this;
}

const String_t& BigNumber::GetNumString() const
{
	return m_num;
}

bool BigNumber::operator==(const BigNumber& _num) const
{
	return this->m_num == _num.GetNumString();
}

bool BigNumber::operator>(const BigNumber& _num) const
{
	int firstLen = this->m_num.length();
	int secondLen = _num.GetNumString().length();
	bool result;	

	if(firstLen > secondLen)
	{
		result = true;
	}
	else if(firstLen < secondLen)
	{
		result = false;
	}
	else
	{
		result = (this->m_num > _num.GetNumString());
	}

	return result;
}

bool BigNumber::operator<(const BigNumber& _num) const
{
	int firstLen = this->m_num.length();
	int secondLen = _num.GetNumString().length();
	bool result;	

	if(firstLen < secondLen)
	{
		result = true;
	}
	else if(firstLen > secondLen)
	{
		result = false;
	}
	else
	{
		result = (this->m_num < _num.GetNumString());
	}

	return result;
}

BigNumber& BigNumber::operator+(const BigNumber& _num) const
{
	int firstLen = this->m_num.length();
	int secondLen = _num.m_num.length();
	int maxLen = firstLen > secondLen ? firstLen : secondLen;
	int firstPos = firstLen - 1;
	int secondPos = secondPos - 1;
	int resPos = maxLen - 1;
	int memory = 0, sum;
	char* result = new char[maxLen + 2];

	result[resPos] = '\0';
	--resPos;

	for(int i = 0; i < maxLen; ++i)
	{
		char firstChar = (firstPos >= 0 ? this->m_num[firstPos] : 0);
		char secondChar = (secondPos >= 0 ? this->m_num[secondPos] : 0);
		sum = firstChar + secondChar - 2 * '0' + memory;
		memory = (sum > 9 ? 1 : 0);
		result[resPos] = sum % 10 + '0';
		--resPos; 
		--firstPos;
		--secondPos;
	}
	
	result[0] = memory + '0';
	
	BigNumber* res = new BigNumber(result);

	delete[] result;

	return *res;//FIXME
}

BigNumber& BigNumber::operator-(const BigNumber& _num) const
{
	int firstLen = this->m_num.length();
	int secondLen = _num.m_num.length();
	int maxLen = firstLen > secondLen ? firstLen : secondLen;
	int firstPos = firstLen - 1;
	int secondPos = secondPos - 1;
	int resPos = maxLen - 1;
	int memory = 0, sum;
	char* result = new char[maxLen + 2];

	result[resPos] = '\0';
	--resPos;

	for(int i = 0; i < maxLen; ++i)
	{
		char firstChar = (firstPos >= 0 ? this->m_num[firstPos] : 0);
		char secondChar = (secondPos >= 0 ? this->m_num[secondPos] : 0);
		sum = firstChar - secondChar + memory;
		
		if(sum < 0)
		{
			memory = -1;
			sum += 10;
		}
		else
		{
			memory = 0;
		}

		result[resPos] = sum + '0';
		--resPos; 
		--firstPos;
		--secondPos;
	}
	
	result[0] = (memory == 0 ? 0 + '0' : 0);
	
	BigNumber* res = new BigNumber(result);

	delete[] result;

	return *res;//FIXME
}

istream& operator>>(istream& _is, BigNumber& _num)
{
	int buffer;	
	
	_is >> buffer;

	_num = buffer;

	return _is;
}

ostream& operator<<(ostream& _os, const BigNumber& _num)
{
	_os << _num.GetNumString();

	return _os;
}














































