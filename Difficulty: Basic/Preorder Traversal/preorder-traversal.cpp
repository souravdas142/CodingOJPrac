/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int>& ans) {
        // root left right
        
        if(root==nullptr) return;
        ans.push_back(root->data);
        solve(root->left, ans);
        solve(root->right, ans);
    }
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};