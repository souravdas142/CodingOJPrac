
#define ppii pair<int,pair<int,int>>
#define vvi vector<vector<int>>

class Solution {
public:
    bool valid(ppii& v, vvi& grid, int n,vvi& dist) {
        int x = v.second.first;
        int y = v.second.second;
        int distv = v.first;
        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0 && distv<dist[x][y]) return true;
        return false;
    }
    vector<int> dirx = {0,0,1,-1,1,1,-1,-1};
    vector<int> diry = {1,-1,0,0,1,-1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<ppii,vector<ppii>, greater<ppii>> pq;
        int sr = 0, sc = 0;
        int dr = n-1, dc = n-1;
        if(grid[sr][sc]==1 || grid[dr][dc]==1) return -1;
        pq.push({0,{sr,sc}});
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[sr][sc] = 0;

        while(!pq.empty()) {
            ppii u = pq.top();
            pq.pop();
            if(u.second.first == dr && u.second.second == dc) break;
            for(int i = 0;i<8;i++) {
                ppii v({u.first+1,{u.second.first+dirx[i],u.second.second+diry[i]}});
                if(valid(v,grid,n,dist)) {
                    pq.push(v);
                    dist[v.second.first][v.second.second] = v.first;
                }
            }
        }
        
        return (dist[dr][dc]==INT_MAX)?-1:dist[dr][dc]+1;
    }
};