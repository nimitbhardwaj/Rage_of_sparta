#include "rage_of_sparta.h"
int *KMP(const std::string &S, const std::string &T)
{
    //Array A need to be deleted
    //Requires string
    int sz = S.size(), szt = T.size();
    int *A = new int[sz]();
    int *B = __lookUpTable(T);
    A[0] = 0;
    int i = 0, j = 0;
    while(i < sz)
    {
        if(T[j] == S[i])
            i++, j++;
        if(j == szt)
        {
            A[0]++;
            A[A[0]] = i - j;
            j = B[j - 1];
        }
        else if(i < sz && T[j] != S[i])
        {
            if(j != 0)
                j = B[j - 1];
            else
                i++;
        }
    }
    delete[] B;
    return A;
}

int *__lookUpTable(const std::string &T)
{
    //array is needed to be freed
    //Requires String, and used by KMP function
    int sz = T.size();
    int *B = new int[sz]();
    int j = 0;
    B[0] = 0;
    for(int i = 1; i < sz; i++)
    {
        while(1)
        {
            if(T[j] == T[i])
            {
                B[i] = j + 1;
                j++;
                break;
            }
            else if(T[j] != T[i] && j != 0)
            {
                j = B[j - 1];
            }
            else if(T[j] != T[i] && j == 0)
            {
                break;
            }
        }
    }
    return B;
}

bool *simple_sieve(int n)
{
    //Array returned needed to be freed
    //Requires cstring
    bool *A = new bool[n + 5];
    memset(A, true, (n + 5) * sizeof(bool));
    A[0] = A[1] = false;
    for(int i = 2; i * i <= n; i++)
    {
        if(A[i] == true)
            for(int j = 2 * i; j <= n; j += i)
            {
                A[j] = false;
            }
    }
    return A;
}
