/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    pair<int,int> dfs(Node* root,int &ans) {
        
        if(root==nullptr) return {0,0};
        
        pair<int,int> left = dfs(root->left,ans);
        pair<int,int> right = dfs(root->right,ans);
        
        
        // first represent height
        // second represent sum
        
        int maxSumFoundSoFar = 0;
        if(left.first>right.first) {
            maxSumFoundSoFar = left.second;
        }
        else if(right.first>left.first) {
            maxSumFoundSoFar = right.second;
        }
        else {
            maxSumFoundSoFar = max(left.second,right.second);
        }
        
        ans = max(ans,maxSumFoundSoFar+root->data);
        
        
        return {1+max(left.first,right.first),maxSumFoundSoFar+root->data};
        
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int ans = 0;
        pair<int,int> ans2 = dfs(root,ans);
        return ans2.second;
    }
};