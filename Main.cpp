#include "CNum.hpp"
#include "ID.hpp"
#include <iostream>
int main()
{
    CNum s("+35i-27"), s1("-236i90"), s2("+450i+0");
    cout << 5 + s1 - "115i-87" << endl;
    MyStr s3 = "wegweg";
    s3 += "worgn";
    cout << s3;
    // cout << s.isNum() << endl;
}
