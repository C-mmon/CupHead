#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Fruit()
{
    char *Input = malloc(strlen("Hello World") + 1);  // +1 for '\0'
    if (Input == NULL) {
        perror("malloc failed");
        return;
    }

    strcpy(Input, "Hello World");  // Safe copy
    printf("%s\n", Input);
    free(Input);  // Now safe
}
