class Solution {
    public int solve(int[][] grid, int x, int y) {

        if(x==0 && y==0) {
            return grid[x][y];
        }

        if(x<0 || y<0) return Integer.MAX_VALUE;

        int up = solve(grid,x-1,y);
        int left = solve(grid,x,y-1);

        return grid[x][y]+Math.min(up,left);
    }

    public int solve2(int[][] grid, int x, int y,int[][] dp) {

        if(x==0 && y==0) {
            return grid[x][y];
        }

        if(x<0 || y<0) return Integer.MAX_VALUE;

        if(dp[x][y]!=0) return dp[x][y];

        int up = solve2(grid,x-1,y,dp);
        int left = solve2(grid,x,y-1,dp);

        return dp[x][y] = grid[x][y]+Math.min(up,left);
    }

    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int x = n-1;
        int y = m-1;

        int ans = 0;
        // ans = solve(grid,x,y);

        int[][] dp = new int[n][m];

        ans = solve2(grid,x,y,dp);
        return ans;
    }
}