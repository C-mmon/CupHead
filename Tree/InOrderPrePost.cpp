#include <iostream>
using namespace std;

// Binary Tree Node class
class Node {
public:
    Node* left;
    Node* right;
    int val;

    // Constructor to initialize the node
    Node(int data) : val(data), left(nullptr), right(nullptr) {
        // Constructor body empty
    }
};

// Function to find predecessor and successor of a given key in BST
void findPreDesc(Node* root, Node*& pre, Node*& succ, int key) {
    while (root != nullptr) {
        if (root->val > key) {
            succ = root; // Successor is updated
            root = root->left; // Travel to the left subtree
        } else if (root->val < key) {
            pre = root; // Predecessor is updated
            root = root->right; // Travel to the right subtree
        } else {
            // Key matches the current node
            if (root->left != nullptr) {
                pre = rightMost(root->left); // Find the right-most node in the left subtree
            }
            if (root->right != nullptr) {
                succ = leftMost(root->right); // Find the left-most node in the right subtree
            }
            break; // Exit the loop after finding the key
        }
    }
}

// Helper function to find the right-most node in a subtree
Node* rightMost(Node* node) {
    while (node != nullptr && node->right != nullptr) {
        node = node->right;
    }
    return node;
}

// Helper function to find the left-most node in a subtree
Node* leftMost(Node* node) {
    while (node != nullptr && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

int main() {
    // Example usage
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    Node* pre = nullptr;
    Node* succ = nullptr;
    int key = 10;

    // Find predecessor and successor
    findPreDesc(root, pre, succ, key);

    // Print results
    if (pre != nullptr) {
        cout << "Predecessor: " << pre->val << endl;
    } else {
        cout << "No Predecessor" << endl;
    }

    if (succ != nullptr) {
        cout << "Successor: " << succ->val << endl;
    } else {
        cout << "No Successor" << endl;
    }

    return 0;
}
