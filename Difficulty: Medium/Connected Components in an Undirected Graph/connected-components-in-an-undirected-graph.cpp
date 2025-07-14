
#define adj_t vector<vector<int>>
#define visit_t vector<bool>

class Solution {
  public:
  
    void dfs(adj_t& graph, int u, vector<bool>& visited, vector<int>& res) {
        visited[u] = true;
        res.push_back(u);
        for(int i  = 0;i<graph[u].size();i++) {
            int v = graph[u][i];
            if(!visited[v]) {
                dfs(graph,v,visited,res);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        int n = edges.size();
        visit_t visited(V,false);
        adj_t graph(V);
        for(int i = 0; i<n;i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        vector<vector<int> > ans;
        
        for(int i  = 0;i<V;i++) {
            if(!visited[i]) {
                vector<int> res;
                dfs(graph,i,visited,res);
                ans.push_back(res);
            }
        }
        return ans;
    }
};
