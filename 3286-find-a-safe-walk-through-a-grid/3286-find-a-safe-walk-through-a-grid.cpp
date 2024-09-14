int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
    
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool> > visited(n,vector<bool>(m,false));

        queue<pair<pair<int,int>,int> > que;
        if(grid[0][0]==1) health-=1;

        que.push({{0,0},health});
        visited[0][0] = true;

        while(!que.empty()) {
            pair<pair<int,int>,int> prnode = que.front();
            que.pop();

            int h = prnode.second;
            int x = prnode.first.first;
            int y = prnode.first.second;

            if(x==n-1 && y==m-1 && h>0) return true;

            for(int i = 0;i<4;i++) {
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx >=0 && newy>=0 && newx<n && newy<m && h>0 && !visited[newx][newy]) {
                    if(grid[newx][newy]==1 && h>1) {
                        visited[newx][newy] = true;
                        que.push({{newx,newy},h-1});
                    }
                    else if(grid[newx][newy]==0 && h>0) {

                        visited[newx][newy] = true;
                        que.push({{newx,newy},h});

                    }
                }
            }
        }

        return false;
        
    }
};