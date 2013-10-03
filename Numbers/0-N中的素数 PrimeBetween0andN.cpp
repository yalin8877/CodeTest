#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void PrimeInRange1(int n)
{
    if (n < 2)
        return;

    vector<bool> v(n + 1);
    v[0] = v[1] = 0;
    v[2] = 1;
    for (int i = 3; i <= n; )
    {
        v[i++] = 1;
        if (i <= n)
        	v[i++] = 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (v[i] == 0)
            continue;
        int pos = i << 1;
        while (pos <= n)
        {
            v[pos] = 0;
            pos = pos + i;
        }
    }
    for (int i = 2; i <= n; i++)
    {
		if (v[i])
            cout << i << " ";
    }
}

void PrimeInRange2(int n)
{
    if (n < 2)
        return;
    vector<bool> v((n - 1) >> 1);
    for (size_t i = 0; i < v.size(); i++)
    	v[i] = 1;
    int pos = int(sqrt(n)) >> 1;
    for (int i = 0; i < pos; i++)
    {
        if (v[i] == 0)
            continue;
        int v1 = (i << 1) + 3;
        int v2 = v1 << 1;
        while (v2 <= n)
        {
            if (v2 & 0x1 == 1)
            	v[(v2 - 3) >> 1] = 0;
            v2 += v1;
        }
    }
    cout << "2 ";
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
            cout << (i << 1) + 3 << " ";
    }   
}

int main()
{
    int n;
    cin >> n;
    PrimeInRange1(n);
	cout << endl;
	PrimeInRange2(n);    
    return 0;
}