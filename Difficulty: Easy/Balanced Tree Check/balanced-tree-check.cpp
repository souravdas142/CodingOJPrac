/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
    int dfs(Node* root, int &ans) {
        if(root==nullptr) return 0;
        int left = dfs(root->left,ans);
        if(left<0) return -1;
        int right = dfs(root->right,ans);
        if(right<0) return -1;
        if(abs(right-left)>1)return -1;
        
        return 1+max(left,right);
    }
    bool isBalanced(Node* root) {
        // Code here
        int ans = 0;
        int k = 0;
        k = dfs(root,ans);
        if(k<0) return false;
        return true;
    }
};