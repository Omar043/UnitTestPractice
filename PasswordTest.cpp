/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
};

TEST(PasswordTest, blank_char)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case(""));
};

TEST(PasswordTest, single_lower_char)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("a"));
};

TEST(PasswordTest, single_upper_char){
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("A"));
};

TEST(PasswordTest, mult_lower_char){
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("aaaa"));
};

TEST(PasswordTest, mult_upper_char){
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("AAAA"));
};

TEST(PasswordTest, num_and_char){
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("1a11aaa"));
};

TEST(PasswordTest, num_and_single_char){
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("1a"));
};

TEST(PasswordTest, single_num_single_char){
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aA"));
};

TEST(PasswordTest, mult_upper_one_single){
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("AAAAa"));
};

TEST(PasswordTest, mult_single_one_upper){
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aAAAA"));
};