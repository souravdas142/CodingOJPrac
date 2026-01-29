/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    void solve(Node* root, int level, vector<vector<int>>& zvec) {
        if(root==nullptr) return;
        
        
        
        if(level&1) {
            if(level==zvec.size()) {
                zvec.push_back({root->data});
            }
            else {
                zvec[level].insert(zvec[level].begin(),root->data);
            }
        }
        else {
            if(level==zvec.size()) {
                zvec.push_back({root->data});
            }
            else {
                zvec[level].push_back(root->data);
            }
        }
        
        
        solve(root->left,level+1,zvec);
        solve(root->right,level+1,zvec);
        
    }
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<vector<int>> zvec;
        vector<int> ans;
        
        
        int level = 0;
        
        solve(root,level,zvec);
        
        
        for(auto& v:zvec) {
            ans.insert(ans.end(),v.begin(),v.end());
        }
        
        return ans;
    }
};