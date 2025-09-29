class Solution {
  public:
    int recurSol(vector<vector<int>>& grid, int m, int n) {
        
        if(m<0 || n<0 || grid[m][n]==1) return 0;
        if(m==0 && n==0) return 1;
        int x = recurSol(grid,m-1,n);
        int y = recurSol(grid,m,n-1);
        return x+y;
    }
    int memoSol(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        if(m<0 || n<0 || grid[m][n]==1) return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(m==0 && n==0) return dp[m][n] = 1;
        
        
        
        int x = memoSol(grid,m-1,n,dp);
        int y = memoSol(grid,m,n-1,dp);
        return dp[m][n] = x+y;
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        // return recurSol(grid,m-1,n-1);
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return memoSol(grid,m-1,n-1,dp);

    }
};