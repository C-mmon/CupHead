/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/


Node* zero = new Node(false, true);
Node* one = new Node(true, true);

class Solution {
public:
    Node* create(vector<vector<int>>& grid, int x, int y, int n) {
        if (n == 1) {
            return grid[x][y] == 1 ? one : zero;
        }
        int mid = n / 2;
        Node *topLeft = create(grid, x, y, mid);
        Node *topRight = create(grid, x, y+mid, mid);
        Node *botLeft = create(grid, x+mid, y, mid);
        Node *botRight = create(grid, x+mid, y+mid, mid);
        if (topLeft == topRight and botLeft == botRight and topLeft == botLeft) {
            return topLeft;
        }
        return new Node(false, false, topLeft, topRight, botLeft, botRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return create(grid, 0, 0, grid.size());    
    }
};
