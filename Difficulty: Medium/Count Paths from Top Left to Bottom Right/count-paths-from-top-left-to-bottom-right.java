class Solution {
    public int solve(int m, int n, int[][] dp) {
        if(m<0 || n<0) return 0;
        
        if(m==0 && n== 0) return 1;
        
        if(dp[m][n]!=0) return dp[m][n];
        
        int left = solve(m-1,n,dp);
        int right = solve(m,n-1,dp);
        
        return dp[m][n] = left+right;
    }

    
    public int numberOfPaths(int m, int n) {
        // code here
        
        int ans = 0;
        int[][] dp = new int[m][n];
        ans = solve(m-1,n-1,dp);
        
       
        return ans;
        
    }
}