/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */

// @lc code=start
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
    
    int findminDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        int left = findminDepth(root->left);
        int right = findminDepth(root->right);
        return (min(left,right)+1);


    }

    int minDepth(TreeNode* root) {
        
        int minDepth_=0;
        if(root!=nullptr)
            minDepth_=findminDepth(root);
        
        return minDepth_;
        
    }
};
// @lc code=end

