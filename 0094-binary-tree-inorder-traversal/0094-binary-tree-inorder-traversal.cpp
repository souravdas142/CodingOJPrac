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

        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*> st;
        st.push(root);
        map<TreeNode*,bool> mark;
        mark[nullptr] = true;

        while(!st.empty()) {
            TreeNode* cur = st.top();
            while(cur->left!=nullptr && mark[cur->left]!=true) {
                cur=cur->left;
                st.push(cur);
            }
            ans.push_back(st.top()->val);
            mark[st.top()]=true;
            cur=st.top()->right;
            st.pop();
            if(cur!=nullptr)
                st.push(cur);
        }
        
        return ans;


        
    }
};