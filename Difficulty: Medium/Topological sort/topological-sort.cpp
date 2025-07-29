#define graph_t vector<vector<int>> 


class Solution {
  public:
  
    void dfs(graph_t& adj, vector<bool>& visited, int u, vector<int>& ans) {
        visited[u] = true;
        for(auto& v: adj[u]) {
            if(!visited[v]) {
                dfs(adj,visited,v,ans);
            }
        }
        ans.push_back(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        graph_t adj(V);
        for(auto& vec: edges) {
            adj[vec[0]].push_back(vec[1]);
        
        }
        
        vector<bool> visited(V,0);
        vector<int> ans;
        
        for(int i = 0;i<V;i++) {
            if(!visited[i])
                dfs(adj,visited,i,ans);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};