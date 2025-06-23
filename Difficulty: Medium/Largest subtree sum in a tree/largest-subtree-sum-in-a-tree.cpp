// User function Template for C++

class Solution {
  public:
    // Function to find largest subtree sum.
    int dfs(Node* root, int& ans) {
        if(root==nullptr) return 0;
        int left = dfs(root->left,ans);
        int right = dfs(root->right,ans);
        
        int temp = root->data;
        root->data = left+right+temp;
        ans = max(ans,root->data);
        return root->data;
    }
    int findLargestSubtreeSum(Node* root) {
        // Write your code here
        int ans = INT_MIN;
        dfs(root,ans);
        return ans;
    }
};
