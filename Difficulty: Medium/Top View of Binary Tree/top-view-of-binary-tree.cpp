/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void dfs(Node* root,int cord,int level, map<int,pair<int,int>>& mp) {
        if(root==nullptr) return;
        if(mp.find(cord)==mp.end()) {
            mp.insert({cord,{level,root->data}});
        }
        else {
            if(mp[cord].first>level) {
                mp[cord].first = level;
                mp[cord].second = root->data;
            }
        }
        dfs(root->left,cord-1,level+1,mp);
        dfs(root->right,cord+1,level+1,mp);
    }
    vector<int> topView(Node *root) {
        
        // code here
        int co_ordinates = 0;
        int level = 0;
        map<int,pair<int,int> > mp;
        dfs(root,co_ordinates,level,mp);
        vector<int> ans;
        for(auto it:mp) {
            ans.push_back(it.second.second);
        }
        return ans;
        
    }
};