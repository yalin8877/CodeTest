#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <cstdlib>
using namespace std;

bool SubStr(const char * s1, const char * s2)
{
    if (s1 == NULL || s2 == NULL || strlen(s1) < strlen(s2))
        return false;
    int i, p1, p2;
    for (i = 0; i <= strlen(s1) - strlen(s2); i++)
    {
            p1 = i;
            p2 = 0;
            while (p1 < strlen(s1) && p2 < strlen(s2) && s1[p1++] == s2[p2++])
          		;
            if (p2 == strlen(s2))
                return true;
    }
    return false;            
}

int main()
{
    cout << SubStr("1356346", "13563465");
}