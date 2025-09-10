#include <stdio.h>
#include <iostream>
#include <string>

class Logger
{
    public:
        virtual void write() = 0;
        ~virtual write() = default;
};

class Shape
{
    public:
        virtual void draw() = 0;
        virtual ~Shape() =  default;
};

class Circle: public Shape
{
    public:
        void draw() override 
        {
            std::cout <<"This is going to be cool " <<endl;
        }
};

class ShapeFactory
{
    static std::unique_ptr<Shape> createShape(const string& t)
    {
        if(t == "circle)
        {
            return make_unique<Circle>(); //No constructor argument 
        }
        else
        {
            return nullptr;
        }
    }
};


int main()
{
    //I have mixed concepts
    Logger s; //this particular object will be allocated on the stack
             //destructor will be automatically called when the object goes out of scope
    Logger *s; //this will case the object to be allocated on the heap 
              //memory for this needs to be manually removed using the delete operator 
    //In the modern Cpp, you never use the raw new directly, you always use with smart pointer
    auto l = std::make_unique <Logger>(); 

    //when you are sure that the object which you are allocating does not fit on the stack
    //at that point, we are using heap 
    

    //When we say we are running the destructor what do we mean 
    //Release the resource which you might have added manually, for example file, socket, manual memoryu
    auto shape1 = ShapeFactory::createShape("circle");
    auto shape2 = ShapeFactory::createShape("square");

    
    shape1->draw();
    shape2->draw();
}


class Shape
{
    private:
        int shapeId;
        int *heapData;
    public:
        Shape()
        {
            shapeId = 4; //for now just normally allocate some value to it
            heapData = new int(32); //allocate a 32 byte memory for it 
            std::cout << "Memory Allocated" <<endl;
        }

        ~Shape()
        {
            delete heapData;
        }
};
//When we use the default keyword destructor is something which is generated automatically 
//
