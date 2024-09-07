#include <gtest/gtest.h>
#include "../src/Remove_vowel.cpp"

TEST(test1, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("This website is for losers LOL!") == "Ths wbst s fr lsrs LL!");
}

TEST(test2, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("") == "");
}

TEST(test3, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("aeiouAEaIOU") == "");
}

TEST(test4, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("bcdfghjklmnpqrstvwxyz") == "bcdfghjklmnpqrstvwxyz");
}
TEST(test5, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("12345!@#$%1231235") == "12345!@#$%1231235");
}

TEST(test6, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("AaaAAAeeeEEEiiiIIIoooOOOuuuUUU") == "");
}

TEST(test7, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("ZVZVZVZVZVzombii") == "ZVZVZVZVZVzmb");
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}