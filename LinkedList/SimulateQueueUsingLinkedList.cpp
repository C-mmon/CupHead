#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

// Initialize queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    return q;
}

// Enqueue operation
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->tail == NULL) {
        // Empty queue
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

// Dequeue operation
int dequeue(Queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* temp = q->head;
    int result = temp->data;
    q->head = q->head->next;

    if (q->head == NULL)
        q->tail = NULL;

    free(temp);
    return result;
}

// Peek front
int front(Queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->head->data;
}

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->head == NULL;
}
