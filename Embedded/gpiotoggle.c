GPIO Toggling: If a General Purpose Input/Output (GPIO) pin is configured as an output, write a C code snippet to toggle this pin 
(i.e., change its state from HIGH to LOW or LOW to HIGH) every 500 milliseconds without using a delay() function. 
You can assume a system clock of 16 MHz and the availability of a timer peripheral.


16 Mhz = 16,000,0000 ticks per seond. //10 to power 6.
1 ms = 16,0000 ticks
500 ms is 8,000,000 ticks.

Most micro-controller are 32 bit or 16 bit to count large interval.
Hence, we must use a pre-scaler.
16/128 =  125,000 Hz
1 ms = 125 ticks

so set time to 62,500 for 500 ms.
Pre-scaler is circuit on micro-controller that divies the input clock frequency by a fixed integer value before its provided to the counter.
  GPIO Toggling: If a General Purpose Input/Output (GPIO) pin is configured as an output, write a C code snippet to toggle this pin (i.e., change its state from HIGH to LOW or LOW to HIGH) every 500 milliseconds without using a delay() function. You can assume a system clock of 16 MHz and the availability of a timer peripheral.



