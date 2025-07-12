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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    
    void dfs(Node* root,vpii& pos,vpii& neg, int level,int cord) {
        if(root==nullptr) return;
        if(cord>=0) {
            if(pos.size()>cord && pos[cord].first>level) {
                pos[cord].first = level;
                pos[cord].second = root->data;
            }
            else if(pos.size()<=cord) {
                pos.push_back({level,root->data});
            }
        }
        else {
            int negCord = (0-cord);
            if(neg.size()>negCord && neg[negCord].first>level) {
                neg[negCord].first = level;
                neg[negCord].second = root->data;
            }
            else if(neg.size()<=negCord) {
                neg.push_back({level,root->data});
            }
        }
        dfs(root->left,pos,neg,level+1,cord-1);
        dfs(root->right,pos,neg,level+1,cord+1);
    }
    
    vector<int> topView(Node *root) {
        // code here
        vector<pair<int,int>> pos,neg;
        neg.push_back({-1,-1});
        
        vector<int> ans;
        int level = 0;
        int cord = 0;
        
        dfs(root,pos,neg,level,cord);
        
        for(int i = 1;i<neg.size();i++) {
            ans.push_back(neg[i].second);
        }
        
        reverse(ans.begin(),ans.end());
        
        for(int i = 0;i<pos.size();i++) {
            ans.push_back(pos[i].second);
        }
        return ans;
    }
};