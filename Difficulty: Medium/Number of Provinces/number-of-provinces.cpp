//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void runDfs(vector<vector<int> >&adj,int &ans,vector<bool>& visited,int node) {
        visited[node] = true;
        
        for(int i = 0;i<adj[node].size();i++) {
            if(visited[adj[node][i]]==false)
                runDfs(adj,ans,visited,adj[node][i]);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adjmat, int V) {
        // code here
        int ans = 0;
        // construction of adj list
        vector<vector<int> > adj(V);
        for(int u = 0;u<V;u++) {
            for(int v = 0;v<V;v++) {
                
                if(adjmat[u][v]==1 && u!=v) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
   /*     
        for(int i = 0;i<V;i++) {
            cout<<i<<" -> ";
            for(int j = 0;j<adj[i].size();j++) {
                cout<<adj[i][j]<<",";
            }
            cout<<endl;
        }
        
     */  
        
        int node = 0;
        vector<bool> visited(V,false);
        for(int i = 0;i<V;i++) {
            if(!visited[i]) {
                ans++;
            
                runDfs(adj,ans,visited,i);
            }
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends