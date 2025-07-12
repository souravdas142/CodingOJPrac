/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

#define vpii vector<pair<int,int>>

class Solution {
  public:
     // Function to return a list containing the inorder traversal of the tree.
    void dfs(Node* root,int level, int cord,vpii& pos, vpii& neg ) {
        if(root==nullptr) return;
        dfs(root->left,level+1,cord-1,pos,neg);
        
        if(cord>=0) {
            if(pos.size()<=cord) pos.resize(cord+1,{-1,-1});
            if(pos[cord].first<=level) {
                pos[cord].first = level;
                pos[cord].second = root->data;
            }
            // else if(pos.size()<=cord) {
            //     pos.push_back({level,root->data});
            // }
        }
        else {
            int negCord = (0-cord);
             if(neg.size()<=negCord) neg.resize(negCord+1,{-1,-1});
            if(neg[negCord].first<=level) {
                neg[negCord].first = level;
                neg[negCord].second = root->data;
            }
            // else if(neg.size()<=cord) {
            //     neg.push_back({level,root->data});
            // }
        }
        
        dfs(root->right,level+1,cord+1,pos,neg);
    }
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        vpii pos,neg;
        //neg.push_back({-1,-1});
        
     
        int level = 0, cord = 0;
        dfs(root,level,cord,pos,neg);
        
        for(int i = neg.size()-1;i>0;i--) {
            ans.push_back(neg[i].second);
        }
        for(int i = 0;i<pos.size();i++) {
            ans.push_back(pos[i].second);
        }
        
        
        return ans;
    }
};