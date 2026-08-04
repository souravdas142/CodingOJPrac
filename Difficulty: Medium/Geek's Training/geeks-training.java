class Solution {

    public int solve(int[][] mat, int n, int m, int indexDay,int indexTask) {
        if(indexDay<0) return 0;
        
        int ans =Integer.MIN_VALUE;
        
        for(int i = 0;i<m;i++) {
            if(i==indexTask) continue;
            int x = solve(mat,n,m,indexDay-1,i) + mat[indexDay][i];
            ans = Math.max(ans,x);
        }
        
        return ans;
    }
    
    public int solve2(int[][] mat, int indexDay,int indexTask,int[][] dp) {
        if(indexDay<0) return 0;
        
        if(dp[indexDay][indexTask]!=-1) return dp[indexDay][indexTask];
        
        int ans =Integer.MIN_VALUE;
        
        for(int i = 0;i<3;i++) {
            if(i==indexTask) continue;
            int x = mat[indexDay][i] + solve2(mat,indexDay-1,i,dp);
            ans = Math.max(ans,x);
        }
        
        dp[indexDay][indexTask] = ans;
        
        return ans;
    }
    
    public int maximumPoints(int mat[][]) {
        // code here
        int n = mat.length;
        int m = mat[0].length;
        
        int indexDay = n-1;
        int indexTask = 3;
        
        // int ans = solve(mat,n,m,indexDay,indexTask);
        
        int[][] dp = new int[n][m+1];
        
        for(int i= 0;i<n;i++) {
            Arrays.fill(dp[i],-1);
        }
        
        int ans = solve2(mat,indexDay,indexTask,dp);
        
        return ans;
    }
}