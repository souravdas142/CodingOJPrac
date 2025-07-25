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
    void mirror(TreeNode* root) {
        if(!root) return;
        if(root->left) mirror(root->left);
        if(root->right) mirror(root->right);
        swap(root->left,root->right);
    }
    TreeNode* invertTree(TreeNode* root) {

        mirror(root);
        return root;
        
    }
};