class Solution {
public:
    int  countWays(int n,vector<int>& dp) {
        if(n<=1) return 1;
        if(dp[n]!=0) return dp[n];
        dp[n] = countWays(n-1,dp)+countWays(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        int ans = countWays(n,dp);
        return ans;
    }
};