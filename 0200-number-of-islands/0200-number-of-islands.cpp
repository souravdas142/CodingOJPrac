#define vvb vector<vector<bool> >
#define vb vector<bool>
#define vvc vector<vector<char> >

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};



class Solution {

    bool checkPossible(pair<int,int>& cell,vvb& visited, vvc& grid,const int &n) {
        int x = cell.first, y = cell.second;
        if(x>=0 && y>=0 && x<n && y<n && !visited[x][y] && grid[x][y]!='0') return true;
        return false;
    }

    void bfs(pair<int,int>& startCell,vvb& visited, vvc& grid,const int &n) {

        visited[startCell.first][startCell.second] = true;
        deque<pair<int,int> > dq;
        dq.push_back(startCell);

        while(!dq.empty()) {
            pair<int,int> cell = dq.front();
            dq.pop_front();

            for(int i = 0;i<4;i++) {
                pair<int,int> newCell(cell.first+dx[i],cell.second+dy[i]);
                if(checkPossible(newCell,visited,grid,n)) {
                    visited[newCell.first][newCell.second] = true;
                    dq.push_back(newCell);
                }
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        vvb visited(n,vb(n,false));
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(!visited[i][j] && grid[i][j]!='0') {
                    cnt++;
                    pair<int,int> cell(i,j);
                    bfs(cell,visited,grid,n);
                }
            }
        }

        return cnt;
        
    }
};