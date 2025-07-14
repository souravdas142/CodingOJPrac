#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
class Node {
    public:
        int row;
        int col;
        int dist;
        Node(int r, int c, int d):row(r),col(c),dist(d){}
};

class Solution {
private:
    vector<int> dirx = {0,0,1,-1};
    vector<int> diry = {1,-1,0,0};
    bool checkPos(Node& newNode,vvi& grid, vvb& visited) {
        int n = grid.size();
        int m = grid[0].size();
        int row = newNode.row;
        int col = newNode.col;

        if(row>= 0 && row<n && col>=0 && col<m && visited[row][col]==false && grid[row][col]==1) return true;
        return false;

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Node> que; // 0-row, 1-col, 2-dist 
        int n  = grid.size();
        int m  = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i  = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]==2) {
                    que.push({i,j,0});
                    
                }
                if(grid[i][j]==0 || grid[i][j]==2) {
                    visited[i][j] = true;
                }
            }
        }

        
        int ans = 0;
        while(!que.empty()) {
            Node parent = que.front();
            que.pop();
            ans = max(ans,parent.dist);


            for(int i  = 0;i<4;i++) {
                Node newNode(parent.row+dirx[i],parent.col+diry[i],parent.dist+1);
                if(checkPos(newNode,grid,visited)) {
                    visited[newNode.row][newNode.col] = true;
                    que.push(newNode);
                }
            }

        }


        for(int i = 0;i<n;i++) {
            for(int j  = 0;j<m;j++) {
                if(visited[i][j]==false) return -1;
            }
        }

        return ans;

    }
};