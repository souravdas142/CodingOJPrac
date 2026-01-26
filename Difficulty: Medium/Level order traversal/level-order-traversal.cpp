/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        queue<Node*> que;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        que.push(root);
        
        while(!que.empty()) {
            int sz = que.size();
            vector<int> tmp;
            for(int i = 0;i<sz;i++) {
                Node* parent = que.front();
                que.pop();
                tmp.push_back(parent->data);
                if(parent->left!=nullptr) que.push(parent->left);
                if(parent->right!=nullptr) que.push(parent->right);
                
            }
            ans.push_back(tmp);
        }
        return ans;
    }
    
};