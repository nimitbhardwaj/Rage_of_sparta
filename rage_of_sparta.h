#ifndef STRING
#define STRING
#include<string>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include<iostream>
#endif
#ifndef CSTR
#define CSTR
#include<cstring>
#endif
int *KMP(const std::string &, const std::string &);
int *__lookUpTable(const std::string &);
bool *simple_sieve(int n);

