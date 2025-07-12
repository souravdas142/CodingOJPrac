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
     // Function to return a list containing the inorder traversal of the tree.
    void dfs(Node* root,int level, int cord,map<int,pair<int,int> >& mp ) {
        if(root==nullptr) return;
        dfs(root->left,level+1,cord-1,mp);
        if(mp.find(cord)==mp.end()) {
            mp.insert({cord,{level,root->data}});
        }
        else {
            if(mp[cord].first<=level) {
                mp[cord].first = level;
                mp[cord].second = root->data;
            }
        }
        dfs(root->right,level+1,cord+1,mp);
    }
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int,pair<int,int> > mp;
        int level = 0, cord = 0;
        dfs(root,level,cord,mp);
        for(auto it: mp) {
            ans.push_back(it.second.second);
        }
        return ans;
    }
};