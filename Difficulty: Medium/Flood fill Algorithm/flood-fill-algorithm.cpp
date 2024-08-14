//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define vvi vector<vector<int> >
class Solution {
private:
    bool check(vvi& image,vvi& visited,int sr,int sc,int newx,int newy,int n,int m) {
        if(newx>=0 && newy >= 0 &&  newx<n && newy<m && image[sr][sc]==image[newx][newy] && visited[newx][newy]==false) return true;
        return false;
    }
    void bfs(vvi& image,vvi& visited,int sr,int sc,int newColor) {
        
        int n = image.size();
        int m = image[0].size();
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        visited[sr][sc] = true;
        deque<pair<int,int> > dq;
        dq.push_back({sr,sc});
        
        while(!dq.empty()) {
            
            pair<int,int> ele = dq.front();
            dq.pop_front();
            for(int i = 0;i<4;i++) {
                int newx = ele.first+dx[i];
                int newy = ele.second+dy[i];
                if(check(image,visited,sr,sc,newx,newy,n,m)) {
                    dq.push_back({newx,newy});
                    image[newx][newy] = newColor;
                    visited[newx][newy] = true;
                }
            }
            
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        vector<vector<int> > visited(n,vector<int>(m,false));
        
        
        bfs(image,visited,sr,sc,newColor);
        
        image[sr][sc] = newColor;
        
             
        
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends