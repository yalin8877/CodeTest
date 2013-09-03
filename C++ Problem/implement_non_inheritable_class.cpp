#include<iostream>
#include<thread>

using namespace std;

class UnInheritancedBase
{
protected:
	UnInheritancedBase(){};
	~UnInheritancedBase(){};
};

class UnInheritanced : virtual private UnInheritancedBase
{
public:
	UnInheritanced(){};
	~UnInheritanced(){};
};

class UnInheritancedWrong : private UnInheritancedBase
{
public:
	UnInheritancedWrong(){};
	~UnInheritancedWrong(){};
};

class Derived : public UnInheritanced
{
public:
	Derived(){};
	~Derived(){};
};

class DerivedWrong : public UnInheritancedWrong
{
public:
	DerivedWrong(){};
	~DerivedWrong(){};
};

int main()
{
	UnInheritancedBase bb;//could not be instantiated
	UnInheritanced b;
	UnInheritancedWrong bw;
	Derived d;//could not be instantiated
	DerivedWrong dw;//could be instantiated
	return 0;
}