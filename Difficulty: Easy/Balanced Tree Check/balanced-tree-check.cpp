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
    int dfs(Node* root, int level, int& ans) {
        if(root==nullptr) return 0;
        int left = dfs(root->left,level+1,ans);
        if(left==-1) return -1;
        int right = dfs(root->right,level+1,ans);
        if(right==-1) return -1;
        if(abs(left-right)>1) {
            ans = -1;
            return -1;
        }
        return 1+max(left,right);
    }
    bool isBalanced(Node* root) {
        // Code here
        int level = 0;
        int ans = 0;
        dfs(root,level,ans);
        if(ans == -1) return false;
        return true;
    }
};