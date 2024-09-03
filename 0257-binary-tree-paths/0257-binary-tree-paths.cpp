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
    private:
        void solve(TreeNode* root,string res,vector<string>& ans) {


            if(root==nullptr) return;
            if(root->left==nullptr && root->right==nullptr) {
                res+=to_string(root->val);
                ans.push_back(res);
                return;
            }

            res+=to_string(root->val)+"->";

            solve(root->left,res,ans);
            solve(root->right,res,ans);

        }
public:
    vector<string> binaryTreePaths(TreeNode* root) {


        vector<string> ans;
        if(root==nullptr) return ans;
        string res="";
        solve(root,res,ans);
        return ans;
        
    }
};