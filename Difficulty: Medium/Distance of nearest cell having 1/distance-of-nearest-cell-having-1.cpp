
#define graph_t vector<vector<int>>
#define visit_t vector<vector<bool>>

class cell {
    public:
        int i;
        int j;
        int dist;
        cell() {
            i = 0;
            j = 0;
            dist = 0;
        }
        cell(int a, int b, int c=0):i(a),j(b),dist(c) {}
};

class Solution {
  public:
    vector<int> dirx = {0,0,1,-1};
    vector<int> diry = {1,-1,0,0};
    
    bool valid(int i, int j,int n, int m, graph_t& grid,visit_t& visited) {
        if(i>=0 && i<n && j>=0 && j<m && visited[i][j]==false)
            return true;
        return false;
    }

  
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        visit_t visited(n,vector<bool>(m,false));
        graph_t gridAns(n,vector<int>(m,0));
        
     
        
        queue<cell> que;
        
        for(int i = 0;i<n;i++) {
            for(int j  = 0;j<m;j++) {
                if(grid[i][j]==1) {
                    que.push(cell(i,j));
                    visited[i][j] = true;
                }
            }
        }
        
        while(!que.empty()) {
            cell cl = que.front();
            que.pop();
            
            for(int i = 0;i<4;i++) {
                
                cell newCell(cl.i+dirx[i],cl.j+diry[i]);
                
                if(valid(newCell.i,newCell.j,n,m,grid,visited)) {
                   
                    newCell.dist = cl.dist+1;
                    gridAns[newCell.i][newCell.j] = cl.dist+1;
                    
                    visited[newCell.i][newCell.j] = true;
                    que.push(newCell);
                }
            }
            
            
        }
       
        return gridAns;
    }
};