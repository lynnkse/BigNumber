#include <string_t.h>

class BigNumber
{
	public:
		BigNumber();
		BigNumber(const char* _num);
		BigNumber(int _num);
		BigNumber(const BigNumber& _num);
		~BigNumber();
		
		
	private:
		String_t* m_num;
};
