//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define vvi vector<vector<int> >
#define vvi vector<vector<int> >

class Node {
    public:
        int x;
        int y;
        int dist;
        Node(int xa,int ya,int da):x(xa),y(ya),dist(da) {}
    
};

class Solution {


private:
    bool check(vvi& grid,vvi& visited,int i, int j,int n,int m) {
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1 && visited[i][j]!=2) return true;
        return false;
    }


public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx = {1,0,0,-1};
        vector<int> dy = {0,1,-1,0};
        int n = grid.size();
        int m = grid[0].size();
        vvi visited(n,vector<int>(m,0));
        int ans = 0;
        
        int totalCells = n*m;
        deque<Node> dq;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]==2) {
                    dq.push_back(Node({i,j,0}));
                    visited[i][j] = 2;
                    
                    
                }
                if(grid[i][j]==0) totalCells--;
            }
        }
      
        while(!dq.empty()) {
            Node nd = dq.front();
            dq.pop_front();
            bool flag = false;
            totalCells--;
            ans = max(ans,nd.dist);
            for(int k = 0;k<4;k++) {
                int newx = nd.x+dx[k];
                int newy = nd.y+dy[k];
                if(check(grid,visited,newx,newy,n,m)) {
                    visited[newx][newy] = 2;
                    dq.push_back(Node({newx,newy,nd.dist+1}));
                    
                    flag = true;
                }
            }
           
        }

        
       
        if(totalCells==0)
            return ans;
        
        return -1;
        
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends