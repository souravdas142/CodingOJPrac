class Solution {

    void runDfs(vector<vector<int> >& adj, int dest,int node, vector<bool>& visited,bool& ans) {
        visited[node] = true;
        if(node==dest) {
            ans = true;
            return;
        }
        int sz = adj[node].size();
        for(int v = 0;v<sz;v++) {
            if(visited[adj[node][v]]==false)
                runDfs(adj,dest,adj[node][v],visited,ans);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {

        vector<vector<int> > adj(n);
        for(int u = 0;u<n;u++) {
            
            adj[edges[u][0]].push_back(edges[u][1]);
            adj[edges[u][1]].push_back(edges[u][0]);
            
        }
        vector<bool> visited(n,false);
        
        
        runDfs(adj,dest,src,visited,ans);
        return ans;
    }
};