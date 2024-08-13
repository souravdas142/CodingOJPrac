//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        /*
       int sz = sizeof(adj);
       cout<<sz<<endl;
       for(int u = 0;u<sz;u++) {
           cout<<u<<"->";
           for(int v = 0;v<adj[u].size();v++) {
               cout<<adj[u][v]<<" ";
           }
           cout<<endl;
       }
       */
        
        deque<int> bfs;
        vector<int> bfsans;
        vector<bool> visited(V,false);
        visited[0] = true;
        bfs.push_back(0);
        //bfsans.push_back(0);
        while(!bfs.empty()) {
            int u = bfs.front();
            bfs.pop_front();
            bfsans.push_back(u);
            for(int v:adj[u]) {
                if(visited[v]==false) {
                    bfs.push_back(v);
                    visited[v] = true;
                    
                }
            }
        }
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