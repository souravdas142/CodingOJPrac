#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define node pair<pair<int,int>,int>
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    
    vector<int> dirx = {0,0,1,-1};
    vector<int> diry = {1,-1,0,0};
    bool check(node& child,vvi& grid, int n, int m,vvb& visited) {
        int x = child.first.first;
        int y = child.first.second;
        if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==false && grid[x][y]==0) return true;
        return false;
    }
    void bfs(vvi& grid, int n, int m, queue<node>& que,vvi& dist, vvb& visited) {
        
        
        
        
        while(!que.empty()) {
            pair<pair<int,int>,int> parent = que.front();
            que.pop();
            for(int i  = 0;i<4;i++) {
                pair<pair<int,int>,int> child({{parent.first.first+dirx[i],parent.first.second+diry[i]},parent.second+1});
                if(check(child,grid,n,m,visited)) {
                    
                    que.push(child);
                    dist[child.first.first][child.first.second] = child.second;
                    visited[child.first.first][child.first.second] = true;
                }
            }
        }
        
    }
    
    vvi nearest(vvi& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vvi dist(n,vector<int>(m,0));
        vvb visited(n,vector<bool>(m,false));
        queue<node> que;
        
        for(int i  = 0;i<n;i++) {
            for(int j  = 0;j<m;j++) {
                if(grid[i][j]==1) {
                    que.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        
        bfs(grid,n,m, que, dist,visited);
        
        return dist;
        
    }
};