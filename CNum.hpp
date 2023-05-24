#pragma once
#include "MyStr.hpp"
class CNum : public MyStr {
public:
    CNum();
    CNum(int);
    CNum(const char*);
    CNum(MyStr const& s);
    CNum(CNum const& s);
    template <typename T>
    CNum& operator=(T other);
    CNum operator+(CNum const& other) const;
    template <typename T>
    CNum operator+(T other) const;
    CNum operator-(CNum const& other) const;
    template <typename T>
    CNum operator-(T other) const;
    CNum operator-() const;
    void clear() = delete;
    MyStr operator~() const = delete;
    char& operator[](int const index) const = delete;
    //
    template <typename T>
    friend CNum operator+(const T a, CNum const& b);
    template <typename T>
    friend CNum operator-(T a, CNum const& b);
};
MyStr calculate(MyStr a, MyStr b, int zn);
;
template <typename T>
CNum& CNum::operator=(T other)
{
    this->MyStr::operator=(CNum(other));
    return *this;
}
template <typename T>
CNum CNum::operator+(T other) const
{
    return this->operator+(CNum(other));
}
template <typename T>
CNum CNum::operator-(T other) const
{
    return this->operator-(CNum(other));
}
template <typename T>
CNum operator+(const T a, CNum const& b)
{
    return b.operator+(a);
}
template <typename T>
CNum operator-(T a, CNum const& b)
{
    return -(b.operator-(a));
}
