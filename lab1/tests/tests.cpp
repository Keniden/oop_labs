#include <gtest/gtest.h>
#include "../src/Remove_vowel.cpp"

TEST(TestSet, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("This website is for losers LOL!") == "Ths wbst s fr lsrs LL!");
}

TEST(TestSet, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("") == "");
}

TEST(TestSet, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("aeiouAEaIOU") == "");
}

TEST(TestSet, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("bcdfghjklmnpqrstvwxyz") == "bcdfghjklmnpqrstvwxyz");
}
TEST(TestSet, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("12345!@#$%1231235") == "12345!@#$%1231235");
}

TEST(TestSet, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("AaaAAAeeeEEEiiiIIIoooOOOuuuUUU") == "");
}

TEST(TestSet, basic_test_set)
{
    ASSERT_TRUE(Remove_vowel("ZVZVZVZVZVzombii") == "ZVZVZVZVZVzmb");
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}