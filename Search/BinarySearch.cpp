#include <iostream>

using namespace std;

int BinarySearch(int * array, int b, int e, int x)
{
	if (b > e)
		return -1;
	int mid = b + (e-b)/2;
	if (array[mid] > x)
		return BinarySearch(array, b, mid - 1, x);
	else if (array[mid] < x)
		return BinarySearch(array, mid + 1, e, x);
	else
	{
		while (array[--mid] == x)
			;
		return mid + 1;
	}
}

int main()
{
	int array[] = {-123, 0, 1, 32, 32,100,1000,3000,2679659,327867891};	
	while (true)
	{
		int v;
		cin >> v;
		cout << BinarySearch(array, 0, sizeof(array)/sizeof(int)-1,v) << endl;
	}	
}
