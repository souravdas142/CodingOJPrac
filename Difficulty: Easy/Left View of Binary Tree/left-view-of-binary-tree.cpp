/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    void dfs(Node* root, int level,vector<int>& res) {
        if(root==nullptr) return;
        if(level == res.size()) {
            res.push_back(root->data);
        }
        dfs(root->left,level+1,res);
        dfs(root->right,level+1,res);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        int level = 0;
        dfs(root,level,ans);
        return ans;
    }
};