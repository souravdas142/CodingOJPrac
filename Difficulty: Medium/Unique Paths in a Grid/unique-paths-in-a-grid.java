class Solution {
    public int solve(int n, int m, int[][] grid) {
        if(n>=0 && m>=0 && grid[n][m]==1) return 0;
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        
        
        int up = solve(n-1,m,grid);
        int left = solve(n,m-1,grid);
        
        return (up+left);
        
        
    }
    
    public int solve2(int n, int m, int[][] grid, int[][] dp) {
        
        if(n>=0 && m>=0 && dp[n][m]!=-1) return dp[n][m];
        
        if(n>=0 && m>=0 && grid[n][m]==1) {
            dp[n][m] = 0;
            return 0;
        }
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        
        
        
        int up = solve2(n-1,m,grid,dp);
        int left = solve2(n,m-1,grid,dp);
        
        return dp[n][m] = (up+left);
        
    }
    
    public int uniquePaths(int[][] grid) {
        // code here
        int n = grid.length;
        int m  = grid[0].length;
        
        int ans = 0;
        
        int[][] dp = new int[n][m];
        
        for(int i =0;i<n;i++) Arrays.fill(dp[i],-1);
        
        ans = solve2(n-1,m-1,grid,dp);
        
        return ans;
    }
};