
#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
  public:
    vi dirx = {0,1};
    vi diry = {1,0};
    int recurSolve(vvi& grid, int r, int c,vvi& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(r == n-1 && c == m-1) {
            return 1;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int ans = 0;
        for(int i  = 0;i<2;i++) {
            int newx = r+dirx[i];
            int newy = c+diry[i];
            if(newx<n && newy<m && grid[newx][newy]!=1) {
                ans += recurSolve(grid,newx,newy,dp);
            }
            
        }
        return dp[r][c] = ans;
    }
    int recurSol(vvi& grid) {
        if(grid[0][0]==1) return 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vvi dp(n,vi(m,-1));
        return recurSolve(grid,0,0,dp);
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        return recurSol(grid);
    }
};