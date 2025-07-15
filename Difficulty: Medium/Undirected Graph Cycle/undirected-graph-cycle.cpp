#define graph_t vector<vector<int>>
#define visit_t vector<bool>


class Solution {
  public:
    bool dfs(graph_t& graph, visit_t& visited, int u,int parent) {
        visited[u] = true;
        for(auto& v:graph[u]) {
            if(!visited[v]) {
                bool check = dfs(graph,visited,v,u);
                if(check == true) return true;
            }
            else if(visited[v] == true && v!=parent) {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int n = edges.size();
        graph_t adj(V);
        visit_t visited(V,false);
      
        for(auto& pr: edges) {
            adj[pr[0]].push_back(pr[1]);
            adj[pr[1]].push_back(pr[0]);
            
        }
        
        for(int  i = 0;i<V;i++) {
            if(!visited[i]) {
                bool check = dfs(adj,visited,i,i);
                if(check == true) return true;
            }
        }
        return false;
    }
};