/*Code-3*/
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 31;

int main()
{
    //malloc size, size of 31 will be converted to byte, and we would get 31 byte
    int* data = (int*)malloc(SIZE);
    for(unsigned int i= SIZE-1;i>=0;i--)  //unsigned can never be negative
    value*/
    {
        *data = (i>>4) ;
        data++;
    }
    free(data); //free called on invvalid ptr
    return 0;
}


//Copy string maybe
#include <stdio.h>
#include<stdlib.h>

char *copy_string(char *input_string)
{
    char *return_string = malloc(sizeof(strlen(input_string)));
    printf("input_string: %s\n",input_string); // output : HELLO
    char *ptr = return_string; // This change has to be required 
    while(*input_string != '\0')
    {
        *return_string++ = *input_string++;
        printf("input_string: %c\n",*input_string); //Output: e,l,l,o
        printf("return_string: %c\n",*return_string); //Output : empty
        
    }
    printf("return_string_after_while: %s\n",return_string);//Output: empty
    printf("input_string_after_while: %s\n",input_string); // Output: empty
    *return_string = '\0';
    printf("final_string: %s\n",ptr);
    return ptr; // Returning return_string will not achieve the desired result
}

int main()
{
    char *example_string = "Hello";
    char *disp_string = copy_string(example_string);
    printf("Final_Result: %s\n",disp_string);
    return 0;
}


int extract_signed_byte(packed_t word, int index) {
    return ((int)((word >> (index * 8)) & 0xFF) << 24) >> 24;
  //we promote the right shifted to int and then we left shift by24 bit, and then fina
//((int)0xF8 << 24) >> 24
  //0xF8000000 → arithmetic shift → 0xFFFFFFF8
  //(int)0xF8 = 0x000000F8
//0x000000F8 << 24 = 0xF8000000
  //0xF8000000 >> 24 = 0xFFFFFFF8


}

int main() {
    packed_t word = 0xA0FF032C;
    int b2 = extract_signed_byte(word, 2); // expected -1
    int b3 = extract_signed_byte(word, 3); // expected -96
    printf("b2 = %d\n", b2);  // Output: -1
    printf("b3 = %d\n", b3);  // Output: -96
}
