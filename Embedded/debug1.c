#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Declare pointer (optional in this case since we do it in main)
void function_A(char **p) {
    *p = NULL;
}

void function_B(char **p) {
    printf("B:\n");
    *p = (char*)malloc(6 * sizeof(char));  // Allocate enough memory for "Hello" + '\0'
    assert(*p != NULL);
}

void function_C(char **p) {
    printf("C:\n");
    strcpy(*p, "Hello");  // Copies "Hello\0"
}

void function_D(char *p) {
    printf("D:\n");
    printf("%s\n", p);
}

void function_E(char **p) {
    printf("E:\n");
    free(*p);
    *p = NULL;
}

int main() {
    char *p = NULL;
    function_A(&p);   // Optional
    function_B(&p);
    function_C(&p);
    function_D(p);
    function_E(&p);
    return 0;
}
