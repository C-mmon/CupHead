#include <iostream>

using namespace std;

class Singleton
{
private:
	//instance class is always created at the program startup
	static Singleton instance;

	//Private constructor
	//We declare this constructor as private, because only the static reference
	// can accesss this functionality of the class
	Singleton()
	{

	}

	//we delete the copy constructor
	Singleton(const Singleton&)=delete;
	//We delete the equal to operator to prevent assignature operation
	Singleton& operator = (const Singleton&) = delete;
public:
	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}

	void sayHello()
	{
		cout <<"Aniket is good"<<endl;
	}
};


int main()
{
	//We use alias to ensure only one refere ce
	Singleton& store = Singleton::getInstance();
	store.sayHello();

}
