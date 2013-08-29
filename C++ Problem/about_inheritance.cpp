#include <stdio.h>
class X
{
	virtual void f(){};
	//virtual void g(){};
};

class Y
{
	virtual void h(){};
};

class A: public X,public Y
{
//	virtual void y();
};

class X1
{
	virtual void vf(){};
};

class X2:virtual public X1
{
	virtual void vf(){};
};

class X3:virtual public X2
{
	virtual void vf(){};
};

int main(int argc, char *argv[])
{

	printf("X = %d\n",sizeof(X));	//4
	printf("Y = %d\n",sizeof(Y));	//4
	printf("A = %d\n",sizeof(A));	//8
	printf("X1 = %d\n",sizeof(X1));	//4
	printf("X2 = %d\n",sizeof(X2));	//4
	printf("X3 = %d\n",sizeof(X3));	//4
	return 0;
}
