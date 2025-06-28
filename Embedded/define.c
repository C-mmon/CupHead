#include <stdio.h>

#define year(_year_) (((_year_) % 4 == 0 && ((_year_) % 100 != 0 || (_year_) % 400 == 0)) ? 366 : 365)
#define seconds(yr) (year(yr) * 24 * 60 * 60)

int main()
{
    printf("Hello World %d " , seconds(2050));
    return 0;
}

//Problem with the above code is, the code will only work for 32 bit.

//This will create a problem because for 16 bit, the value will only be 32,767 (signed integer)

//Use this
#define SECONDS (86400L)
#define seconds(yr) ((long)(year(yr)) * SECONDS)
  //This will be stored in the memory layout.
  //It has no memory footprint by itself., this is preproceessor memory
