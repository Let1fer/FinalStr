#pragma once
#include "MyStr.hpp"
class ID : public MyStr {
public:
    ID();
    ID(const char*);
    ID(MyStr const& s);
    ID(ID const& s);
    template <class T>
    ID& operator=(const T other);
    template <class T>
    ID operator+(const T other) const;
    template <class T>
    friend ID operator+(const T a, ID const& b);
    template <typename T>
    friend ID& operator+=(ID&, T);
    friend void tocopy(char* a, const char* b, int len);
    MyStr operator~() const = delete;
    ID(int) = delete;
    char& operator[](int const index) const = delete;
};
template <class T>
ID& ID::operator=(const T other)
{
    return this->operator=(ID(MyStr(other)));
}
template <class T>
ID ID::operator+(const T other) const
{
    return ID(this->MyStr::operator+(other));
}
template <class T>
ID operator+(const T a, ID const& b)
{
    return ID(operator+(a, (MyStr)b));
}
template <typename T>
ID& operator+=(ID& a, T b)
{
    return a.operator=(a.MyStr::operator+(b));
}
