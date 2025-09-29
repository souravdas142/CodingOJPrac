class Solution {
  public:
    int recurSol(int m, int n) {
        
        if(m<0 || n<0) return 0;
        
        if(m==0 && n==0) return 1;
        
        
        int x = recurSol(m-1,n);
        int y = recurSol(m,n-1);
        return x+y;
    }
    int memoSol(int m, int n,vector<vector<int>>& dp) {
        
        
        if(m<0 || n<0) return 0;
        
        if(m==0 && n==0) return dp[m][n]=1;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        
        int x = memoSol(m-1,n,dp);
        int y = memoSol(m,n-1,dp);
        return dp[m][n] = x+y;
    }
    int numberOfPaths(int m, int n) {
        // Code Here
        // return recurSol(m-1,n-1);
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = 1;
        return memoSol(m-1,n-1,dp);
    }
};
