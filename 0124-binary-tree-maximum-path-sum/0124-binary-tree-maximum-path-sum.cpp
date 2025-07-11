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
    int dfs(TreeNode* root, int& ans) {
        if(root== nullptr) return 0;
        int left = max(0,dfs(root->left,ans));
        int right = max(0,dfs(root->right,ans));
        ans = max(ans,left+root->val+right);
        return max(root->val,max(left+root->val,right+root->val));
    }
    int maxPathSum(TreeNode* root) {
        int ans =  INT_MIN;
        dfs(root,ans);
        return ans;
        
    }
};