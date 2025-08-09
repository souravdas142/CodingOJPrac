// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int recurSol(vector<int>& arr, int index,vector<int>& dp) {
        if(index<0) return 0;
        if(dp[index]!=0) return dp[index];
        int left = recurSol(arr, index-2,dp) + arr[index];
        int right = recurSol(arr,index-1,dp);
        return dp[index] = max(left,right);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int index = n-1;
        vector<int> dp(n,0);
        return recurSol(arr,index,dp);
    }
};