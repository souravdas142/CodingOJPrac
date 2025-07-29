#define graph_t vector<vector<int>>

class Solution {
  public:
    bool dfs(graph_t& adj, int u, vector<int>& visited) {
        visited[u] = 1;
        for(auto& v: adj[u]) {
            if(!visited[v]) {
                if(dfs(adj,v,visited)==false) return false;;
            }
            else if(visited[v]==1) {
                return false;
            }
        }
        visited[u] = 2;
        return true;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        graph_t adj(V);
        for(auto& vec: edges) {
            adj[vec[0]].push_back(vec[1]);
        }
        
        vector<int> visited(V,false);
        for(int i  = 0;i<V;i++) {
            if(!visited[i]) {
                if(dfs(adj,i,visited)==false) return true;
            }
            
        }
        return false;
        
    }
};