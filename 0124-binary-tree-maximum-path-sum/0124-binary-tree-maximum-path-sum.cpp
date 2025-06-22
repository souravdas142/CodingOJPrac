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
    int solve(TreeNode* root, int& ans) {
        if(root->left == nullptr || root->right==nullptr) {
            return root->val;

        }
        int left = solve(root->left,ans);
        int right = solve(root->right,ans);

        int cur = max(left+right+root->val,max(left,right));
        return cur;
    }
    int maxPathSum(TreeNode* root) {
        int ans = 0;
        ans = solve(root,ans);
        //ans = max(0,ans);
        return ans;
        
    }
};