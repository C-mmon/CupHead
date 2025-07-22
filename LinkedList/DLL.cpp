#include <iostream>
using namespace std;

struct DLL {
    int data;
    DLL* next;
    DLL* prev;
};

int main() {
    // Step 1: Create a simple doubly linked list: 1 <-> 2 <-> 3
    DLL* node1 = new DLL{1, nullptr, nullptr};
    DLL* node2 = new DLL{2, nullptr, node1};
    DLL* node3 = new DLL{3, nullptr, node2};
    node1->next = node2;
    node2->next = node3;

    DLL* head = node1;

    // Step 2: Reverse the list
    DLL* curr = head;
    DLL* temp = nullptr;

    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;  // because we swapped next and prev
    }

    // Step 3: Update head to new first node
    if (temp != nullptr) {
        head = temp->prev;  // temp is the last non-null node processed
    }

    // Step 4: Print the reversed list
    DLL* print = head;
    while (print != nullptr) {
        cout << print->data << " ";
        print = print->next;
    }
    cout << endl;

    return 0;
}
