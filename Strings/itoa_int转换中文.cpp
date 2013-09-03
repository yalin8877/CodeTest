#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string GetPartSuffix(int n)
{
	switch(n)
	{
		case 1:
			return "万";
		case 2:
			return "亿";
		default:
			return "";
	}
}

string GetSuffix(int n)
{
	switch(n)
	{
		case 1:
			return "十";
		case 2:
			return "百";
		case 3:
			return "千";
		default:
			return "";
	}
}

string GetNum(char c)
{
	switch(c)
	{
		case '0':
			return "零";
		case '1':
			return "一";
		case '2':
			return "二";
		case '3':
			return "三";
		case '4':
			return "四";
		case '5':
			return "五";
		case '6':
			return "六";
		case '7':
			return "七";
		case '8':
			return "八";
		case '9':
			return "九";
		default:
			return "";
	}
}

string GetPartialString(char * c, int b, int n)
{
	string result = "";
	bool bZero = false;
	while (n--)
	{
		if (c[b] == '0')
		{
			b++;
			bZero = true;
			continue;
		}
		else if (bZero)
		{
			result.append("零");
		}
		bZero = false;
		result.append(GetNum(c[b++]));
		result.append(GetSuffix(n));
	}
	return result;
}

string Int2Chinese(int x)
{
	string result = "";
	if (x < 0)
		result.append("负");

	char c[11];
	sprintf(c, "%d", x);
	
	int length = strlen(c) - (x < 0 ? 1 : 0);
	int partNum = (length % 4 == 0 ? 0 : 1) + length / 4;
	
	int b = (x < 0 ? 1 : 0);
	int n = length - (partNum - 1) * 4;
	while (partNum--)
	{
		result = result + GetPartialString(c, b, n) + GetPartSuffix(partNum);
		b = b + n;
		n = 4;
	}
	return result;
}

int main(int argc, char *argv[])
{
	int x;
	while(1)
	{
		cin >> x;
		cout << Int2Chinese(x) << endl;
	}
	return 0;
}
