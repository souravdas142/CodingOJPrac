
#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:

    int recurSol(vvi& grid, int n, int m) {
    
        if(n==0 && m==0) return grid[n][m];

        int x = INT_MAX;
        int y = INT_MAX;

        if(n-1>=0)
            x = grid[n][m] + recurSol(grid,n-1,m);
        if(m-1>=0)
            y = grid[n][m] + recurSol(grid,n,m-1);

        return min(x,y);

    }
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        return recurSol(grid, n-1, m-1);
        
    }
};