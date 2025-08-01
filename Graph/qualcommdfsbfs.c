#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph as array of adjacency lists
Node* adjList[MAX];

// Visited arrays for DFS and BFS
bool visited[MAX];

// Create a node
Node* createNode(int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void dfs(int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

//we don't have something called adjacent list or unordered map, so we traverse like linked list
    Node* temp = adjList[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs(temp->vertex);
        temp = temp->next;
    }
}


//Implementing a queue like 
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front == rear;
}

void bfs(int start) {
    for (int i = 0; i < MAX; i++) visited[i] = false;
    
    visited[start] = true;
    enqueue(start);

    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        Node* temp = adjList[curr];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = true;
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
    }
}
