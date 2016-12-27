#include "Numbers_of_sparta.h"
#include <cstring>
#include <iostream>
BigNumber::BigNumber(const char *str)
{
    len = strlen(str);
    p = new char[len + 10]();
    std::strcpy(p, str);
    for(int i = 0, j = len - 1; i < j; i++, j--)
    {
        char c;
        c = p[i];
        p[i] = p[j];
        p[j] = c;
    }
}

BigNumber::BigNumber(int n)
{
    len = n;
    p = new char[len + 10]();
}

BigNumber::~BigNumber()
{
    delete [] p;
    len = 0;
}

BigNumber::BigNumber(const BigNumber& num)
{
    len = num.len;
    p = new char[num.len + 10]();
    std::strcpy(p, num.p);
}

BigNumber &BigNumber::operator=(const BigNumber& num)
{
    len = num.len;
    p = new char[num.len + 10];
    std::strcpy(p, num.p);
}

BigNumber BigNumber::operator+(const BigNumber& num)
{
    int mx = len > num.len ? len : num.len;
    int mn = len + num.len - mx;
    int fl = 0, carry = 0;
    BigNumber res(mx + 11);
    for(int i = 0; i < mx; i++)
    {
        if(fl == 0)
        {
            res[i] = p[i] - '0' + num.p[i] - '0' + '0' + carry;
            carry = 0;
            if(res[i] > '9')
            {
                carry = res[i] - '9';
                res[i] = (res[i] - '0' + 1) % 10 + '0';
            }
        }
        else
        {
            if(mx == len)
                res[i] = p[i];
            else
                res[i] = num.p[i];
        }
        if(i == mn - 1)
            fl = 1;
    }
    return res;
}


void BigNumber::disp()
{
    for(int i = len - 1; i >= 0; i--)    
        std::cout << p[i];
}
