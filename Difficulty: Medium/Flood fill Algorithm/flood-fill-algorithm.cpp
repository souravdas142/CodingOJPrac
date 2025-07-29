#define grid_t vector<vector<int>>
#define visit_t vector<vector<bool>>

class Solution {
  public:
    vector<int> dirx = {0,0,1,-1};
    vector<int> diry = {1,-1,0,0};
    bool checkValid(grid_t& image, int sr, int sc, int color,visit_t& visited) {
        int n = image.size();
        int m = image[0].size();
        if(sr>=0 && sr<n && sc>=0 && sc<m && visited[sr][sc]!=true && image[sr][sc]==color) return true;
        return false;
    }
    void dfs(grid_t& image,int sr, int sc,visit_t& visited,int color, int newColor) {
        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        for(int i  = 0;i<4;i++) {
            int nsr = sr+dirx[i];
            int nsc = sc+diry[i];
            if(checkValid(image,nsr,nsc,color,visited)) {
                dfs(image,nsr,nsc,visited,color,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(grid_t& image, int sr, int sc, int newColor) {
        // Code here
        int color = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        dfs(image,sr,sc,visited,color,newColor);
        return image;
        
    }
};