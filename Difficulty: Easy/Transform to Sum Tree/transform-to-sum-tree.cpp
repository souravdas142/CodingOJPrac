/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int dfs(Node* root) {
        if(root==nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int tmp = root->data;
        int res = left+right;
        root->data = res;
        //if(root->left == nullptr && root->right==nullptr) root->data = 0;
        return res+tmp;
    }
    void toSumTree(Node *node) {
        // Your code here
        dfs(node);
    }
};