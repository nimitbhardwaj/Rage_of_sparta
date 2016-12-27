#ifndef NUMBERS_OF_SPARTA_
#define NUMBERS_OF_SPARTA_
class BigNumber
{
    private:
        char *p;
        int len;
    public:
        BigNumber(const char *num);
        BigNumber(int n = 0);
        ~BigNumber();
        BigNumber(const BigNumber&);
        BigNumber &operator=(const BigNumber&);
        BigNumber operator+(const BigNumber&);
        char& operator[](const int n){return p[n];}
        void disp();
};
#endif
