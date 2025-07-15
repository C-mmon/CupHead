class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int parent = kthValue(level - 1, (k + 1) / 2);
        bool isRightChild = (k % 2 == 0);

        if (isRightChild)
            return parent ^ 1; // right child is flipped
        else
            return parent; // left child is same as parent
    }
};
