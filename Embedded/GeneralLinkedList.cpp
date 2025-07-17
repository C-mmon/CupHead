#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generic node
typedef struct Node {
    struct Node* next;
    size_t sizeOfElement;
    void* data;
    void (*handler)(void*);  // function to print or handle data
} Node;


void* my_memcpy(void* dest, const void* src, size_t n) {
    // Cast to char* to perform byte-by-byte copy
    char* d = (char*)dest;
    const char* s = (const char*)src;

    for (size_t i = 0; i < n; ++i) {
        d[i] = s[i];
    }

    return dest;
}

// Function to create a new node with given data and handler
Node* createNode(void* srcData, size_t size, void (*handler)(void*)) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate Node");
        exit(1);
    }

    newNode->sizeOfElement = size;
    newNode->data = malloc(size);
    if (!newNode->data) {
        perror("Failed to allocate Node data");
        exit(1);
    }
    my_memcpy(newNode->data, srcData, size);  // copy user's data into node
    newNode->handler = handler;
    newNode->next = NULL;
    return newNode;
}

// Traversal
void traverseList(Node* head) {
    Node* temp = head;
    while (temp) {
        temp->handler(temp->data);  // invoke type-specific handler
        temp = temp->next;
    }
}

// Example handler for int
void handleInt(void* data) {
    printf("Int: %d\n", *(int*)data);
}

// Example handler for float
void handleFloat(void* data) {
    printf("Float: %.2f\n", *(float*)data);
}

// Example user-defined struct
typedef struct {
    int id;
    char name[20];
} Person;

void handlePerson(void* data) {
    Person* p = (Person*)data;
    printf("Person: ID=%d, Name=%s\n", p->id, p->name);
}

// Optional: Free list
void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

// Main demo
int main() {
    Node* head = NULL;

    // Add an int
    int x = 42;
    head = createNode(&x, sizeof(int), handleInt);

    // Add a float
    float f = 3.14f;
    head->next = createNode(&f, sizeof(float), handleFloat);

    // Add a person struct
    Person p = {1, "Alice"};
    head->next->next = createNode(&p, sizeof(Person), handlePerson);

    // Traverse and print
    traverseList(head);

    // Cleanup
    freeList(head);
    return 0;
}
