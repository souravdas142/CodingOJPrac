// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto& vec: edges) {
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        
    
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        
        pq.push({0,src});
        
        while(!pq.empty()) {
            pair<int,int> u = pq.top();
            pq.pop();
            for(auto& v: adj[u.second]) {
                if(dist[u.second]+v.second<dist[v.first]) {
                    dist[v.first] = dist[u.second]+v.second;
                    pq.push({dist[v.first],v.first});
                }
               
            }
        }
        return dist;
    }
};