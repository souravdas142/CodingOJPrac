#define vvc vector<vector<char> >
#define vvb vector<vector<bool> >
#define vb vector<bool>
#define vi vector<char>

class Node {
public:
    int row;
    int col;
    int dist;
    
    Node(int r,int c,int d):row(r),col(c),dist(d) {};
    
    
};

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};


class Solution {
private:
void dfs(vvc& grid,vvb& visited, int i,int j,int m,int n) {

    visited[i][j] = true;
    grid[i][j]='C';

    for(int k = 0;k<4;k++) {
        int nrow = i+dx[k];
        int ncol = j+dy[k];

        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]=='O' && !visited[nrow][ncol]) {
            dfs(grid,visited,nrow,ncol,m,n);
        }
    }

}
public:
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vvb visited(m,vb(n,0));

        for(int i =0;i<m;i++) { // up to down
            
            if(board[i][0]=='O' && !visited[i][0]) { // left
                dfs(board,visited,i,0,m,n);
            }
            if(board[i][n-1]=='O' && !visited[i][n-1]) { //right
                dfs(board,visited,i,n-1,m,n);
            }
            


        }

        for(int i = 0;i<n;i++) { // left to right

            if(board[0][i]=='O' && !visited[0][i]) { //top
                dfs(board,visited,0,i,m,n);
            }

            if(board[m-1][i]=='O' && !visited[m-1][i]) { //bottom
                dfs(board,visited,m-1,i,m,n);
            }


        }

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(board[i][j] == 'C') {
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O') {
                    board[i][j] = 'X';
                    
                }
            }
        }
        
    }
};