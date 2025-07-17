
#define graph_t vector<vector<int>>
#define visit_t vector<pair<bool,int>>



class Solution {
  public:
    bool dfs(graph_t& adj,visit_t& visited, pair<int,int> parent) {
        visited[parent.first].first = true;
        visited[parent.first].second = parent.second;
        
        for(auto& e: adj[parent.first]) {
            if(!visited[e].first) {
                pair<int,int> child({e,parent.second^1});
                if(dfs(adj,visited,child)==false) return false;
            }
            else if(visited[e].second==parent.second) {
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        graph_t adj(V);
        visit_t visited(V,pair<bool,int>({0,-1}));
        
        int n = edges.size();
        for(int i =0;i<n;i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i = 0;i<V;i++) {
            if(!visited[i].first) {
                pair<int,int> parent({i,0});
                if(dfs(adj,visited,parent)==false) return false;
            }
        }
        
        return true;
    }
};