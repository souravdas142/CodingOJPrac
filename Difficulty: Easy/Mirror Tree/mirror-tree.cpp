/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* mirrorSolve(Node* root) {
        
        if(root==nullptr) return nullptr;
        
        Node* left = mirrorSolve(root->left);
        Node* right = mirrorSolve(root->right);
        
        root->left = right;
        root->right = left;
        
        return root;
        
    }
    void mirror(Node* root) {
        // code here
        mirrorSolve(root);
    }
};