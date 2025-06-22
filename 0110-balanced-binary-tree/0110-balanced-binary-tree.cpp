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
    int maxHeight(TreeNode* root,int& ans) {
        if(root==nullptr) {
            return 0;
        }
        int left = maxHeight(root->left,ans);
        int right = maxHeight(root->right,ans);

        ans = max(ans,abs(left-right));
        int cur = max(left,right)+1;
        
        
   
        return cur;
    }


    bool isBalanced(TreeNode* root) {

        int maxdiff = 0;
        maxHeight(root,maxdiff);
        if(maxdiff>1) return false;
        return true;

   
        
    }
};