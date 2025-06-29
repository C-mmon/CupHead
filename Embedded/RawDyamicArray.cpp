#include <iostream>
#include <cstring>

class RawDynamicArray {
private:
    void* data;
    size_t element_size;
    size_t capacity;
    size_t length;

    void resize(size_t new_capacity) {
        void* new_data = malloc(new_capacity * element_size);
        std::memcpy(new_data, data, length * element_size);
        free(data);
        data = new_data;
        capacity = new_capacity;
    }

public:
    RawDynamicArray(size_t elem_size, size_t initial_capacity = 4)
        : element_size(elem_size), capacity(initial_capacity), length(0) {
        data = malloc(element_size * capacity);
    }

    ~RawDynamicArray() {
        free(data);
    }

    void push_back(void* element) {
        if (length == capacity) {
            resize(capacity * 2);
        }
        void* dest = (char*)data + (length * element_size);
        std::memcpy(dest, element, element_size);
        ++length;
    }

    void* get(size_t index) const {
        return (char*)data + (index * element_size);
    }

    size_t size() const { return length; }
    size_t get_capacity() const { return capacity; }
};


int main() {
    RawDynamicArray arr(sizeof(int));

    int x = 10, y = 20, z = 30;
    arr.push_back(&x);
    arr.push_back(&y);
    arr.push_back(&z);

    for (size_t i = 0; i < arr.size(); ++i) {
        int* val = (int*)arr.get(i);
        std::cout << *val << std::endl;
    }

    return 0;
}
