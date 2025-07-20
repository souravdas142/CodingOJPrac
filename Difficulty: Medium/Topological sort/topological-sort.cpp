
#define graph_t vector<vector<int>> 
#define visit_t vector<bool>

class Solution {
    bool dfs(visit_t& visited,visit_t& dfsVisited, graph_t& adj, vector<int>& ans, int u) {
        visited[u] = true;
        dfsVisited[u] = true;
        for(auto& v: adj[u]) {
            if(!visited[v]) {
                
                if(dfs(visited,dfsVisited,adj,ans,v)==true) return true;
            }
            else if(dfsVisited[v]==true) {
                return true;
            }
        }
        ans.push_back(u);
        dfsVisited[u] = false;
        return false;
    }
  public:
    vector<int> topoSort(int V, graph_t& edges) {
        // code here
        graph_t adj(V);
        visit_t visited(V,false);
        int n = edges.size();
        for(auto& pr: edges) {
            adj[pr[0]].push_back(pr[1]);
          
        }
        
        vector<int> ans;
        vector<bool> dfsVisited(V,false);
        
        for(int i = 0;i<V;i++) {
            if(!visited[i]) {
                if(dfs(visited,dfsVisited,adj,ans,i)==true) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};