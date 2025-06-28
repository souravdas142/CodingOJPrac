/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* findLca(Node* root,int a,int b) {
        if(root==nullptr) return nullptr;
        if(root->data == a || root->data == b) return root;
        Node* left = findLca(root->left,a,b);
        Node* right = findLca(root->right,a,b);
        
        if(left!=nullptr && right!=nullptr) return root;
        if(left==nullptr) return right;
        return left;
    }
    
    int findMinDistance(Node* root, int a,int level) {
        if(root==nullptr) return 0;
        if(root->data == a ) {
            return level;
        }
        
        int left = findMinDistance(root->left,a,level+1);
        int right = findMinDistance(root->right,a,level+1);
        return max(left,right);
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lca = findLca(root,a,b);
        int level = 0;
        int as = findMinDistance(lca,a,level);
        int bs = findMinDistance(lca,b,level);
        return abs(as+bs);
    }
};