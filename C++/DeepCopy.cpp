//Both the object will have a separate memory through which they can wormjk one
//there will no double free srash, since each object manages its own memory safely 

#include <iostream>
using namespace std;

class Deep
{
private: int* data;
public:
	Deep(int val)
	{
		data = new int(val); //allocate on heap
	}
	//No customer coppy constructor provided ->default shallow copy will be used
	Deep(const Deep& other)
	{
		data = new int(*other.data); //allocate a new memory and copy value
		cout << "Deep copy constructor called" << endl;
	}

	void setValue(int val)
	{
		*data= val;
	}

	void print() const
	{
		cout << *data <<endl;
	}
	~Deep()
	{
		delete data;
		cout <<" Destructor is called" <<endl;
	}
};

int main()
{
	Deep obj1(1);
	Deep obj2=  obj1;
	obj2.setValue(100);
	obj2.print();
}
