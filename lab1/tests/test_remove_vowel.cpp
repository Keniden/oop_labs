#include <gtest/gtest.h>
#include "../src/Remove_vowel.cpp"

TEST(TestSet, CorrectRemoveVowel)
{
    std::string input = "This website is for losers LOL!";
    std::string result = Remove_vowel(input);
    ASSERT_TRUE(result == "Ths wbst s fr lsrs LL!");
}

TEST(TestSet, EmptyString)
{
    std::string input = "";
    std::string result = Remove_vowel(input);
    ASSERT_TRUE(result == "");
}

TEST(TestSet, AllVowels)
{
    std::string input = "aeiouAEaIOU";
    std::string result = Remove_vowel(input);
    ASSERT_TRUE(result == "");
}

TEST(TestSet, NoVowels)
{
    std::string input = "bcdfghjklmnpqrstvwxyz";
    std::string result = Remove_vowel(input);
    ASSERT_TRUE(result == "bcdfghjklmnpqrstvwxyz");
}

TEST(TestSet, NumbersAndSymbols)
{
    std::string input = "12345!@#$%1231235";
    std::string result = Remove_vowel(input);
    ASSERT_TRUE(result == "12345!@#$%1231235");
}

TEST(TestSet, UpperLowerVowels)
{
    std::string input = "AaaAAAeeeEEEiiiIIIoooOOOuuuUUU";
    std::string result = Remove_vowel(input);
    ASSERT_TRUE(result == "");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
