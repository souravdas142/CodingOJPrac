/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        // code here
        
        if(root->left == nullptr && root->right==nullptr) {
            return 0;
        }
        
        int left = 0;
        
        if(root->left)
            left = height(root->left);
        int right = 0;
        if(root->right)
            right = height(root->right);
        
        return max(left,right)+1;
    }
};