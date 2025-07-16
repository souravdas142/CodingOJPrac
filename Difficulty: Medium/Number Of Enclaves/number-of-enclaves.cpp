// User function Template for C++

#define graph_t vector<vector<int>> 
#define visit_t vector<vector<bool>>

class Solution {
  public:
    vector<int> dirx = {0,0,1,-1};
    vector<int> diry = {1,-1,0,0};
    bool valid(int i ,int j, int n, int m, graph_t& mat, visit_t& visited) {
        if(i>= 0 && i<n && j>=0 && j<m && visited[i][j]==false && mat[i][j]==1)
            return true;
        return false;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        visit_t visited(n,vector<bool>(m,false));
        queue<pair<int,int>> que;
        
        for(int i = 0;i<n;i++) {
            if(grid[i][0]==1) {
                que.push({i,0});
                visited[i][0] = true;
            }
            if(grid[i][m-1]==1) {
                que.push({i,m-1});
                visited[i][m-1] = true;
            }
        }
        
        for(int j  = 1;j<m-1;j++) {
            if(grid[0][j]==1) {
                que.push({0,j});
                visited[0][j] = true;
                
            }
            if(grid[n-1][j]==1) {
                que.push({n-1,j});
                visited[n-1][j] =true;
            }
        }
        
        while(!que.empty()) {
            pair<int,int> pr = que.front();
            que.pop();
            for(int i = 0;i<4;i++) {
                int newi = pr.first+dirx[i];
                int newj = pr.second+diry[i];
                if(valid(newi,newj,n,m,grid,visited)) {
                    que.push({newi,newj});
                    visited[newi][newj] = true;
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(visited[i][j]==false && grid[i][j]==1) {
                    ans+=1;
                }
            }
        }
        
        return ans;
        
    }
};
