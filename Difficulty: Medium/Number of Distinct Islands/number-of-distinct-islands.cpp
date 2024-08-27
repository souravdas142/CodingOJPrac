//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define vvi vector<vector<int> >
#define vi vector<int>
#define vvb vector<vector<bool> >
#define vb vector<bool>
#define pii pair<int,int>
#define stvpii set<vector<pair<int,int> > >
#define vpii vector<pair<int,int> >

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

class Solution {
  private:
    bool checkPossible(vvi& grid,vvb& visited,int i,int j,int n,int m) {
        if(i>=0 && j>=0 && i<n && j<m && !visited[i][j] && grid[i][j]==1) return true;
        return false;
    }
    
    vpii runBfs(vvi& grid,vvb& visited,int bi,int bj,int n,int m) {
        visited[bi][bj] = true;
        deque<pii> dq;
        dq.push_back({bi,bj});
        vpii ans;
        
        while(!dq.empty()) {
            pii pr = dq.front();
            dq.pop_front();
            
            ans.push_back({pr.first-bi,pr.second-bj});
            
            for(int i = 0;i<4;i++) {
                int nrow = pr.first+dx[i];
                int ncol = pr.second+dy[i];
                if(checkPossible(grid,visited,nrow,ncol,n,m)) {
                    dq.push_back({nrow,ncol});
                    visited[nrow][ncol]=true;
                }
            }
        }
        return ans;
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vvb visited(n,vb(m,false));
        
         stvpii stpath;
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                
                if(!visited[i][j] && grid[i][j]==1) {
                    stpath.insert(runBfs(grid,visited,i,j,n,m));
                }
                
            }
        }
        
        int ans = stpath.size();
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends