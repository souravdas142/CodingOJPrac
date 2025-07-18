
#define graph_t vector<vector<int>>
#define visit_t vector<bool>

ostream& operator<<(ostream& print,vector<int>& tmp) {
    for(auto& e: tmp) {
        print<<e<<" ";
    }
    return print;
}

class Solution {
  public:
    bool dfs(graph_t& adj, visit_t& visited,visit_t& dfsvisited,int u, vector<int>& ans) {
        visited[u] = true;
        dfsvisited[u]=true;
        
        for(auto& v:adj[u]) {
            if(!visited[v]) {
                dfs(adj,visited,dfsvisited, v, ans);
            }
            // else if(dfsvisited[v]){
            //     return true;
            // }
        }
        ans.push_back(u);
        dfsvisited[u] = false;
        return false;
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        graph_t adj(V);
        visit_t visited(V,0);
        int n = edges.size();
        
        for(int i = 0;i<n;i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> ans;
        for(int i = 0;i<V;i++) {
            if(!visited[i]) {
                visit_t dfsvisited(V,0);
                dfs(adj,visited,dfsvisited,i,ans);
                
            }
        }
        reverse(ans.begin(),ans.end());
        //cout<<ans<<endl;
        return ans;
    }
};