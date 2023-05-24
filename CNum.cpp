#include "CNum.hpp"
CNum::CNum()
    : MyStr("+0i+0")
{
}
CNum::CNum(int a)
    : CNum(MyStr(a))
{
}
CNum::CNum(const char* ch)
    : CNum(MyStr(ch))
{
}
CNum::CNum(MyStr const& s)
{
    if (s.isNum()) {
        this->MyStr::operator=(((s[0] == '+' || s[0] == '-') ? "" : "+") + s + "i+0");
        return;
    }
    if (s.isCNum()) {
        pair<MyStr, MyStr> p = s.split('i');
        if (p.first[0] != '-' && p.first[0] != '+')
            p.first = '+' + p.first;
        if (p.second[0] != '-' && p.second[0] != '+')
            p.second = '+' + p.second;
        this->MyStr::operator=(p.first + 'i' + p.second);
        return;
    }
    this->MyStr::operator=("+0i+0");
}
CNum::CNum(CNum const& other)
    : MyStr(other)
{
}
CNum CNum::operator+(CNum const& other) const
{
    pair<MyStr, MyStr> p1 = this->split('i');
    pair<MyStr, MyStr> p2 = other.split('i');
    MyStr rez;
    rez += (MyStr(p1.first.getCh() + 1) > MyStr(p2.first.getCh() + 1)) ? p1.first[0] : p2.first[0];
    rez += calculate(p1.first, p2.first, (p1.first[0] == p2.first[0]) ? 1 : -1) + 'i';
    if (rez[rez.length() - 1] == '+' || rez[rez.length() - 1] == '-')
        rez += '0';
    rez += (MyStr(p1.second.getCh() + 1) > MyStr(p2.second.getCh() + 1)) ? p1.second[0] : p2.second[0];
    rez += calculate(p1.second, p2.second, (p1.second[0] == p2.second[0]) ? 1 : -1);
    if (rez[rez.length() - 1] == '+' || rez[rez.length() - 1] == '-')
        rez += '0';
    return CNum(rez);
}
CNum CNum::operator-(CNum const& other) const
{
    MyStr s(other.str);
    for (int i = 0; i < len; i++)
        if (s[i] == '+')
            s[i] = '-';
        else if (s[i] == '-')
            s[i] = '+';
    return this->operator+(s);
}
CNum CNum::operator-() const
{
    MyStr s = *this;
    for (int i = 0; i < len; i++)
        if (s[i] == '+')
            s[i] = '-';
        else if (s[i] == '-')
            s[i] = '+';
    return CNum(s);
}
MyStr calculate(MyStr a, MyStr b, int zn)
{
    a[0] = b[0] = '0';
    if (a < b)
        swap(a, b);
    int i = 1, carry = 0;
    for (; (a.length() - i) >= 0; i++) {
        a[a.length() - i] += ((((b.length() - i) >= 0) ? (b[b.length() - i] - '0') : 0) + carry) * zn;
        if (a[a.length() - i] < '0' || a[a.length() - i] > '9') {
            a[a.length() - i] += 10 * (-zn);
            carry = 1;
        } else
            carry = 0;
    }
    return a.Ltrim('0');
}
