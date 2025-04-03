/*
Problem Breakdown: Finding Ranks in a Stream of Numbers

1. Input Processing:
   - Read a stream of numbers one by one
   - Example input: [5, 4, 6, 1]

2. Binary Search Tree (BST) Structure:
   - Each node stores:
     * Value (the number)
     * Left child pointer (for smaller values)
     * Right child pointer (for larger values)
     * Right_size (count of nodes in right subtree)
   - BST property: left < root < right

3. Insertion Process (insert function):
   a. If tree is empty, create root node
   b. Find insertion position while tracking path
   c. Insert new node at correct position
   d. Update right_size for affected nodes

4. Rank Calculation (get_rank function):
   a. Start from root with count = 0
   b. For each node traversed:
      - If value < current node:
        * Add (1 + right_size) to count
        * Go left
      - If value >= current node:
        * Go right
   c. Return (count + 1) as rank

5. Memory Management:
   - Allocate nodes dynamically
   - Clean up all nodes when done

Example Walkthrough:
Input: [5, 4, 6, 1]
Step 1: Insert 5 -> Rank 1 (first element)
Step 2: Insert 4 -> Rank 2 (smaller than 5)
Step 3: Insert 6 -> Rank 1 (larger than both)
Step 4: Insert 1 -> Rank 4 (smallest of all)
Output: [1, 2, 1, 4]
*/

// Problem: Given a stream of person strengths, find the rank of each person in the stream
// Example stream: [5, 4, 6, 1]
// Output: [1, 2, 1, 4]
// Solution: Using Binary Search Tree (BST) to maintain order and calculate ranks

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Node class represents a node in the Binary Search Tree
// Each node stores a value, pointers to left and right children,
// and the size of its right subtree
class Node {
public:
    int value;          // Value stored in the node
    Node* left;         // Pointer to left child
    Node* right;        // Pointer to right child
    int right_size;     // Number of nodes in right subtree

    // Constructor initializes a new node with given value
    Node(int val) : value(val), left(nullptr), right(nullptr), right_size(0) {}
};

// Insert a new value into the BST and maintain right_size property
// Returns: Root node of the modified tree
Node* insert(Node* root, int value) {
    // If tree is empty, create new root node
    if (root == nullptr) {
        return new Node(value);
    }

    // Store path taken during insertion for updating right_size
    std::vector<std::pair<Node*, std::string>> path;
    Node* current = root;
    Node* parent = nullptr;
    std::string direction;

    // Find insertion position and track path
    while (true) {
        parent = current;
        if (value < current->value) {
            // Go left if value is smaller
            direction = "left";
            path.push_back({current, "left"});
            current = current->left;
            if (current == nullptr) break;
        } else {
            // Go right if value is greater or equal
            direction = "right";
            path.push_back({current, "right"});
            current = current->right;
            if (current == nullptr) break;
        }
    }

    // Create and insert new node
    Node* new_node = new Node(value);
    if (direction == "left") {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    // Update right_size for all nodes where we went right
    for (const auto& p : path) {
        if (p.second == "right") {
            p.first->right_size += 1;
        }
    }

    return root;
}

// Calculate rank of a value in the BST
// Rank is 1-based position of the value if the tree was sorted
int get_rank(Node* root, int value) {
    int count = 0;
    Node* current = root;

    while (current) {
        if (value < current->value) {
            // Add current node and its right subtree to count
            count += 1 + current->right_size;
            current = current->left;
        } else {
            // Move to right without counting
            current = current->right;
        }
    }

    return count + 1;
}

// Recursively delete all nodes in the tree to prevent memory leaks
void cleanup(Node* root) {
    if (root == nullptr) return;
    cleanup(root->left);
    cleanup(root->right);
    delete root;
}

int main() {
    // Read input line
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    
    Node* root = nullptr;
    std::vector<std::string> output;
    int num;

    // Process each number in the input stream
    while (iss >> num) {
        // Insert number and get its rank
        root = insert(root, num);
        int rank = get_rank(root, num);
        output.push_back(std::to_string(rank));
    }

    // Print results with space separation
    for (size_t i = 0; i < output.size(); ++i) {
        std::cout << output[i];
        if (i < output.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;

    // Clean up allocated memory
    cleanup(root);
    return 0;
}