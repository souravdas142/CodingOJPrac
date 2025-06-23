/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
   
        if(!root) return {};
        
 
        vector<vector<int> > ans;
        
        deque<Node*> dq;
        dq.push_back(root);
        ans.push_back({root->data});
        while(!dq.empty()) {
            int n = dq.size();
            vector<int> res;
            for(int i = 0;i<n;i++) {
                Node* cur = dq.front();
                dq.pop_front();
                if(cur->left) {
                    dq.push_back(cur->left);
                    res.push_back(cur->left->data);
                }
                if(cur->right) {
                    dq.push_back(cur->right);
                    res.push_back(cur->right->data);
                }
            }
            ans.push_back(res);
        }
        
       
        vector<int> res;
        int n = ans.size();
        for(int j = n-1;j>=0;j--) {
            int k = ans[j].size();
            for(int l = 0;l<k;l++) {
                res.push_back(ans[j][l]);
            }
        }
        
        return res;
        
        
        
        
    }
};