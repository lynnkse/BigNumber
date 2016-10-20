/*************************
* BigNumber.h
* 
* Author: Anton Gulyaev
* Last update: 20.10.16
*
*************************/

#ifndef __BIGNUMBER_H__
#define __BIGNUMBER_H__

#include "string_t.h"
#include <iostream>

using namespace std;

class BigNumber
{
	public:
		BigNumber();
		BigNumber(const char* _num);
		BigNumber(int _num);
		BigNumber(const BigNumber& _num);
		~BigNumber();
		
		const BigNumber& operator=(const BigNumber& _num);
		const BigNumber& operator=(int _num);
		
		bool operator>(const BigNumber& _num) const;
		bool operator<(const BigNumber& _num) const;
		bool operator==(const BigNumber& _num) const;

		BigNumber& operator+(const BigNumber& _num) const;
		BigNumber& operator-(const BigNumber& _num) const;

		const String_t& GetNumString() const;
		
	private:
		String_t m_num;
};

istream& operator>>(istream& _is, BigNumber& _num);
ostream& operator<<(ostream& _os, const BigNumber& _num);

#endif //__BIGNUMBER_H__
