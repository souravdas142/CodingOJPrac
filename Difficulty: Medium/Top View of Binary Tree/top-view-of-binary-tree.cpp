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
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        map<int,int> mans;
        queue<pair<int,pair<int,Node*> > > que;
        
        
        que.push({0,{0,root}});
        while(!que.empty()) {
            
            int n = que.size();
            for(int i = 0;i<n;i++) {
                pair<int,pair<int,Node*> > curNodes = que.front();
                if(mans.find(curNodes.first)==mans.end()) {
                    mans[curNodes.first] = curNodes.second.second->data;
                }
                que.pop();
                
                if(curNodes.second.second->left) {
                    que.push({curNodes.first-1,{curNodes.second.first+1,curNodes.second.second->left}});
                    
                }
                if(curNodes.second.second->right) {
                    que.push({curNodes.first+1,{curNodes.second.first+1,curNodes.second.second->right}});
                }
            }
        }
        
        for(auto ele: mans) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};