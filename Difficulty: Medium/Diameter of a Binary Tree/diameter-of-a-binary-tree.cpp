/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int dfs(Node* root, int &ans) {
        if(!root) return 0;
        int left = max(0,dfs(root->left,ans));
        int right = max(0,dfs(root->right,ans));
        ans = max(ans,right+left);
        
        return 1+max(left,right);
        
    }
    int diameter(Node* root) {
        // Your code here
        int ans = 0;
         dfs(root,ans);
         return ans;
    }
};