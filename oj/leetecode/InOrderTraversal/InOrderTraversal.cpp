#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.
 */
 class TreeNode {
     public:
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void CreateNodes() {
        TreeNode* root = new TreeNode(1);
        root->right=new TreeNode(2);
        (root->right)->left = new TreeNode(3);
        
        vector<int> ans;
        
        ans = inorderTraversal(root);
        
        cout<<endl;
        for(auto i: ans) {
            cout<<i<<" ";
        }
        cout<<endl;


        
    }
/*
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*> st;
        st.push(root);
        map<TreeNode*,bool> mark;
        mark[nullptr]=true;
        while(!st.empty()) {
            TreeNode* cur = st.top();
            cout<<__LINE__<<endl;
            if(mark[cur->left]==true) {
                cout<<__LINE__<<endl;
                st.pop();
            }
            if(cur->right!=nullptr && mark[cur->right]!=true) { 
                cout<<__LINE__<<endl;
                st.push(cur->right);
            }

            if(cur->left!=nullptr && mark[cur->left]!=true) {
                cout<<__LINE__<<endl;
                st.push(cur->left);
            }

            if(mark[cur->left]==true) {
                ans.push_back(cur->val);
                mark[cur] = true;
                cout<<__LINE__<<endl;
            }

        }

        return ans;
        
    }
*/
    

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

int main() {
    Solution sl;
    sl.CreateNodes();
    
}