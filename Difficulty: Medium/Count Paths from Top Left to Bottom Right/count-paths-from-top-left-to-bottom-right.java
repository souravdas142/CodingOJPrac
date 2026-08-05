class Solution {
    
    private int solve(int m, int n) {
       
        
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return 1;
        int up = solve(m-1,n);
        int left = solve(m,n-1);
        
        return (left+up);
    }
    
    private int solve2(int m, int n,int[][] dp) {
       
        
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return 1;
        
        if(dp[m][n]!=0) return dp[m][n];
        
        int up = solve2(m-1,n,dp);
        int left = solve2(m,n-1,dp);
        
        return dp[m][n] = (left+up);
    }
    
    public int numberOfPaths(int m, int n) {
        // code here
        
        
        int[][] dp = new int[m][n];
        // return solve(m-1,n-1);
        
        return solve2(m-1,n-1,dp);
        
        
        
        
    }
}