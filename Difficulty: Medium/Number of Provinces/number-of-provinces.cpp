// User function Template for C++
#define adj_t vector<vector<int>>
#define visit_t vector<bool>
 
class Solution {
  public:
    void dfs(adj_t& graph, visit_t& visited, int u) {
        visited[u] = true;
        
        for(auto& v:graph[u]) {
            if(!visited[v]) {
                dfs(graph,visited,v);
            }
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        adj_t graph(V);
        visit_t visited(V,false);
        int province = 0;
        
        for(int u = 0;u<adj.size();u++) {
            for(int v = 0;v<adj.size();v++) {
                if(adj[u][v]==1) {
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }
        
        for(int i = 0;i<V;i++) {
            if(!visited[i]) {
                dfs(graph,visited,i);
                province++;
            }
        }
        
        return province;
        
    }
};