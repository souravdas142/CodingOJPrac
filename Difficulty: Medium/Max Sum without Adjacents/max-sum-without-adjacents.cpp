// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int recurSol(vector<int>& nums, int i) {
        if(i<0) return 0;
        int x = nums[i]+recurSol(nums,i-2);
        int y = 0+recurSol(nums,i-1);
        return max(x,y);
        
    }
    int memoSol(vector<int>& nums, int i, vector<int>& dp) {
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int x = nums[i]+memoSol(nums,i-2,dp);
        int y = 0+memoSol(nums,i-1,dp);
        return dp[i] = max(x,y);
        
        
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        // int n = arr.size();
        // int index = n-1;
        // return recurSol(arr,index);
        int n = arr.size();
        vector<int> dp(n+1,-1);
        int index = n-1;
        
        return memoSol(arr,index,dp);
    }
};