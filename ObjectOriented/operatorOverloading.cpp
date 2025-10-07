#include <iostream>
using namespace std;

class Complex
{
    public:
    int real, imag;

    Complex(int r, int l)
    {
        real = r;
        imag = l;
    }
    
    //Return an object for the complex type
    Complex operator(const Complex& obj)
    {
        return Complex(real+ obj.real, imag+ obj.imag);
    }
}

int main()
{
    Complex c1 (1,2);
    Complex c2 (10,2);
    Complex c3 = c1 + c2;
    return 0;
}

//Behind the scene of operator overloading
// c1+ c2
//Behind the scenes, this calls our overloaded operator function 
//c1.operator+(c2)
