#include "MyStr.hpp"
void mycopy(char* a, const char* b, int len)
{
    for (int i = 0; i <= len; i++)
        a[i] = b[i];
}
ostream& operator<<(ostream& os, MyStr const& s)
{
    os << s.str;
    return os;
}
MyStr::MyStr()
{
    len = 0;
    str = new char[1];
    str[0] = 0;
}
MyStr::MyStr(const char* other)
{
    while (*(other + len++))
        ;
    str = new char[len--];
    mycopy(str, other, len);
}
MyStr::MyStr(const char c)
{
    len = 1;
    str = new char[len + 1];
    str[0] = c;
    str[1] = 0;
}
MyStr::MyStr(int n)
{
    while (n / (int)pow(10, ++len))
        ;
    int i = (n < 0 ? 1 : 0);
    len += i;
    str = new char[len + 1];
    str[0] = '-';
    str[len] = 0;
    for (int k = 0; k < len - i; k++) {
        str[len - k - 1] = abs(n % 10) + '0';
        n /= 10;
    }
}
MyStr::MyStr(MyStr const& other)
{
    len = other.len;
    str = new char[len + 1];
    mycopy(str, other.str, len);
}
MyStr::~MyStr()
{
    delete[] str;
}
MyStr& MyStr::operator=(MyStr const& other)
{
    len = other.len;
    delete[] str;
    str = new char[len + 1];
    mycopy(str, other.str, len);
    return *this;
}
MyStr& MyStr::operator=(const char* other)
{
    while (*(other + len++))
        ;
    delete[] str;
    str = new char[len--];
    mycopy(str, other, len);
    return *this;
}
MyStr& MyStr::operator=(const char other)
{
    len = 1;
    delete[] str;
    str = new char[len + 1];
    str[0] = other;
    str[1] = 0;
    return *this;
}
string MyStr::getS() const
{
    return string(str);
}
char* MyStr::getCh() const
{
    return str;
}
MyStr MyStr::operator+(MyStr const& other) const
{
    MyStr rez;
    rez.len = len + other.len;
    rez.str = new char[rez.len + 1];
    mycopy(rez.str, str, len);
    mycopy(rez.str + len, other.str, other.len);
    return rez;
}
MyStr MyStr::operator+(const char* other) const
{
    MyStr rez;
    rez.len = 0;
    while (*(other + rez.len++))
        ;
    rez.len += (len - 1);
    rez.str = new char[rez.len + 1];
    mycopy(rez.str, str, len);
    mycopy(rez.str + len, other, rez.len - len);
    return rez;
}
MyStr MyStr::operator+(const char other) const
{
    MyStr rez;
    rez.len = len + 1;
    rez.str = new char[rez.len + 1];
    mycopy(rez.str, str, len);
    rez.str[len] = other;
    rez.str[len + 1] = 0;
    return rez;
}
MyStr operator+(const char* a, MyStr const& b)
{
    MyStr rez;
    rez.len = 0;
    while (*(a + rez.len++))
        ;
    rez.len += (b.len - 1);
    rez.str = new char[rez.len + 1];
    mycopy(rez.str, a, rez.len - b.len);
    mycopy(rez.str + rez.len - b.len, b.str, b.len);
    return rez;
}
MyStr operator+(const char a, MyStr const& b)
{
    MyStr rez;
    rez.len = b.len + 1;
    rez.str = new char[rez.len + 1];
    mycopy(rez.str + 1, b.str, b.len);
    rez.str[0] = a;
    rez.str[rez.len] = 0;
    return rez;
}
MyStr MyStr::operator~() const
{
    MyStr rez(*this);
    for (int i = 0; i < (len - 0) / 2; i++)
        swap(rez.str[i], rez.str[(len - 1) - i]);
    return rez;
}
char& MyStr::operator[](int const index) const
{
    return str[index];
}
void MyStr::clear()
{
    delete[] str;
    str = new char[1];
    str[0] = 0;
    len = 0;
}
int MyStr::length() const
{
    return len;
}
int MyStr::find(const char c) const
{
    for (int i = 0; i < len; i++)
        if (str[i] == c)
            return i;
    return -1;
}
bool MyStr::isNum() const
{
    if ((*this) == MyStr("0") || (*this) == MyStr("+0") || (*this) == MyStr("-0"))
        return 1;
    if (!len)
        return 0;
    int i = 0;
    if (str[0] == '+' || str[0] == '-')
        i++;
    if (str[i] == '0' || str[i] == 0)
        return 0;
    for (; i < len; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
bool MyStr::isCNum() const
{
    if (this->count('i') != 1)
        return 0;
    pair<MyStr, MyStr> p = this->split('i');
    return p.first.isNum() && p.second.isNum();
}
int MyStr::count(const char c) const
{
    int k = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == c)
            k++;
    }
    return k;
}
pair<MyStr, MyStr> MyStr::split(const char c) const
{
    pair<MyStr, MyStr> rez;
    int i = 0;
    for (; str[i] != c;)
        rez.first += str[i++];
    while (++i < len)
        rez.second += str[i];
    return rez;
}
MyStr MyStr::Ltrim(const char c) const
{
    int i = -1;
    while (str[++i] == c)
        ;
    MyStr rez;
    while (i != len)
        rez += str[i++];
    return rez;
}
bool MyStr::operator<(MyStr const& other) const
{
    if (len < other.len)
        return 1;
    if (len > other.len)
        return 0;
    for (int i = 0; i < len; i++)
        if (str[i] < other.str[i])
            return 1;
        else if (str[i] > other.str[i])
            return 0;
    return 0;
}
bool MyStr::operator>(MyStr const& other) const
{
    if (len > other.len)
        return 1;
    if (len < other.len)
        return 0;
    for (int i = 0; i < len; i++)
        if (str[i] > other.str[i])
            return 1;
        else if (str[i] < other.str[i])
            return 0;
    return 0;
}
bool MyStr::operator==(MyStr const& other) const
{
    if (len != other.len)
        return 0;
    for (int i = 0; i < len; i++)
        if (str[i] != other.str[i])
            return 0;
    return 1;
}
bool MyStr::operator!=(MyStr const& other) const
{
    if (len != other.len)
        return 1;
    for (int i = 0; i < len; i++)
        if (str[i] != other.str[i])
            return 1;
    return 0;
}
bool MyStr::operator<=(MyStr const& other) const
{
    if (len < other.len)
        return 1;
    if (len > other.len)
        return 0;
    for (int i = 0; i < len; i++)
        if (str[i] < other.str[i])
            return 1;
        else if (str[i] > other.str[i])
            return 0;
    return 1;
}
bool MyStr::operator>=(MyStr const& other) const
{
    if (len > other.len)
        return 1;
    if (len < other.len)
        return 0;
    for (int i = 0; i < len; i++)
        if (str[i] < other.str[i])
            return 0;
        else if (str[i] > other.str[i])
            return 1;
    return 1;
}
