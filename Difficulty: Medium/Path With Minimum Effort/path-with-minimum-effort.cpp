
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>
#define ppi pair<int,pi>


class Solution {
  public:
    vi dirx = {0,0,1,-1};
    vi diry = {1,-1,0,0};
    bool valid(ppi& v, int row, int col) {
        int x = v.second.first;
        int y = v.second.second;
        if(x>=0 && x<row && y>=0 && y<col) return true;
        return false;
    }
    int MinimumEffort(int rows, int cols, vvi &heights) {
        // code here
        int sr = 0, sc = 0;
        int dr = rows - 1, dc = cols - 1;
        priority_queue<ppi,vector<ppi>, greater<ppi>> pq;
        
        vvi dist(rows,vi(cols,INT_MAX));
        dist[sr][sc] = 0;
        pq.push({0,{sr,sc}});
        
        while(!pq.empty()) {
            ppi u = pq.top();
            pq.pop();
            if(u.second.first == dr && u.second.second == dc) break;
            
            for(int i  = 0;i<4;i++) {
                ppi v({0,{u.second.first+dirx[i],u.second.second+diry[i]}});
                if(valid(v,rows,cols)) {
                    v.first = max(u.first,abs(heights[u.second.first][u.second.second]-heights[v.second.first][v.second.second]));
                    if(v.first<dist[v.second.first][v.second.second]) {
                        dist[v.second.first][v.second.second] = v.first;
                        pq.push({v.first,{v.second.first,v.second.second}});
                    }
                }
            }
            
         
        }
        return dist[dr][dc];
        
    }
};
