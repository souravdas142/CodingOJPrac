//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void runDfs(int u,vector<vector<int> >& adjlist,vector<bool>& visited,vector<int>& dfsans) {
        visited[u] = true;
        dfsans.push_back(u);
        
        for(auto v:adjlist[u]) {
            if(!visited[v]) {
                
                runDfs(v,adjlist,visited,dfsans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int> > adjlist(V);
        for(int u = 0;u<V;u++) {
            for(auto v:adj[u]) {
                adjlist[u].push_back(v);
                adjlist[v].push_back(u);
            }
        }
        
        vector<int> dfsans;
        
        vector<bool> visited(V,false);
        int start = 0;
        runDfs(start,adjlist,visited,dfsans);
        return dfsans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends