#ifndef __STRING_T_H__
#define __STRING_T_H__

#include <iostream>

using namespace std;

class String_t
{
	public:
		String_t();
		String_t(const char* _str);
		String_t(const String_t& _str);	
		~String_t();
		const String_t& operator=(const String_t& _str);
		int length() const;
		void setString(const char* _str);
		const char* getString() const;
		int compare(const String_t& _str) const;
		void print() const;
		
		void toUpper(); 
		void toLower();
		void prepend(const char* _str);//TODO 4 this return void
		void prepend(const String_t& _str);
		const String_t& operator+=(const String_t& _str);
		bool operator>(const String_t& _str) const;
		bool operator<(const String_t& _str) const;
		bool operator>=(const String_t& _str) const;
		bool operator<=(const String_t& _str) const;
		bool operator==(const String_t& _str) const;
		bool operator!=(const String_t& _str) const;
		bool contains(const String_t& _str) const;
		bool contains(const char* _str) const;
		char operator[](int i) const;
		static int getNumOfStrings();

	private:	
		char* m_chars;
		int m_currSize;
		static int m_numOfStrings;
		
		void ReallocIfNeed(int _newSize);
};

ostream& operator<<(ostream& _os, const String_t& _str);
istream& operator>>(istream& _is, String_t& _str);

#endif //__STRING_T_H__
















































