// User function Template for C++
#define graph_t vector<vector<int>> 
#define visit_t vector<vector<bool>>
#define un set<vector<pair<int,int>>>
#define bs pair<int,int>
#define vpii vector<pair<int,int>>

class Solution {
  public:
    vector<int> dirx = {0,0,1,-1};
    vector<int> diry = {1,-1,0,0};
    
    bool valid(graph_t& grid, visit_t& visited,int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m && visited[i][j]==false && grid[i][j]==1) {
            return true;
        }
        return false;
    }
    
    void dfs(graph_t& grid, visit_t& visited,vpii& path,bs& base,  int i, int j ) {
       
        int n = grid.size();
        int m = grid[0].size();
       
        path.push_back({i-base.first,j-base.second});
        visited[i][j] = true;
        
        for(int k = 0; k<4; k++) {
            int newi = i+dirx[k];
            int newj = j+diry[k];
            if(valid(grid, visited,newi, newj)) {
                
                dfs(grid,visited, path,base, newi, newj);
            }
        }
        
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m  = grid[0].size();
        
        visit_t visited(n,vector<bool>(m,0));
        set<vector<pair<int,int>>> uniq;
        
        for(int i = 0 ;i<n;i++) {
            for(int j  = 0;j<m;j++) {
                if(grid[i][j]==1 && visited[i][j]==0) {
                    bs base({i,j});
                    vector<pair<int,int>> path;
                    dfs(grid,visited,path,base,i,j);
                   
                    uniq.insert(path);
                }
            }
        }
        return uniq.size();
    }
};
