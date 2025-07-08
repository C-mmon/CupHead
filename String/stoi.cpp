class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        // skip the + sign as well
        bool sign = false;
        if (s[i] == '-') {
            sign = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        int sum = 0;
        int num;
        while (i < s.size() && isdigit(s[i])) {
            int num = s[i] - '0';
            if (sum > (INT_MAX - num) / 10)
                {
                    if (sign) {
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
            else {a
                sum = sum * 10 + num;
            }
            i++;
        }
        if(sign)
        {
            return -sum;
        }
        return sum;
    }
};
