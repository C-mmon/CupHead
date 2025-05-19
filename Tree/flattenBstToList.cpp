#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node* left;
  Node* right;
  int val;
  Node(int data): val(data), left(NULL), right(NULL){}
};

void flattenBstToList(Node* root, vector <Node*> res)
{
  if(!root) return nullptr;
  flattenBstToList(root->left);
  res.push_back(root->val);
  flattenBstToList(root->right);
}

//lets understand in place manipulation, where all the left child is set to NULL and the right child has to contain some valid value 
//Think about overall, you are traversing, lets say you visited some element X, now the node,previous to X, lets call it a node y.
// that means node y -> right must point to this given node.
// this made us realise, we need to track the previous node

Node* head= NU
//How does it work, we must go completely left
//mark the current node 
void flattenBstToList2(Node* root, Node* prev)
{
  if(!root) return nullptr;
   flattenBstToList2(root->left, prev);
  root->left = NULL;
  //if there exist prev 
  if(prev)
    prev->right = root;
  //move the pr
  prev = root;
  flattenBstToList2(root->right, prev);
  pre

//tree creator function
int main()
{
}
