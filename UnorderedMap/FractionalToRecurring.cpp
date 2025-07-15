class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
                if (denominator == 0) return "NaN";

        string ans;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }

        // Convert to long to avoid overflow (e.g., INT_MIN)
        long num = labs(numerator);
        long den = labs(denominator);

        // Integral part
        long integral = num / den;
        ans += to_string(integral);
        long rem = num % den;

        if (rem == 0) return ans;  // no fractional part

        ans += ".";

        unordered_map<long, int> pos;  // rem -> index in ans

        while (rem) {
            if (pos.count(rem)) {
                ans.insert(pos[rem], "(");
                ans += ")";
                break;
            }
            pos[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }

        return ans;
    }
};
