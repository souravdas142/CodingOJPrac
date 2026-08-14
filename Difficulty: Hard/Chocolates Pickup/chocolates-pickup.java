class Solution {
    
    int[] dy = {1,0,-1};
    
    private int solve1(int[][] grid, int n, int m,int rbx, int rby1, int rby2) {
        
        if(rby1<0 || rby1>=m || rby2<0 || rby2>=m) {
            return Integer.MIN_VALUE;
        }
        
        if(rbx==n-1) {
            if(rby1==rby2) {
                return grid[rbx][rby1];
            }
            
            //System.out.println("rbx:"+rbx+", rby1:"+rby1+", rby2:"+rby2);
            return (grid[rbx][rby1]+grid[rbx][rby2]);
        }
        
        int maxi = Integer.MIN_VALUE;
        
        for(int i = 0;i<3;i++) {
            
            for(int j = 0;j<3;j++) {
                maxi = Math.max(maxi,solve1(grid,n,m,rbx+1,rby1+dy[i],rby2+dy[j]));
            }
        }
        
        
        if(rby1==rby2) {
            return (maxi+grid[rbx][rby1]);
        }
        
        return (maxi+grid[rbx][rby1]+grid[rbx][rby2]);
        
        
    }
    
    
    private int solve2(int[][] grid, int n, int m,int rbx, int rby1, int rby2,int[][][] dp) {
        
        if(rby1<0 || rby1>=m || rby2<0 || rby2>=m) {
            return Integer.MIN_VALUE;
        }
        
        if(rbx==n-1) {
            if(rby1==rby2) {
                return dp[rbx][rby1][rby2] = grid[rbx][rby1];
            }
            
            //System.out.println("rbx:"+rbx+", rby1:"+rby1+", rby2:"+rby2);
            return dp[rbx][rby1][rby2] = (grid[rbx][rby1]+grid[rbx][rby2]);
        }
        
        if(dp[rbx][rby1][rby2]!=0) return dp[rbx][rby1][rby2];
        
        int maxi = Integer.MIN_VALUE;
        
        for(int i = 0;i<3;i++) {
            
            for(int j = 0;j<3;j++) {
                maxi = Math.max(maxi,solve2(grid,n,m,rbx+1,rby1+dy[i],rby2+dy[j],dp));
            }
        }
        
        
        if(rby1==rby2) {
            return dp[rbx][rby1][rby2] = (maxi+grid[rbx][rby1]);
        }
        
        return dp[rbx][rby1][rby2] = (maxi+grid[rbx][rby1]+grid[rbx][rby2]);
        
        
    }
    
    public int maxChocolate(int grid[][]) {
        // code here
        
        int ans = 0;
        int n = grid.length;
        int m = grid[0].length;
        // ans = solve1(grid,n,m,0,0,m-1);
        
        int[][][] dp = new int[n][m][m];
        
        ans = solve2(grid,n,m,0,0,m-1,dp);
        
        return ans;
        
    }
}