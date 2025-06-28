
#include <stdio.h>

#define PERIPHERAL_REGISTER ((volatile uint16_t*)0x67a9)
void set_register_value(void)
{
    *PERIPHERAL_REGISTER = 0xaa55;
}

int main(void)
{
    set_register_value();
    
    // The program would continue its main loop or other tasks here.
    while(1)
    {
        // Infinite loop, common in embedded systems
    }
    
    return 0;
}
