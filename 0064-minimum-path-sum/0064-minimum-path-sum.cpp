#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    vi dirx = {0,1};
    vi diry = {1,0};

    int dfs(vvi& grid, int r, int c,vvi& dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(r==n-1 && c==m-1) {
            return grid[r][c];
        }

        int ans = INT_MAX;
        if(dp[r][c]!=-1) return dp[r][c];
        if(c+diry[0]<m) {
            ans = min(ans,grid[r][c]+dfs(grid,r,c+diry[0],dp));

        }
        if(r+dirx[1]<n) {
            ans = min(ans,grid[r][c]+dfs(grid,r+dirx[1],c,dp));
        }
        return dp[r][c] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvi dp(n,vi(m,-1));
        return dfs(grid,0,0,dp);
    }
};