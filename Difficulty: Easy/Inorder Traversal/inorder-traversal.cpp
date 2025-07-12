/*
// Tree Node
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
    // Function to return a list containing the inorder traversal of the tree.
    void dfs(Node* root, vector<int>& ans) {
        if(root==nullptr) return;
        dfs(root->left,ans);
        ans.push_back(root->data);
        dfs(root->right,ans);
    }
    
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};