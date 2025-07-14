class Solution {
public:
    int divide(int dividend, int divisor) {
       // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Convert to long to avoid overflow
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        long ans = 0;

        // Subtract multiples using bit shifting
        while (dvd >= dvs) {
            long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            ans += multiple;
        }

        // Check signs
        return (dividend > 0) == (divisor > 0) ? ans : -ans;
    }
};
