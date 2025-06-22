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

    int balanced(TreeNode* root) {
        if(root==nullptr) return 0;
        int left = 1+balanced(root->left);
        if(left<0) return -1;
        int right = 1+balanced(root->right);
        if(right<0) return -1;

        if(abs(left-right)>1)   
            return -1;

        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {

        if(balanced(root) < 0) {
            return false;
        }

        return true;
        
    }
};