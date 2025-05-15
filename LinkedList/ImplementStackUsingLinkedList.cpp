#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* head;  // top of the stack

public:
    Stack() {
        head = nullptr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Push element onto stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow");
        }
        int topData = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return topData;
    }

    // Peek top element
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return head->data;
    }

    // Display stack contents
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to clean up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
