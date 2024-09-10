//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define vvpii vector<vector<pair<int,int> > >
#define vi vector<int>
#define vb vector<bool>
class Solution {
  private:
    bool dfs(vvpii& graph,vb& visited,stack<int>& st,int source) {
        visited[source] = true;
        for(auto pr:graph[source]) {
            
            if(!visited[pr.first]) {
                dfs(graph,visited,st,pr.first);
            }
            
        }
        st.push(source);
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        
        vvpii graph(n);
        vb visited(n,false);
        vi dist(n,INT_MAX);
        stack<int> st;
        vi ans;
        
        for(int i = 0;i<m;i++) {
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            
        }
        
        for(int i = 0;i<n;i++) {
            if(!visited[i]) {
               
                dfs(graph,visited,st,i);
            }
        }
        
        
         dist[0] = 0;
         
         while(!st.empty() && st.top()!=0) st.pop();
         
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            for(auto adjpr:graph[node]) {
                
                int v = adjpr.first;
                int wt = adjpr.second;
                
                if(dist[node]+wt<dist[v]) {
                    dist[v] = dist[node]+wt;
                }
            }
        }
        
        for(int i = 0;i<n;i++) {
            if(dist[i]==INT_MAX) dist[i] = -1;
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends