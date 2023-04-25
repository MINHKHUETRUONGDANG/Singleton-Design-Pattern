#include <iostream>
#include <mutex>
using namespace std;

class Singleton{
public:
	static Singleton& getInstance(); 

private:
	Singleton(){ cout << "Ctor\n"; }
	~Singleton(){ cout << "Dtor\n"; }
	Singleton(const Singleton &) = delete;
	const Singleton& operator=(const Singleton&);
};

Singleton& Singleton::getInstance() {
	mutex mtx;
	mtx.lock();
	static Singleton instance;
	return instance;
};

int main()
{
	Singleton &s1 = Singleton::getInstance();
	Singleton &s2 = Singleton::getInstance();
    
    cout << &s1 << endl;
    cout << &s2 << endl;

	return 0;
}
