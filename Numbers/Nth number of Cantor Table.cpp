#include<iostream>
#include<math.h>
using namespace std;

pair<unsigned, unsigned> CalcCantorN(unsigned n)
{
	if (n == 0)
		return pair<unsigned, unsigned>(0, 0);
	unsigned lines = sqrt(n << 1) - 1;
	unsigned d = n - ((lines * (lines + 1)) >> 1);
	if (d > lines + 1)
	{
		lines++;
		d -= lines;
	}
	if (lines & 0x1 == 1)
		return pair<unsigned, unsigned>(d, lines + 2 - d);
	else
		return pair<unsigned, unsigned>(lines + 2 - d, d);
}

int main()
{
	unsigned n;
	while(1)
	{
		cin>>n;
		pair<unsigned, unsigned> p = CalcCantorN(n);
		cout << p.first << " " << p.second << endl;
	}
    return 0;
}
