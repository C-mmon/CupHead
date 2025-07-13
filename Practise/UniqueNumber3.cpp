#include <iostream>
#include <vector>
using namespace std;

int getSingle(vector<int>& arr) {
    int result = 0, x, sum;

    // Iterate through every bit (from 0 to 31)
    for (int i = 0; i < 32; i++) {
        sum = 0;
        
         // Get the mask for the i-th bit position
        x = (1 << i); 

        // Iterate over the array and count the number of set
        // bits at position i
        for (int j = 0; j < arr.size(); j++) {
            
            // Check if the i-th bit is set in arr[j]
            if (arr[j] & x) {  
                sum++;
            }
        }

        // If sum is not a multiple of 3, it's part of the unique element
        if ((sum % 3) != 0) {
            result |= x;
        }
    }

    return result;  
}
