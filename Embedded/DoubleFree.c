void foo()
{
    static char* Input = (char*)malloc(30);
    Input[0] = '\0';
    free(Input);
    Input = NULL;
}

foo();
foo(); // Issue-1: It would be here as you calling free on Null Pointer
