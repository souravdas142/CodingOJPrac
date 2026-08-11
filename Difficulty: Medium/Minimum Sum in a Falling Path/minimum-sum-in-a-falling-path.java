class Solution {
    
    public int solve(int[][] mat, int n, int m, int x, int y) {
        
        if(x>=n) return 0;
        if(y<0 || y>=m) return Integer.MAX_VALUE;
        
        if(x==0) {
            int mini = Integer.MAX_VALUE;
            for(int i = y;i<m;i++) {
                int a = solve(mat,n,m,x+1,i);
                int b = solve(mat,n,m,x+1,i-1);
                int c = solve(mat,n,m,x+1,i+1);
                
                int k = mat[x][i]+Math.min(a,Math.min(b,c));
                mini = Math.min(mini,k);
                
                
                
            }
            return mini;
        }
        
        
        int mini = Integer.MAX_VALUE;
        int a = solve(mat,n,m,x+1,y);
        int b = solve(mat,n,m,x+1,y-1);
        int c = solve(mat,n,m,x+1,y+1);
                
        int k = mat[x][y]+Math.min(a,Math.min(b,c));
        mini = Math.min(mini,k);
        
        return mini;
        
        
    }
    
    public int solve2(int[][] mat, int n, int m, int x, int y,int[][] dp) {
        
        if(x>=n) return 0;
        if(y<0 || y>=m) return Integer.MAX_VALUE;
        
        if(dp[x][y]!=101) return dp[x][y];
        
        if(x==0) {
            int mini = Integer.MAX_VALUE;
            for(int i = y;i<m;i++) {
                int a = solve2(mat,n,m,x+1,i,dp);
                int b = solve2(mat,n,m,x+1,i-1,dp);
                int c = solve2(mat,n,m,x+1,i+1,dp);
                
                int k = mat[x][i]+Math.min(a,Math.min(b,c));
                dp[x][i] = mini = Math.min(mini,k);
                
                
                
            }
            return mini;
        }
        
        
        int mini = Integer.MAX_VALUE;
        int a = solve2(mat,n,m,x+1,y,dp);
        int b = solve2(mat,n,m,x+1,y-1,dp);
        int c = solve2(mat,n,m,x+1,y+1,dp);
                
        int k = mat[x][y]+Math.min(a,Math.min(b,c));
        mini = Math.min(mini,k);
        
        return dp[x][y] = mini;
        
        
    }
    
    public int minFallingPathSum(int[][] mat) {
        // code here
        int n = mat.length;
        int m = mat[0].length;
        int i = 0;
        int j = 0;
        int[][] dp = new int[n][m];
        for(int k = 0;k<n;k++) {
            Arrays.fill(dp[k],101);
        }
        int ans = solve2(mat,n,m,i,j,dp);
        return ans;
    }
}
