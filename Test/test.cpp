#include "pch.h"
using namespace std;
TEST(TestCase1, Test1) 
{
	char str[BUF_SIZE] = "1 + 2 + 3 + 4 + 5";
	EXPECT_EQ(eval(str), 15);
}
TEST(TestCase2, Test2)
{
	char str[BUF_SIZE] = "1 * 2 * 3 * 4 * 5";
	EXPECT_EQ(eval(str), 15);
}
TEST(TestCase3, Test3)
{
	char str[BUF_SIZE] = "1 + 2 * 3 + 4 + 5";
	EXPECT_EQ(eval(str), 15);
}
TEST(TestCase4, Test4)
{
	char str[BUF_SIZE] = "(1 + 2) * 3 + 4 + 5";
	EXPECT_EQ(eval(str), 15);
}
TEST(TestCase5, Test5)
{
	char str[BUF_SIZE] = "(1 + 2) / 3 + 4 + 5";
	EXPECT_EQ(eval(str), 15);
}
TEST(TestCase6, Test6)
{
	char str[BUF_SIZE] = "6-1*0+2/2";
	EXPECT_EQ(eval(str), 7);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}