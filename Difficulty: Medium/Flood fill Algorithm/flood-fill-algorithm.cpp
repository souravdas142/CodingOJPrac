#define graph_t vector<vector<int>> 
#define visit_t vector<vector<bool>>

class Solution {
  public:
  
    vector<int> dirx = {0, 0, 1, -1};
    vector<int> diry = {1, -1, 0, 0};
    
    bool checkPos(graph_t& graph, visit_t& visited, int sr, int sc) {
        int n = graph.size();
        int m = graph[0].size();
        if(sr>=0 && sr<n && sc>=0 && sc<m && visited[sr][sc]==false) return true;
        return false;
    }
  
    void dfs(graph_t& image,visit_t& visited, int sr, int sc, int color,int newColor) {
        
        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        
        for(int i = 0;i<4;i++) {
            if(checkPos(image,visited,sr+dirx[i],sc+diry[i])) {
                dfs(image,visited,sr+dirx[i],sc+diry[i],color,newColor);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size();
        int m = image[0].size();
    
        visit_t visited(n,vector<bool>(m,false));
        
        int color = image[sr][sc];
        
        for(int i =0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(image[i][j]!=color) {
                    visited[i][j] = true;
                }
            }
        }
        
        dfs(image,visited,sr,sc,color,newColor);
        
        return image;
    
        
        
    }
};