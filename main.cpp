#include "mu_test.h"
#include "BigNumber.h"
#include "string_t.h"
#include <iostream>

using namespace std;

UNIT(Def_CTOR)
	BigNumber num;
	cout << num;
	ASSERT_THAT(num == 0);
END_UNIT

UNIT(CHARS_CTOR)
	BigNumber num("25");
	cout << num;
	ASSERT_THAT(num == 25);
END_UNIT

UNIT(INT_CTOR)
	BigNumber num(25);
	cout << num;
	ASSERT_THAT(num == 25);
END_UNIT

UNIT(INT_BIGNUM)
	BigNumber num(25);
	BigNumber num2(num);
	cout << num;
	ASSERT_THAT(num == 25);
END_UNIT

UNIT(ADDITION)
	BigNumber a(5);
	BigNumber b(6);
	BigNumber result;
	result = a + b;
	cout << result;
	ASSERT_THAT(result == 11);
END_UNIT

UNIT(MORE)
	BigNumber a(5);
	BigNumber b(6);
	ASSERT_THAT(b > a);
END_UNIT

UNIT(LESS)
	BigNumber a(5);
	BigNumber b(6);
	ASSERT_THAT(a < b);
END_UNIT

TEST_SUITE(BigNumber test)
	TEST(Def_CTOR)
	TEST(CHARS_CTOR)
	TEST(INT_CTOR)
	TEST(INT_BIGNUM)
	TEST(ADDITION)
	TEST(MORE)
	TEST(LESS)
END_SUITE










































