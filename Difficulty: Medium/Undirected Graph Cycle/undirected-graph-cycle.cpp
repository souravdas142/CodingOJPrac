//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define vvi vector<vector<int> >
#define vvb vector<vector<bool> >
#define vi vector<int>
#define vb vector<bool>

#define pi pair<int,int> 

class Solution {
  private:
  
  //bool detectCycle(vvi& adjlist,vb& visited, int src) {
  bool detectCycle(vector<int> adjlist[],bool visited[], int src) {
      
      deque<pi> dq;
      dq.push_back({src,-1}); // we don't know the parent of src so -1
      visited[src] = true;
      
      while(!dq.empty()) {
          pi pr = dq.front();
          dq.pop_front();
          int parent = pr.second;
          int u = pr.first;
          
          for(auto v:adjlist[u]) {
              
              
              if(!visited[v]) {
                  visited[v] = true;
                  dq.push_back({v,u});
              }
              else if(v!=parent) {
                  return true;
              }
          }
          
          
        }
      
      return false;
      
      
      
  }

  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
       /* vvi adjlist(V);
        int sz = adj->size();
        
        cout<<sz<<endl;
        
        for(int i = 0;i<sz;i++) {
            adjlist[i] = adj[i];
        }
        */
        bool visited[V] = {false};
        
        for(int i = 0;i<V;i++) {
            if(!visited[i]) {
                //bool checkCycle = detectCycle(adjlist,visited,i);
                bool checkCycle = detectCycle(adj,visited,i);
                if(checkCycle) return true;
            }
        }
        
        return false;
        
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends