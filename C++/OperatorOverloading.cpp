class Vector{
public:
	double x, y;
	
	//these are arthematic operation
	Vector operator+(Vector &rhs) const
	{
		return {x+rhs.x, y+rhs.y};
	}

	//we want to return the reference of the vector itself, and nothing else
	Vector& operator+=(const Vector &rhs)
	{
		x+=rhs.x;
		y+=rhs.y;
		return *this; //this gives the call back *this
	}

	//comparison ==
	bool operator==(const Vector& rhs) const
	{
		return x== rhs.x && y == rhs.y;
	}

	//same thing can be implemented for the > or <
};

int main()
{
Vector v1{10, 10};
Vector v2{10, 10};

v1 += v2; 
}
