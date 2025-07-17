
#define graph_t vector<vector<int>>
#define visit_t vector<bool>

class Solution {
  public:
    
    bool dfs(graph_t& adj, visit_t visited, int u, int parent) {
        visited[u] = true;
        
        for(auto& v: adj[u]) {
            if(!visited[v]) {
                
                if(dfs(adj, visited, v, u)==true) return true;
            }
            else {
                return true;
            }
        }
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        visit_t visited(V,0);
        graph_t adj(V);
        
        int n = edges.size();
        for(int i = 0 ;i<n;i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i = 0;i<V;i++) {
            if(!visited[i]) {
                int parent = i;
                if(dfs(adj,visited,i,parent)==true) return true;
            }
        }
        return false;
    }
};