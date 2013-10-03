#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <cstdlib>
using namespace std;

unsigned CalcAppearOf1Recursive(char * num, unsigned nleft)
{
    //cout << num << " " << nleft << endl;
    if (num == NULL || *num == '\0' || nleft <= 0)
        return 0;
    if (*num == '0')
        return CalcAppearOf1Recursive(++num, --nleft);
    
    unsigned s1;
    if (*num == '1')
        s1 = atoi(num + 1) + 1;
    else if (*num <= '9')
        s1 = pow(10, nleft - 1);
        
    unsigned s2 = pow(10, nleft - 2) * (nleft - 1) * (*num - '0');
    
    return s1+ s2 + CalcAppearOf1Recursive(++num, --nleft);
}

unsigned CalcAppearOf1(unsigned n)
{
    if (n == 0)
        return 0;
    if (n < 10)
        return 1;
    char num[11];
    sprintf(num, "%d", n);
    return CalcAppearOf1Recursive(num, strlen(num));
}
                                  
int main()
{
    unsigned n = 12345;
    cout << CalcAppearOf1(n);
}