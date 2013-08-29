#include <stdio.h>
#include <iostream>
using namespace std;

struct Base 
{
	int j; 
	virtual void f()
	{
		printf("B\n");
	} 
};

struct Derived: Base 
{
	void f()
	{
		printf("D\n");
	}
};

void fooBar()
{
	Base b;
	b.f();	//B
	b.~Base();
	new ( &b ) Derived;
	b.f();	//B
}

int main(int argc, char *argv[])
{
	fooBar();	
	return 0;
}
