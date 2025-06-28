/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
    int dfs(Node* root,int& k,int node,int level,int& backLevel,int& ans) {
        if(root==nullptr) return -1;
        if(root->data == node ) {
            //k=k-1;
            //backLevel++;
            return level;
        }
        int left = dfs(root->left,k,node,level+1, backLevel,ans);
        if(left!=-1) {
            backLevel++;
            if(backLevel==k) {
                ans = root->data;
            }
            return left;
        }
        int right = dfs(root->right,k,node,level+1,backLevel,ans);
          if(right!=-1) {
            backLevel++;
            if(backLevel==k) {
                ans = root->data;
            }
            return right;
        }
        return right;
        
    }
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        int level = 0;
        int ans = -1;
        int backLevel = 0;
        dfs(root,k,node,level,backLevel ,ans);
        return ans;
    }
};
