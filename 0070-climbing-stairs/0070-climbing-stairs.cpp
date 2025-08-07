class Solution {
public:
    int dpSol(int n, vector<int>& dp) {
        if(n<=1) return 1;

        if(dp[n]!=-1) return dp[n];
        return dp[n] = dpSol(n-1,dp)+dpSol(n-2,dp);
    }


    int tabSol(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i<=n;i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }


    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return dpSol(n,dp);

        //return tabSol(n);
        
    }
};