#include<iostream>
#include<thread>

using namespace std;

class Singleton
{
public:
	static Singleton * GetInstance();
	void test(){cout << "test" << endl;};
private:
	Singleton(){};
	~Singleton(){};
	Singleton(Singleton&);
	Singleton & operator=(const Singleton &);
	static Singleton * pointer;
};

Singleton * Singleton::pointer = NULL;

Singleton * Singleton::GetInstance()
{
	if (!pointer)
	{
		pthread_mutex_t m;
		pthread_mutex_lock(&m);
		if (!pointer)
		{
			pointer = new Singleton();
		}
		pthread_mutex_unlock(&m);
	}
	return pointer;
}

int main()
{
	//Singleton * s = new Singleton();
	Singleton * p = Singleton::GetInstance();
	p->test();
	return 0;
}