/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        vector<vector<int> > ans;
        if(root==nullptr) return ans;
         
        queue<pair<int,pair<int,Node*> > > que; // verticalLines, 
                                            // levels
                                            // nodes
                                            
        
        map<int,vector<int> > mans; // verticalLines, 
                                            // levels
                                            // nodes
                                            
        
        que.push({0,{0,root}});
        
        while(!que.empty()) {
            
            int n = que.size();
            for(int i = 0;i<n;i++) {
                pair<int,pair<int,Node*> > curNode = que.front();
                mans[curNode.first].push_back(curNode.second.second->data);
                que.pop();
                if(curNode.second.second->left) {
                    que.push({curNode.first-1,{curNode.second.first+1,curNode.second.second->left}});
                    
                
                }
                if(curNode.second.second->right) {
                    que.push({curNode.first+1,{curNode.second.first+1,curNode.second.second->right}});
                }
            }
            
        }
        
        for(auto ele: mans) {
            ans.push_back(ele.second);
        }
        
        return ans;
        
    }
};