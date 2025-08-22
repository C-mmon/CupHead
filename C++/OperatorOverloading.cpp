class Vector 
{
    public:
    double x,y;

    Vector (double a, double b): x(a), y(b) {}
    Vector operator+(Vector &rhs) const
    {
        //this is a ptr, so we must return this->x
        return {this->x, this->y};
    }


    //We are taking the original object and manipulating it over here

    Vector& operator+=(const Vector &rhs)
    {
        x+=rhs.x;
        y+=rhs.y;

        return *this;
    }

    bool operator==(const Vector &rhs) const
    {
      //To use this, you must de-reference it
      return this->x == rhs.x && this->y == rhs.y;
    }
};

int main()
{
//this will not work, because these methods are not public
    Vector v2 {10,20};

    //We can also create an object using the parameterized way
    // if that function call exist
    Vector v3 {10, 10};

    v2+=v2;
    return 0;
}

