
#define vvi vector<vector<char>>
#define vvb vector<vector<bool>>



class Solution {
  private:
    vector<int> dirx = {0,  0,  1,  -1,  1,  -1,  1,  -1};
    vector<int> diry = {1,  -1,  0,  0,  1,  -1,  -1,  1};
                    // UP   d    ryt Lft UR  DL   DR  UL
                    
    bool checkValid(int row, int col, vvi& grid, vvb& visited) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(row>=0 && row<n && col>=0 && col<m && grid[row][col]!='W' && visited[row][col]==false) return true;
        return false;
        
    }
    void dfs(vvi& grid, vvb& visited, int row, int col) {
        
        visited[row][col] = true;
        
        for(int i = 0;i<8;i++) {
            int newRow = row+dirx[i];
            int newCol = col+diry[i];
            if(checkValid(newRow,newCol,grid,visited)) {
                dfs(grid,visited,newRow,newCol);
            }
        }
        
        
        
    }
    
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i  = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]=='W') {
                    visited[i][j] = true;
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i<n;i++) {
            for(int j  = 0;j<m;j++) {
                if(visited[i][j]==false) {
                    ans++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        
        return ans;
        
    }
};