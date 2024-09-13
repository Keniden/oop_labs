#include <gtest/gtest.h>
#include "../src/Remove_vowel.cpp"

TEST(TestSet, CorrectRemoveVowel)
{
    // arrange
    std::string input = "This website is for losers LOL!";
    // act
    std::string result = Remove_vowel(input);
    // assert
    ASSERT_TRUE(result == "Ths wbst s fr lsrs LL!");
}

TEST(TestSet, EmptyString)
{
    // arrange
    std::string input = "";
    // act
    std::string result = Remove_vowel(input);
    // assert
    ASSERT_TRUE(result == "");
}

TEST(TestSet, AllVowels)
{
    // arrange
    std::string input = "aeiouAEaIOU";
    // act
    std::string result = Remove_vowel(input);
    // assert
    ASSERT_TRUE(result == "");
}

TEST(TestSet, NoVowels)
{
    // arrange
    std::string input = "bcdfghjklmnpqrstvwxyz";
    // act
    std::string result = Remove_vowel(input);
    // assert
    ASSERT_TRUE(result == "bcdfghjklmnpqrstvwxyz");
}

TEST(TestSet, NumbersAndSymbols)
{
    // arrange
    std::string input = "12345!@#$%1231235";
    // act
    std::string result = Remove_vowel(input);
    // assert
    ASSERT_TRUE(result == "12345!@#$%1231235");
}

TEST(TestSet, UpperLowerVowels)
{
    // arrange
    std::string input = "AaaAAAeeeEEEiiiIIIoooOOOuuuUUU";
    // act
    std::string result = Remove_vowel(input);
    // assert
    ASSERT_TRUE(result == "");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
