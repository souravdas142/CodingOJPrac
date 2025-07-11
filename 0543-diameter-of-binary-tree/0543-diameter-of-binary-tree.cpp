/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root,int& ans) {
        if(root==nullptr) return 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        if(left+right>ans) {
            ans = left+right;
        }
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        int ans = 0;
        dfs(root,ans);
        return ans;
        
    }
};