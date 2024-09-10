//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        int n = N;
        int m = M;
        vector<vector<int> > graph(n);
        
        for(int i = 0;i<m;i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        
        
        vector<bool> visited(n,false);
        vector<int> dist(n,INT_MAX);
        queue<pair<int,int> > que;
        visited[src] = true;
        que.push({src,0});
        dist[src] = 0;

        while(!que.empty()) {
            pair<int,int> node = que.front();
            que.pop();

            for(auto a: graph[node.first]) {

                if(!visited[a]) {
                    dist[a] = node.second+1;
                    visited[a] = true;
                    que.push({a,dist[a]});
                }
            }


        }
        

        for(int i= 0;i<n;i++) {
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends