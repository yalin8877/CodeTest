#include <stdio.h>
#define INT_MAX (2147483647)
#define INT_MIN (-2147483648)
int atoi(const char *str)
{
	if (!str) return 0;
	unsigned int result = 0;
	int sign = 1;
	if (*str == '+') str++;
	if (*str == '-') { sign = -1; str++; }
	while ('0' <= *str && *str <= '9')
	{
		unsigned int digit = *str - '0';
		//style 1
		if ((result > INT_MAX/10) ||
			(sign > 0 ? (result == INT_MAX / 10 && digit > INT_MAX % 10)
			:(result == ((unsigned int)INT_MAX + 1)/10 && digit > ((unsigned int)INT_MAX + 1)% 10) )
			)
		{
			return sign > 0 ? INT_MAX : INT_MIN;
		}
		result = result * 10 + digit;
		str++;
	}
	return ((int)result) * sign;
}
int main(int argc, char *argv[])
{
	char * x1 = "-2147483648";
	char * x2 = "2147483648";
	char * x3 = "-2147483649";
	int y1 = atoi(x1);
	int y2 = atoi(x2);
	int y3 = atoi(x3);
	printf("%d\n%d\n%d\n", y1, y2, y3);
	return 0;
}
