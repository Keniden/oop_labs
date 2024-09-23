#include "../include/five.h"

Five::Five()
{
    size = 0;
    data = nullptr;
}

Five::Five(const size_t &n, unsigned char t = 0)
{
    validateFive(n);
    size = n;
    data = new unsigned char[n];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = t;
    }
}

Five::Five(const std::initializer_list<unsigned char> &t)
{
    size_t i = 0;
    size = t.size();
    data = new unsigned char[size];
    size_t i = size;
    for (auto s : t)
    {
        validateFive(s);
        data[i] = s;
        i--;
    }
}

Five::Five(const std::string &t)
{
    size = t.size();
    data = new unsigned char[size];
    size_t i = size;
    for (auto s : t)
    {
        validateFive(s);
        data[i] = s;
        i--;
    }
}

Five::Five(const Five &other)
{
    size = other.size;
    data = new unsigned char[size];

    for (size_t i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

Five::Five(Five &&other) noexcept
{
    size = other.size;
    data = other.data;
    other.data = nullptr;
    other.size = 0;
}

Five::Five() noexcept
{
    delete[] data;
    data = nullptr;
    size = 0;
}

Five &Five::operator=(const Five &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] data;
    size = other.size;
    data = new unsigned char[size];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }

    return *this;
}
