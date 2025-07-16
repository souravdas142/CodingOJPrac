// User function Template for C++


#define graph_t vector<vector<char>>
#define visit_t vector<vector<bool>>

class Solution {
  public:
    vector<int> dirx = {0,0,1,-1};
    vector<int> diry = {1,-1,0,0};
    bool valid(int i ,int j, visit_t& visited, graph_t& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(i>=0 && i<n && j>=0 && j<m && mat[i][j]=='O' && visited[i][j] == false)
            return true;
        return false;
    }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        visit_t visited(n,vector<bool>(m,false));
        queue<pair<int,int>> que;
        
        for(int i = 0;i<n;i++) {
            if(mat[i][0]=='O') {
                que.push({i,0});
                visited[i][0] = true;
            }
            if(mat[i][m-1]=='O') {
                que.push({i,n-1});
                visited[i][n-1]= true;
            }
        }
        
        for(int i = 1;i<m-1;i++) {
            if(mat[0][i]=='O') {
                que.push({0,i});
                visited[0][i] = true;
            }
            if(mat[n-1][i]=='O') {
                que.push({n-1,i});
                visited[n-1][i] = true;
            }
        }
        
        while(!que.empty()) {
            pair<int,int> nd = que.front();
            que.pop();
            
            for(int i = 0;i<4;i++) {
                int newi = nd.first+dirx[i];
                int newj = nd.second+diry[i];
                
                if(valid(newi,newj,visited,mat)) {
                    visited[newi][newj] = true;
                    que.push({newi,newj});
                }
            }
            
        }
        
        for(int i = 0 ;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(visited[i][j]==false && mat[i][j]=='O') {
                    mat[i][j] = 'X';
                }
            }
        }
        
        
        return mat;
    }
};