#include <iostream>
#include <string>
#include "MyMemoryResource.hpp"
#include "./src/MyMemoryResource.cpp"
#include "MyVector.hpp"


struct MyStruct
{
    int a;
    double b;
    std::string c;

    MyStruct(int aa, double bb, const std::string &cc)
        : a(aa), b(bb), c(cc) {}
};

int main()
{
    MyMemoryResource memory_resource;

    std::pmr::polymorphic_allocator<int> alloc_int(&memory_resource);
    MyVector<int> vec_int(alloc_int);

    vec_int.push_back(10);
    vec_int.push_back(20);
    vec_int.push_back(30);

    std::cout << "Integer Vector:\n";
    for (auto it = vec_int.begin(); it != vec_int.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << "\nSize: " << vec_int.size() << ", Capacity: " << vec_int.capacity() << "\n\n";

    vec_int.push_back(40);
    vec_int.push_back(50);

    std::cout << "Integer Vector after adding more elements:\n";
    for (auto it = vec_int.begin(); it != vec_int.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << "\nSize: " << vec_int.size() << ", Capacity: " << vec_int.capacity() << "\n\n";

    vec_int.pop_back();
    std::cout << "Integer Vector after pop_back:\n";
    for (auto it = vec_int.begin(); it != vec_int.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << "\nSize: " << vec_int.size() << ", Capacity: " << vec_int.capacity() << "\n\n";

    std::pmr::polymorphic_allocator<MyStruct> alloc_struct(&memory_resource);
    MyVector<MyStruct> vec_struct(alloc_struct);

    vec_struct.push_back(MyStruct(1, 1.1, "one"));
    vec_struct.push_back(MyStruct(2, 2.2, "two"));
    vec_struct.push_back(MyStruct(3, 3.3, "three"));

    std::cout << "Struct Vector:\n";
    for (auto it = vec_struct.begin(); it != vec_struct.end(); ++it)
    {
        std::cout << "a: " << it->a << ", b: " << it->b << ", c: " << it->c << '\n';
    }
    std::cout << "Size: " << vec_struct.size() << ", Capacity: " << vec_struct.capacity() << "\n\n";

    vec_struct.push_back(MyStruct(4, 4.4, "four"));
    vec_struct.push_back(MyStruct(5, 5.5, "five"));

    std::cout << "Struct Vector after adding more elements:\n";
    for (auto it = vec_struct.begin(); it != vec_struct.end(); ++it)
    {
        std::cout << "a: " << it->a << ", b: " << it->b << ", c: " << it->c << '\n';
    }
    std::cout << "Size: " << vec_struct.size() << ", Capacity: " << vec_struct.capacity() << "\n\n";

    vec_struct.pop_back();
    std::cout << "Struct Vector after pop_back:\n";
    for (auto it = vec_struct.begin(); it != vec_struct.end(); ++it)
    {
        std::cout << "a: " << it->a << ", b: " << it->b << ", c: " << it->c << '\n';
    }
    std::cout << "Size: " << vec_struct.size() << ", Capacity: " << vec_struct.capacity() << "\n";

    return 0;
}
