#include<iostream>

using namespace std;

unsigned long power(unsigned int a, unsigned int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return a;

	int half=power(a,n>>1);
	if(n%2==0)
		return half*half;
	else
		return half*half*a;
}

int main()
{
	int a,n;
	cin>>a>>n;
	cout<<power(a,n);
    return 0;
}
