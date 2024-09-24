#pragma once

#include <initializer_list>
#include <string>
#include <stdexcept>
#include <iostream>

class Five
{
public:
    Five();
    Five(const size_t &n, unsigned char t);
    Five(const std::initializer_list<unsigned char> &ValuesList);
    Five(const std::string &ValueString);
    Five(const Five &other);
    Five(Five &&other) noexcept;
    virtual ~Five() noexcept;
    Five &operator=(const Five &other);
    Five &operator+=(const Five &other);
    Five &operator-=(const Five &other);
    Five operator+(const Five &other);
    Five operator-(const Five &other);
    bool operator==(const Five &other) const;
    bool operator<(const Five &other) const;
    bool operator>(const Five &other) const;
    size_t getSize() const;
    unsigned char *getData() const;
    friend std::ostream &operator<<(std::ostream &os, const Five &obj);

private:
    unsigned char *data;
    size_t size;
    void validateFive(unsigned char digit);
};
