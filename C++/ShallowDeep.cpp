#include <iostream>
#include <cstring>
using namespace std;

class Shallow {
public:
    char* data;

    Shallow(const char* val) {
        data = new char[strlen(val) + 1];
        strcpy(data, val);
    }

    // Shallow copy constructor
    Shallow(const Shallow& other) {
        data = other.data;  // Just copies the pointer!
    }

    void show() {
        cout << "Data: " << data << endl;
    }
};

class Deep {
public:
    char* data;

    Deep(const char* val) {
        data = new char[strlen(val) + 1];
        strcpy(data, val);
    }

    // Deep copy constructor
    Deep(const Deep& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);  // Allocates new memory
    }

    void show() {
        cout << "Data: " << data << endl;
    }
};

int main() {
    cout << "--- Shallow Copy ---" << endl;
    Shallow s1("Hello");
    Shallow s2 = s1;  // Shallow copy
    s2.data[0] = 'X';
    s1.show();  // Shows: Xello — s1 is modified!
    s2.show();  // Xello

    cout << "--- Deep Copy ---" << endl;
    Deep d1("World");
    Deep d2 = d1;  // Deep copy
    d2.data[0] = 'Y';
    d1.show();  // World — d1 is intact!
    d2.show();  // Yorld

    return 0;
}
