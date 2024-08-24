//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<int> bfs(int starting,vector<vector<int> >& adjlist,int v,vector<bool>& visited) {
        
        deque<int> dq;
        dq.push_back(starting);
        visited[starting] = true;
        vector<int> bfsans;
        
        while(!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            
            bfsans.push_back(u);
            
            
            for(int v:adjlist[u]) {
                if(visited[v]!=true) {
                    dq.push_back(v);
                    visited[v] = true;
                }
            }
        }
        
        return bfsans;
        
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<vector<int> > adjlist(V);
       
        for(int u = 0;u<V;u++) {
            for(auto v:adj[u]) {
                adjlist[u].push_back(v);
                
                
            }
        }
        
        vector<bool> visited(V,false);
        int starting = 0;
  
                
        vector<int> bfsans = bfs(starting,adjlist,V,visited);
        return bfsans;
                
          
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends