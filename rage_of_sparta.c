#include "rage_of_sparta.h"
int *KMP(const std::string S, const std::string T)
{
    //Array A need to be deleted
    int sz = S.size(), szt = T.size();
    int *A = new int[sz];
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
    int sz = T.size();
    int *B = new int[sz];
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
