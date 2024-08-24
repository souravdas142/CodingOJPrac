
#define vvb vector<vector<bool> >
#define vb vector<bool>
#define vvi vector<vector<int> >
#define vi vector<int>


class Node {

    public:
        int row;
        int col;
        int dist;

        Node(int x,int y, int d=0): row(x),col(y),dist(d) {}

};

vector<int> dx = {0,0,-1,1};
vector<int> dy = {1,-1,0,0};

bool checkPossible(int m,int n,Node& v,vvb& visited,vvi& grid) {

    int x = v.row;
    int y = v.col;

    if(x>=0 && y>=0 && x<m && y<m && grid[x][y]==1 && !visited[x][y]) return true;
    return false;

}

class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {

        deque<Node> dq;

        int m = grid.size();
        int n = grid[0].size();

        int freshcnt = 0;
        vvb visited(m,vb(n,false));

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j]==2) {
                    dq.push_back(Node(i,j,0));
                    visited[i][j] = true;
                }
                else if(grid[i][j]==1) {
                    freshcnt ++;
                }
            }
        }
        int mx = 0;




        while(!dq.empty()) {
            Node u = dq.front();
            dq.pop_front();

            for(int i = 0;i<4;i++) {
                Node v(u.row+dx[i],u.col+dy[i],u.dist+1);
                

                if(checkPossible(m,n,v,visited,grid)) {
                    freshcnt--;
                    dq.push_back(v);
                    visited[v.row][v.col] = true;
                    mx = max(mx,v.dist);
                }
            }


        }

        if(freshcnt>0) return -1;
        return mx;
        
    }
};