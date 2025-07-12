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
    int dfs(Node* node) {
        if(node==nullptr) return 0;
        if(node->left==nullptr && node->right == nullptr) {
            
            int x = node->data;
            node->data = 0;
            return x;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        int y = node->data;
        node->data = left+right;
        return node->data+y;
    }
    void toSumTree(Node *node) {
        // Your code here
        
        dfs(node);
        
    }
};