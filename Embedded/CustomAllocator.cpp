#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define HEAP_SIZE (1024 * 1024) // 1 MB heap

// Simulated heap space
static uint8_t heap[HEAP_SIZE];

// Metadata block structure
typedef struct metablock {
    size_t size;
    bool isFree;
    struct metablock* next;
} metablock;

static metablock* heapHead = NULL;

// Initialize the heap with one big free block
void initialiseHeap() {
    heapHead = (metablock*)heap;
    heapHead->size = HEAP_SIZE - sizeof(metablock);
    heapHead->isFree = true;
    heapHead->next = NULL;
}

// Split a block if large enough
void splitBlock(metablock* block, size_t size) {
    size_t remaining = block->size - size;
    if (remaining > sizeof(metablock)) {
        metablock* newBlock = (metablock*)((uint8_t*)block + sizeof(metablock) + size);
        newBlock->size = remaining - sizeof(metablock);
        newBlock->isFree = true;
        newBlock->next = block->next;

        block->size = size;
        block->next = newBlock;
    }
}

// Allocate memory using first-fit
void* my_malloc(size_t size) {
    metablock* current = heapHead;

    while (current) {
        if (current->isFree && current->size >= size) {
            splitBlock(current, size);
            current->isFree = false;
            return (uint8_t*)current + sizeof(metablock);
        }
        current = current->next;
    }

    return NULL; // No suitable block
}

// Free memory and coalesce adjacent free blocks
void my_free(void* ptr) {
    if (!ptr) return;

    metablock* block = (metablock*)((uint8_t*)ptr - sizeof(metablock));
    block->isFree = true;

    // Coalesce adjacent free blocks
    metablock* current = heapHead;
    while (current && current->next) {
        if (current->isFree && current->next->isFree) {
            current->size += sizeof(metablock) + current->next->size;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
}

// Debug: print heap state
void printHeapState() {
    printf("\nHeap State:\n");
    metablock* current = heapHead;
    int index = 0;
    while (current) {
        printf("Block %d | Addr: %p | Size: %zu | Free: %s\n", index++,
            (void*)current, current->size, current->isFree ? "yes" : "no");
        current = current->next;
    }
    printf("\n");
}

// Test usage
int main() {
    initialiseHeap();

    void* a = my_malloc(100);
    void* b = my_malloc(200);
    void* c = my_malloc(300);

    printHeapState();

    my_free(b);
    my_free(a);

    printHeapState();

    void* d = my_malloc(150); // Should reuse free space
    printHeapState();

    my_free(c);
    my_free(d);
    printHeapState();

    return 0;
}
