//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
  
    bool check(vector<vector<char>> &grid,vector<vector<bool>>& visited,int n,int m,int i, int j) {
        if(i<n && j<m && i>=0 && j>=0 && grid[i][j]=='1' && visited[i][j]==false) return true;
        return false;
    }
    
    void bfs(vector<vector<char>> &grid, vector<vector<bool>>& visited, int n, int m, int i, int j) {
        
        deque<pair<int,int>> dq;
        vector<int> dx = {1,0,-1,1,1,-1,-1,0};
        vector<int> dy = {0,1,0,-1,1,-1,1,-1};
        dq.push_back({i,j});
        visited[i][j]=true;
        
        while(!dq.empty()) {
            pair<int,int> prxy = dq.front();
            dq.pop_front();
            
            for(int k = 0;k<8;k++) {
                int newi = prxy.first+dx[k];
                int newj = prxy.second+dy[k];
                if(check(grid,visited,n,m,newi,newj)) {
                    dq.push_back({newi,newj});
                    visited[newi][newj] = true;
                }
            }
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        int ans = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    ans++;
                    bfs(grid,visited,n,m,i,j);
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends