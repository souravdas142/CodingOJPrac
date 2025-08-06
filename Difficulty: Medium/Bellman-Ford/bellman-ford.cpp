// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int n = edges.size();
        vector<int> dist(V,1e8);
        dist[src] = 0;
        
        for(int i = 0;i<n;i++) {
            for(auto& vec: edges) {
                if(dist[vec[0]]==1e8) continue;
                if(dist[vec[0]]+vec[2] < dist[vec[1]]) {
                    dist[vec[1]] = dist[vec[0]] + vec[2];
                }
            }
        }
        
        
        
        for(auto& vec: edges) {
            if(dist[vec[0]]==1e8) continue;
            if(dist[vec[0]]+vec[2] < dist[vec[1]]) {
                dist[vec[1]] = dist[vec[0]] + vec[2];
                return {-1};
            }
        }
        
        return dist;
        
        
    }
};
