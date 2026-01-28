/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
    void solve(Node* root, int level, vector<int>& ans) {
        
        if(root==nullptr) return;
        
        if(level==ans.size()) ans.push_back(root->data);
        
        solve(root->right,level+1,ans);
        solve(root->left,level+1,ans);
        
    }
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        
        solve(root,0,ans);
        
        
        return ans;
    }
};