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
    int solve(TreeNode* root, int& maxdia) {
        if(root==nullptr) {
            return 0;
        }
        int left = solve(root->left,maxdia);
        int right = solve(root->right,maxdia);
        maxdia = max(maxdia,left+right);
        return max(left,right)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {

        int maxdia = 0;
        solve(root,maxdia);

        return maxdia;
        
    }
};