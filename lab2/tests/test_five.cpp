#include <gtest/gtest.h>
#include "../src/five.cpp"

TEST(Test, DefaultConstructor)
{
    Five five;

    size_t size = five.getSize();
    unsigned char *data = five.getData();

    EXPECT_EQ(size, 0);
    EXPECT_EQ(data, nullptr);
}

TEST(Test, ConstructorWithInitializerList)
{
    Five five = {1, 2, 3};

    size_t size = five.getSize();
    unsigned char *data = five.getData();

    EXPECT_EQ(size, 3);
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 2);
    EXPECT_EQ(data[2], 3);
}

TEST(Test, ConstructorWithString)
{
    std::string value = "123";

    Five five(value);

    EXPECT_EQ(five.getSize(), 3);
    EXPECT_EQ(five.getData()[0], 1);
    EXPECT_EQ(five.getData()[1], 2);
    EXPECT_EQ(five.getData()[2], 3);
}

TEST(Test, CopyConstructor)
{
    Five five1 = {1, 2, 3};

    Five five2 = five1;

    EXPECT_EQ(five2.getSize(), five1.getSize());
    EXPECT_EQ(five2.getData()[0], five1.getData()[0]);
}

TEST(Test, MoveConstructor)
{
    Five five1 = {1, 2, 3};

    Five five2 = std::move(five1);

    EXPECT_EQ(five2.getSize(), 3);
    EXPECT_EQ(five1.getSize(), 0);
}

TEST(Test, AdditionOperator)
{
    Five five1 = {2, 3};
    Five five2 = {1, 1};
    Five result = five1 + five2;

    EXPECT_EQ(result.getSize(), 2);
    EXPECT_EQ(result.getData()[0], 3); // (2 + 1) % 5 = 3
    EXPECT_EQ(result.getData()[1], 4); // (3 + 1) % 5 = 4
}

TEST(Test, SubtractionOperator)
{

    Five five1 = {4, 3};
    Five five2 = {1, 1};

    Five result = five1 - five2;

    EXPECT_EQ(result.getSize(), 2);
    EXPECT_EQ(result.getData()[0], 3); // 4 - 1 = 3
    EXPECT_EQ(result.getData()[1], 2); // 3 - 1 = 2
}

TEST(Test, EqualityOperator)
{
    Five five1 = {1, 2, 3};
    Five five2 = {1, 2, 3};

    EXPECT_TRUE(five1 == five2);
}

TEST(Test, LessThanOperator)
{
    Five five1 = {1, 2};
    Five five2 = {1, 3};

    EXPECT_TRUE(five1 < five2);
}

TEST(Test, InvalidDigitThrows)
{
    EXPECT_THROW(Five five({5}), std::invalid_argument);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}