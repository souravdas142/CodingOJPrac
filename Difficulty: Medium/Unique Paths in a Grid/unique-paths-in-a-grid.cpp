
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
    int tabulation(vvi& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvi dp(n,vi(m,0));
        if(grid[0][0]==1) return 0;
        dp[0][0] = 1;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(i == 0 && j==0) continue;
                if(grid[i][j]==1) continue;
                int left = (i-1>=0 && grid[i-1][j]!=1)?dp[i-1][j]:0;
                int right = (j-1>=0 && grid[i][j-1]!=1)?dp[i][j-1]:0;
                dp[i][j] = left+right;
            }
        }
        return dp[n-1][m-1];
    }
    int spaceOpt(vvi& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1) return 0;
        vi dp(m,1);
        int way = 1;
        for(int i = 0;i<m;i++) {
            if(grid[0][i]==1) way = 0;
            dp[i] = way;
        }
        
        for(int i =1;i<n;i++) {
            int prev = 0;
            vi temp(m,0);
            for(int j = 0;j<m;j++) {
                if(grid[i][j]==1) {
                    int cur = 0;
                    temp[j] = cur;
                    prev = cur;
                    continue;
                }
                int cur = 0;
                if(dp[j]==0 && j>0 && prev==0) cur = 0;
                else if(dp[j]==0 && !(j>0 && prev==0)) cur = prev;
                else if(dp[j]!=0 && (j>0 && prev==0)) cur = dp[j];
                else cur = prev+dp[j];
                prev = cur;
                temp[j] = cur;
            }
            dp = temp;
        }
        return dp[m-1];
        
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        //return recurSol(grid);
        //return tabulation(grid);
        return spaceOpt(grid);
        
    }
};