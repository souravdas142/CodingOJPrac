//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool checkCycle(vector<int> adj[],vector<bool>& visited,vector<bool>& pathvisited,int parent) {
        
        visited[parent] = true;
        pathvisited[parent]=true;
        
        for(auto child:adj[parent]) {
            
            //int child = adj[parent][j];
            
            
            
            
            if(!visited[child]) {

                
                
                if(checkCycle(adj,visited,pathvisited,child)==true) {
                    return true;
                }
                
                
                
            }
            else if(pathvisited[child]==true) {
                return true;
                
            }
        }
        pathvisited[parent] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
       // vector<vector<int> > adjlist(V);
        
       
        
        
        vector<bool> visited(V,false);
        vector<bool> pathvisited(V,false);
        
        for(int i = 0;i<V;i++) {
            if(!visited[i]) {
                if(checkCycle(adj,visited,pathvisited,i)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends