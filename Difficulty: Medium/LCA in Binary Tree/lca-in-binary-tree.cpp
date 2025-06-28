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
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* dfs(Node* root,int n1, int n2) {
        if(root==nullptr) return nullptr;
        if(root->data == n1 || root->data==n2) return root;
        Node* left = dfs(root->left,n1,n2);
        Node* right = dfs(root->right,n1,n2);
        
        if(left!=nullptr && right!=nullptr) return root;
        if(left==nullptr) return right;
        return left;
        
    }
    Node* lca(Node* root, int n1, int n2) {
        // Your code here
        return dfs(root,n1,n2);
        
    }
};