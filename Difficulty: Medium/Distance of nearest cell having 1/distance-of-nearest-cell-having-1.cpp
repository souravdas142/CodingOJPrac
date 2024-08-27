//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define vvi vector<vector<int> >
#define vvb vector<vector<bool> >
#define vb vector<bool>
#define vi vector<int>

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
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vvi ans(n,vi(m,0));
        vvb visited(n,vb(m,0));
        
        deque<Node> dq;
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1) {
                    dq.push_back(Node(i,j,0));
                    visited[i][j] = true;
                }   
            }
        }
        
        
        while(!dq.empty()) {
            
            Node nd = dq.front();
            dq.pop_front();
            
            ans[nd.row][nd.col] = nd.dist;
            
            for(int i = 0;i<4;i++) {
                Node newNode(nd.row+dx[i],nd.col+dy[i],nd.dist+1);
                if(newNode.row>=0 && newNode.col>=0 && newNode.row<n && newNode.col<m && !visited[newNode.row][newNode.col]) {
                    ans[newNode.row][newNode.col] = newNode.dist;
                    visited[newNode.row][newNode.col] = true;
                    dq.push_back(newNode);
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
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends