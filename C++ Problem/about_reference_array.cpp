#include <stdio.h>

int main(int argc, char *argv[])
{
	int x,y,z;
	int &a[3] = {x,y,z};	//compile error : 错误：‘a’声明为引用的数组

	return 0;
}
