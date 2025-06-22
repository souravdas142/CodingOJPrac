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
    vector<int> inorderTraversal(TreeNode* root) {

        if(!root) return {};

        stack<TreeNode*> st;
        //st.push(root);
        vector<int> ans;
        TreeNode* cur = root;

        while(true) {
            if(cur!=nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                if(st.empty()) break;
                ans.push_back(st.top()->val);
                cur = st.top();
                st.pop();
                cur = cur->right;
            }
        }

        return ans;
        
    }
};