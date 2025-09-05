class Base
{
struct Shape {
    virtual Shape* clone() const = 0;
};

struct Circle : Shape {
    Shape* clone() const override { return new Circle(*this); } // must return Shape*
};
