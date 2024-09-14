//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

ostream& operator<<(ostream& print,vector<int>& vec) {
    print<<endl;
    for(auto a:vec) {
        print<<a<<" -> ";
    }
    print<<endl;
    return print;
}


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> dist(n+1,INT_MAX),ans;
        vector<vector<pair<int,int> > > adj(n+1);
        for(int i = 0;i<m;i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        dist[1] = 0;
        //dist[0]=0;
        pq.push({0,1});   //{dist,node}
        vector<int> parent(n+1,0);
        parent[1]=-1;
        parent[0] = 0;
        
        while(!pq.empty()) {
            pair<int,int> prnodeu = pq.top();
            pq.pop();
            
            int u = prnodeu.second;
            int distu = prnodeu.first;
            for(auto prv:adj[u]) {
                int distv = prv.second;
                int v = prv.first;
                if(distu+distv<dist[v]) {
                    dist[v] = distu+distv;
                    pq.push({dist[v],v});
                    parent[v]=u;
                }
            }
            
        }
        if(dist[n]==INT_MAX) return {-1};
        vector<int> path;
        //path.push_back(n);
        int p = n;
        while(p!=-1) {
            path.push_back(p);
            p = parent[p];
        }
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        //path.push_back(1);
        
        //cout<<path<<endl;
        
        
        return path;
        
    }   
    
    
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends