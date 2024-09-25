#include <gtest/gtest.h>
#include <stdexcept>
#include "../src/five.cpp"

TEST(FiveTest, DefaultConstructor)
{

    Five numberDefault;

    ASSERT_EQ(numberDefault.getSize(), 0);
    ASSERT_EQ(numberDefault.getData(), nullptr);
}

TEST(FiveTest, IncorrectDigitConstructor)
{

    EXPECT_THROW(Five number(1, '5'), std::invalid_argument);
    EXPECT_THROW(Five number(1, 'a'), std::invalid_argument);
}

TEST(FiveTest, IncorrectLengthConstructor)
{

    EXPECT_THROW(Five number(0, '0'), std::invalid_argument);
}

TEST(FiveTest, InitListConstructor)
{

    Five expected{3, 3, 3};

    Five number{3, 3, 3};

    ASSERT_TRUE(number == expected);
}

TEST(FiveTest, IncorrectDigitInitListConstructor)
{

    EXPECT_THROW(Five({'5'}), std::invalid_argument);
    EXPECT_THROW(Five({'1', '2', '6', '0'}), std::invalid_argument);
    EXPECT_THROW(Five({'1', '5', '3', '0', '4'}), std::invalid_argument);
}

TEST(FiveTest, StringConstructor)
{

    Five expected{3, 2, 2};

    Five number("322");

    ASSERT_TRUE(number == expected);
}

TEST(FiveTest, IncorrectDigitStringConstructor)
{

    EXPECT_THROW(Five("5"), std::invalid_argument);
    EXPECT_THROW(Five("1260"), std::invalid_argument);
    EXPECT_THROW(Five("15304"), std::invalid_argument);
}

TEST(FiveTest, CopyConstructor)
{

    Five number1("1234");

    Five number2{number1};

    ASSERT_TRUE(number1 == number2);
}

TEST(FiveTest, MoveConstructor)
{

    Five numberOriginal("12341");
    Five expected{numberOriginal};

    Five number{std::move(numberOriginal)};

    ASSERT_TRUE(number == expected);
    ASSERT_TRUE(numberOriginal.getSize() == 0);
}

TEST(FiveTest, AssignmentOperator)
{

    Five number2("32222");

    Five number1;
    number1 = number2;

    ASSERT_TRUE(number1 == number2);
}

TEST(FiveTest, ComparisonOperators)
{

    Five number1({2, 3});
    Five number2({2, 3});
    Five number3({2, 1});

    ASSERT_FALSE(number1 < number2);
    ASSERT_FALSE(number1 > number2);
    ASSERT_FALSE(number1 < number3);
    ASSERT_TRUE(number1 > number3);
    ASSERT_TRUE(number1 == number2);
    ASSERT_FALSE(number1 == number3);
}

TEST(FiveTest, AddZero)
{

    Five number1("1234");
    Five number1Copy{number1};
    Five numberZero;

    number1 += numberZero;

    ASSERT_TRUE(number1 == number1Copy);
}

TEST(FiveTest, Add)
{

    Five number1("1023");
    Five number2("31");
    Five expected("1104");

    number1 += number2;

    ASSERT_TRUE(number1 == expected);
}

TEST(FiveTest, AddExtend)
{

    Five number1("44444");
    Five number2("1");
    Five expected("100000");

    number1 += number2;

    ASSERT_TRUE(number1 == expected);
}

TEST(FiveTest, SubZero)
{

    Five number1("1234");
    Five number1Copy{number1};
    Five numberZero;

    number1 -= numberZero;

    ASSERT_TRUE(number1 == number1Copy);
}

TEST(FiveTest, Sub)
{

    Five number1("1044");
    Five number2("31");
    Five expected("1013");

    number1 -= number2;

    ASSERT_TRUE(number1 == expected);
}

TEST(FiveTest, SubstructionError)
{

    Five number1("234");
    Five number2("12334");

    EXPECT_THROW(number1 -= number2, std::logic_error);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
