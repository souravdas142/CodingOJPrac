class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        queue<pair<int,int>> que;
        int V = adj.size();
        que.push({src,0});
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        vector<bool> visited(V,false);
        
        while(!que.empty()) {
            pair<int,int> u = que.front();
            que.pop();
            for(auto v: adj[u.first]) {
                if(u.second+1<dist[v]) {
                    dist[v] = u.second+1;
                    que.push({v,dist[v]});
                }
            }
        }
        
        for(int i = 0;i<V;i++) {
            if(dist[i]==INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
        
    }
};