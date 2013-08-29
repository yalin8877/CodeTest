#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> vec;

	vector<int>::const_iterator iter1 = vec.begin();
	*iter1 = 10;	//Compile Error
	++iter1;		//OK

	const vector<int>::iterator iter2 = vec.begin();
	*iter2 = 10;	//OK
	++iter2;		//Compile Error
	
	cout << vec.at(0) << endl;
	return 0;
}
