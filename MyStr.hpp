#pragma once
#include <iostream>
using namespace std;
class MyStr {
protected:
    char* str;
    int len = 0;

public:
    MyStr();
    MyStr(const char*);
    MyStr(const char);
    MyStr(int);
    MyStr(MyStr const&);
    ~MyStr();
    //
    MyStr& operator=(MyStr const&);
    MyStr& operator=(const char*);
    MyStr& operator=(const char);
    string getS() const;
    char* getCh() const;
    //
    MyStr operator+(MyStr const&) const;
    MyStr operator+(const char*) const;
    MyStr operator+(const char) const;
    //
    friend MyStr operator+(const char*, MyStr const&);
    friend MyStr operator+(const char, MyStr const&);
    //
    MyStr operator~() const;
    char& operator[](int const) const;
    void clear();
    int length() const;
    int find(const char) const;
    int count(const char) const;
    template <typename T>
    friend MyStr& operator+=(MyStr&, T);
    friend ostream& operator<<(ostream&, MyStr const&);
    friend void mycopy(char*, const char*, int);
    //
    bool isNum() const;
    bool isCNum() const;
    pair<MyStr, MyStr> split(const char) const;
    MyStr Ltrim(const char) const;
    //
    bool operator<(MyStr const&) const;
    bool operator>(MyStr const&) const;
    bool operator==(MyStr const&) const;
    bool operator!=(MyStr const&) const;
    bool operator<=(MyStr const&) const;
    bool operator>=(MyStr const&) const;
};

template <typename T>
MyStr& operator+=(MyStr& a, T b)
{
    return a.operator=(a.operator+(b));
}
