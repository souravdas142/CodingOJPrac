    int dx[] = {0, 0,1,-1,-1, 1,-1,1};
    int dy[]=  {1,-1,0, 0, 1,-1,-1,1};

class Solution {
private:
    bool checkValidity(vector<vector<int> >& grid,int x,int y, int n) {
        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0) return true;
        return false;
    }
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int>> >, greater<pair<int,pair<int,int> > > > pq;

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        vector<vector<int> > dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = 0;
        pq.push({1,{0,0}});

        while(!pq.empty()) {
            pair<int,pair<int,int> > unodepr = pq.top();
            pq.pop();

            int distu = unodepr.first;
            pair<int,int> cell = unodepr.second;
            for(int i =0;i<8;i++) {
                int newCellx = cell.first+dx[i];
                int newCelly = cell.second+dy[i];
                if(checkValidity(grid,newCellx,newCelly,n)) {
                    if(distu+1<dist[newCellx][newCelly]) {
                        dist[newCellx][newCelly] = distu+1;
                        pq.push({distu+1,{newCellx,newCelly}});
                    }
                }
            }
        }

        return dist[n-1][n-1];
        
    }
};