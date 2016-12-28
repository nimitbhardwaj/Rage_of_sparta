#ifndef BIG_NUMBERS_
#define BIG_NUMBERS_
#include <iostream>
class BigNumber
{
    private:
        char *p;
        int len;
        bool sign;
        void normalize();
    public:
        BigNumber()
            :p(NULL), len(0){}
        BigNumber(const char *num);
        BigNumber(int n);
        ~BigNumber();
        BigNumber(const BigNumber&);
        BigNumber &operator=(const BigNumber&);
        BigNumber operator-(void) const ;
        BigNumber operator+(const BigNumber&) const;
        BigNumber operator-(const BigNumber&) const;
        bool operator<(const BigNumber&) const;
        bool operator>(const BigNumber&) const;
        bool operator>=(const BigNumber&) const;
        bool operator<=(const BigNumber&) const;
        bool operator==(const BigNumber&) const;
        bool operator!=(const BigNumber&) const;
        void operator+=(const BigNumber &);
        char &operator[](const int n){ return p[n]; }
        const char &operator[](const int n) const { return p[n]; }
        const int length() const { return len; }
        friend std::ostream &operator<<(std::ostream &dout, const BigNumber &big);
        friend std::istream &operator>>(std::istream &din, BigNumber &big);
};

inline bool BigNumber::operator>(const BigNumber &num) const
{
    return num.operator<(*this);
}

inline bool BigNumber::operator==(const BigNumber &num) const
{
    return !operator<(num) && !operator>(num);
}

inline bool BigNumber::operator>=(const BigNumber &num) const
{
    return operator>(num) || operator==(num);
}

inline bool BigNumber::operator<=(const BigNumber &num) const
{
    return operator<(num) || operator==(num);
}

inline bool BigNumber::operator!=(const BigNumber &num) const
{
    return !operator==(num);
}

#endif
