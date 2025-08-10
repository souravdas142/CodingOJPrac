class Solution {
  public:
    int solve(vector<int>& arr,int k, int index,vector<int>& dp) {
        
        
        if(index<k) return 0;
        if(dp[index]!=-1) return dp[index];
        int left = solve(arr,k, index-2,dp)+arr[index];
        int right = solve(arr,k,index-1,dp);
        return dp[index] = max(left,right);
        
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        vector<int> dp(n,-1),dp2(n,-1);
        
        int left = solve(arr,0,n-2,dp);
        int right = solve(arr,1,n-1,dp2);
        return max(left,right);
    }
};
