#include <gtest/gtest.h>
#include "MyMemoryResource.hpp"
#include "../src/MyMemoryResource.cpp"
#include "MyVector.hpp"
#include <string>


TEST(MyVectorTest, PushBackInt) {
    MyMemoryResource memory_resource;
    std::pmr::polymorphic_allocator<int> alloc_int(&memory_resource);
    MyVector<int> vec_int(alloc_int);
    int value1 = 10;
    int value2 = 20;

    vec_int.push_back(value1);
    vec_int.push_back(value2);

    ASSERT_EQ(vec_int.size(), 2);
    EXPECT_EQ(vec_int[0], value1);
    EXPECT_EQ(vec_int[1], value2);
}

TEST(MyVectorTest, PopBackInt) {
    MyMemoryResource memory_resource;
    std::pmr::polymorphic_allocator<int> alloc_int(&memory_resource);
    MyVector<int> vec_int(alloc_int);
    vec_int.push_back(10);
    vec_int.push_back(20);

    vec_int.pop_back();

    ASSERT_EQ(vec_int.size(), 1);
    EXPECT_EQ(vec_int[0], 10);
}

TEST(MyVectorTest, PushBackString) {
    MyMemoryResource memory_resource;
    std::pmr::polymorphic_allocator<std::string> alloc_str(&memory_resource);
    MyVector<std::string> vec_str(alloc_str);
    std::string str1 = "Hello";
    std::string str2 = "World";

    vec_str.push_back(str1);
    vec_str.push_back(str2);

    ASSERT_EQ(vec_str.size(), 2);
    EXPECT_EQ(vec_str[0], str1);
    EXPECT_EQ(vec_str[1], str2);
}

TEST(MyVectorTest, IteratorTestInt) {
    MyMemoryResource memory_resource;
    std::pmr::polymorphic_allocator<int> alloc_int(&memory_resource);
    MyVector<int> vec_int(alloc_int);
    vec_int.push_back(1);
    vec_int.push_back(2);
    vec_int.push_back(3);

    int expected_value = 1;
    for (auto it = vec_int.begin(); it != vec_int.end(); ++it) {
        EXPECT_EQ(*it, expected_value++);
    }
}

TEST(MyVectorTest, CapacityIncrease) {
    MyMemoryResource memory_resource;
    std::pmr::polymorphic_allocator<int> alloc_int(&memory_resource);
    MyVector<int> vec_int(alloc_int);
    int initial_capacity = vec_int.capacity();

    for (int i = 0; i < 100; ++i) {
        vec_int.push_back(i);
    }

    EXPECT_GE(vec_int.capacity(), 100);
    EXPECT_EQ(vec_int.size(), 100);
    for (int i = 0; i < 100; ++i) {
        EXPECT_EQ(vec_int[i], i);
    }
}

TEST(MyVectorTest, EmptyVector) {
    MyMemoryResource memory_resource;
    std::pmr::polymorphic_allocator<int> alloc_int(&memory_resource);
    MyVector<int> vec_int(alloc_int);

    EXPECT_TRUE(vec_int.empty());
    EXPECT_EQ(vec_int.size(), 0);

    vec_int.push_back(10);

    EXPECT_FALSE(vec_int.empty());
    EXPECT_EQ(vec_int.size(), 1);
}

TEST(MyVectorTest, AccessOperator) {
    MyMemoryResource memory_resource;
    std::pmr::polymorphic_allocator<std::string> alloc_str(&memory_resource);
    MyVector<std::string> vec_str(alloc_str);
    vec_str.push_back("Hello");
    vec_str.push_back("World");

    EXPECT_EQ(vec_str[0], "Hello");
    EXPECT_EQ(vec_str[1], "World");

    vec_str[1] = "C++";

    EXPECT_EQ(vec_str[1], "C++");
}

TEST(MyVectorTest, PushBackDouble) {
    MyMemoryResource memory_resource;
    std::pmr::polymorphic_allocator<double> alloc_double(&memory_resource);
    MyVector<double> vec_double(alloc_double);
    double value1 = 1.234;
    double value2 = 5.678;

    vec_double.push_back(value1);
    vec_double.push_back(value2);

    ASSERT_EQ(vec_double.size(), 2);
    EXPECT_DOUBLE_EQ(vec_double[0], value1);
    EXPECT_DOUBLE_EQ(vec_double[1], value2);
}
