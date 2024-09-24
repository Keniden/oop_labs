#include "../include/five.h"

Five::Five()
{
    size = 0;
    data = nullptr;
}

Five::Five(const size_t &n, unsigned char t)
{
    validateFive(t);
    size = n;
    data = new unsigned char[n];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = t;
    }
}

Five::Five(const std::initializer_list<unsigned char> &t)
{
    size = t.size();
    data = new unsigned char[size];
    size_t i = 0;
    for (auto s : t)
    {
        validateFive(s);
        data[i++] = s;
    }
}

Five::Five(const std::string &t)
{
    size = t.size();
    data = new unsigned char[size];
    for (size_t i = 0; i < size; i++)
    {

        unsigned char value = t[i] - '0';
        validateFive(value);
        data[i] = value;
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

Five::~Five() noexcept
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

Five &Five::operator+=(const Five &other)
{
    size_t transfer = 0;
    size_t maxSize = std::max(size, other.size);
    unsigned char *newNumber = new unsigned char[maxSize + 1];

    for (size_t i = 0; i < maxSize; i++)
    {
        int sum = transfer;
        if (i < size)
        {
            sum += data[i];
        }
        if (i < other.size)
        {
            sum += other.data[i];
        }
        newNumber[i] = sum % 5;
        transfer = sum / 5;
    }
    if (transfer > 0)
    {
        newNumber[maxSize] = transfer;
        maxSize++;
    }

    delete[] data;
    data = newNumber;
    size = maxSize;

    return *this;
}

Five Five::operator+(const Five &other)
{
    size_t transfer = 0;
    size_t maxSize = std::max(size, other.size);
    unsigned char *newNumber = new unsigned char[maxSize + 1];

    for (size_t i = 0; i < maxSize; i++)
    {
        int sum = transfer;
        if (i < size)
        {
            sum += data[i];
        }
        if (i < other.size)
        {
            sum += other.data[i];
        }
        newNumber[i] = sum % 5;
        transfer = sum / 5;
    }

    if (transfer > 0)
    {
        newNumber[maxSize] = transfer;
        maxSize++;
    }

    Five result;
    result.size = maxSize;
    result.data = new unsigned char[maxSize];

    for (size_t i = 0; i < maxSize; i++)
    {
        result.data[i] = newNumber[i];
    }

    delete[] newNumber;

    return result;
}

Five &Five::operator-=(const Five &other)
{
    if (size < other.size)
    {
        throw std::invalid_argument("Сheck size of the numbers");
    }
    int transfer = 0;
    for (size_t i = 0; i < size; i++)
    {
        int currentDigit = data[i];
        int otherDigit = (i < other.size) ? (other.data[i]) : 0;

        int different = currentDigit - otherDigit - transfer;

        if (different < 0)
        {
            different += 5;
            transfer = 1;
        }
        else
        {
            transfer = 0;
        }

        data[i] = different;
    }
    if (transfer != 0)
    {
        throw std::invalid_argument("Otricial result");
    }

    return *this;
}

Five Five::operator-(const Five &other)
{
    if (size < other.size)
    {
        throw std::invalid_argument("Check size of the number");
    }

    Five result = *this;
    int transfer = 0;

    for (size_t i = 0; i < result.size; i++)
    {
        int currentDigit = result.data[i];
        int otherDigit = (i < other.size) ? other.data[i] : 0;

        int different = currentDigit - otherDigit - transfer;

        if (different < 0)
        {
            different += 5;
            transfer = 1;
        }
        else
        {
            transfer = 0;
        }

        result.data[i] = different;
    }

    if (transfer != 0)
    {
        throw std::invalid_argument("Otricial result");
    }

    return result;
}

bool Five::operator==(const Five &other) const
{
    if (size != other.size)
    {
        return false;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (data[i] != other.data[i])
        {
            return false;
        }
    }
    return true;
}

bool Five::operator<(const Five &other) const
{
    if (size < other.size)
    {
        return true;
    }

    if (size > other.size)
    {
        return false;
    }

    for (size_t i = size; i > 0; --i)
    {
        int currentDig = data[i - 1];
        int otherDig = other.data[i - 1];

        if (currentDig < otherDig)
        {
            return true;
        }
        if (currentDig > otherDig)
        {
            return false;
        }
    }
    return false;
}

bool Five::operator>(const Five &other) const
{
    if (size > other.size)
    {
        return true;
    }
    if (size < other.size)
    {
        return false;
    }
    for (size_t i = size; i > 0; --i)
    {
        int currentDig = data[i - 1];
        int otherDig = other.data[i - 1];

        if (currentDig > otherDig)
        {
            return true;
        }
        if (currentDig < otherDig)
        {
            return false;
        }
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Five &obj)
{
    for (size_t i = obj.size; i > 0; --i)
    {
        os << static_cast<int>(obj.data[i - 1]);
    }
    return os;
}

size_t Five::getSize() const
{
    return size;
}

unsigned char *Five::getData() const
{
    return data;
}

void Five::validateFive(unsigned char digit)
{
    if (digit < 0 || digit > 4)
    {
        throw std::invalid_argument("Invalid digit. Digit must be from 0 to 4");
    }
}
