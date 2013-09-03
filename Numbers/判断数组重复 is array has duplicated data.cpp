#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

bool IsDuplicated(int * arr, int n)
{
	bitset<256> bs;
	for (size_t i = 0; i < n; i++)
	{
		if (bs.test(arr[i]))
			return true;
		else
			bs.set(arr[i]);
	}
	return false;
}

bool IsDuplicated(int * arr, int n, const int range)
{
	//vector<bool> actually store each data with 1 bit (same as bitset), not 8 bits
	vector<bool> vec(range);
	for (size_t i = 0; i < n; i++)
	{
		if (vec[arr[i]]==1)
			return true;
		else
			vec[arr[i]]=1;
	}
	return false;
}

int main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	cout << IsDuplicated(a, 5);
	cout << IsDuplicated(a, 5, 256);
    return 0;
}
