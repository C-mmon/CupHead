class Solution {
public:
    string convert(string s, int numRows) {
        //how does the pattern goes down then up
        // what element will fall in between, only those element whose 
        // every numsRow element will fall in between
        //but there can be more element in between
        //how do we identify the diagonal size, d
        // numsRow 2 there will be no digaonl, 3 there will be 1 
        // 4 there will be two,
        //so nonce we, reach numrow, aafter that we need to print numsRow-2 element in  total starting from nums row
        //there will be atleast numsRow partition for which we can put element 
        //how to determine the size, the top and bottom will have no diagonal, that means all the element in between will atleast one more extra element
        //we will have 3 function, bottom and top fun1 and middle func2.
        if (numRows == 1 || s.size() <= numRows) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string result;
        for (string &row : rows) result += row;
        return result;
    }
};
