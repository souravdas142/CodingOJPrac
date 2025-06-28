/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()) {
            Node* curNode = que.front();
            que.pop();
            while(curNode) {
                ans.push_back(curNode->data);
                if(curNode->left) que.push(curNode->left);
                curNode = curNode->right;
            }
            
        }
        return ans;
    }
};