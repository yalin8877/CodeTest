#include <stdio.h>

int main(int argc, char *argv[])
{
	int x = 20, y = 35;
	x = x++ + y++;
	printf("%d %d\n", x, y);	//56 36

	return 0;
}
