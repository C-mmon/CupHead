//C++ provides a default interface to perform a memberwise copy of all member variable, including pointers.
#include <iostream>
using namespace std;

class Shallow
{
public:
	int * data;

	Shallow(int val)
	{
		data = new int(val); //allocate on heap
	}
	//No customer coppy constructor provided ->default shallow copy will be used

};

int main()
{
	Shallow obj(42);
	Shallow obj2= obj; //default shall copy
	cout << *obj.data<<endl;
	*obj2.data= 99;
	cout << *obj.data<<endl;

}
