#define vvi vector<vector<int> >
#define vi vector<int>
#define vs vector<string>
#define vvb vector<vector<bool> >
#define vb vector<bool>

vector<int> dirx = {0,  0,   1,   -1};
vector<int> diry = {1,  -1,  0,    0};
vector<char> dir = {'R','L','D','U'};
                //  up down right left

class Solution {
  public:
  
    bool isValidPos(int x,int y, vvi& maze,vvb& visited) {
        
        int row = maze.size();
        int col = maze[0].size();
        
        if(x>=0 && x<row && y>= 0 && y<col && maze[x][y]==1 && visited[x][y] == 1) return true;
        return false;
        
    }
  
    void solve(vvi& maze, vs& ans, string res, int x, int y,vvb& visited) {
        
        int row = maze.size();
        int col = maze[0].size();
        if(x==row-1 && y==col-1) {
            ans.push_back(res);
            return;
        }
        
        
        
        for(int i = 0;i<dirx.size();i++) {
            int nextPosx = x+dirx[i];
            int nextPosy = y+diry[i];
            if(isValidPos(nextPosx,nextPosy,maze,visited)) {
                res.push_back(dir[i]);
                visited[x][y] = 0;
                solve(maze,ans,res,nextPosx,nextPosy,visited);
                res.pop_back();
                visited[x][y] = 1;
            }
        }
        
        
    }
  
    vector<string> ratInMaze(vvi& maze) {
        // code here
        
        if(maze[0][0]==0) return {""};
        int x = 0, y = 0;
        int row = maze.size();
        int col = maze[0].size();
        
        
        vvb visited(row,vb(col,0));
        
        for(int i = 0;i<row;i++) {
            for(int j = 0;j<col;j++) {
                visited[i][j] = maze[i][j];
            }
        }
        
        //vvb visited = maze;
        
        vs ans;
        string res = "";
        
        solve(maze,ans,res,x,y,visited);
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};