/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    /*You are required to complete this method*/
    int dfs(Node* root) {
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        if(left == -1) return -1;
        int right = dfs(root->right);
        if(right == -1) return right;
        if(left!=right && left>0 && right>0) return -1;
        
        if(left==0) return right+1;
        return left+1;
    }
    bool check(Node *root) {
        // Your code here
        int ans = dfs(root);
        if(ans == -1) return false;
        return true;
    }
};