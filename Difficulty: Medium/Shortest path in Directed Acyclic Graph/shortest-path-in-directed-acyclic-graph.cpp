// User function Template for C++
class Solution {
  public:
    void topoSort(vector<vector<pair<int,int>>> &adj, int u, vector<bool>& visited, stack<int>& topo) {
        visited[u] = true;
        for(auto& v:adj[u]) {
            if(!visited[v.first]) {
                topoSort(adj,v.first,visited,topo);
            }
        }
        topo.push(u);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        vector<int> dist(V,INT_MAX);
        dist[0] = 0; // source is always 0;
        vector<int> indeg(V,0);
        for(auto& vec: edges) {
            adj[vec[0]].push_back({vec[1],vec[2]});
            indeg[vec[1]]++;
        }
        
        queue<int> que;
        
        // for(int i  = 0;i<V;i++) {
        //     if(indeg[i]==0) {
        //         que.push(i);
        //         //dist[i] = 0;
        //     }
        // }
        que.push(0);
        stack<int> topo;
        
        // while(!que.empty()) {
        //     int u = que.front();
        //     que.pop();
        //     topo.push(u);
        //     for(auto& v: adj[u]) {
        //         indeg[v.first]--;
        //         if(indeg[v.first]==0) {
        //             que.push(v.first);
        //         }
        //     }
        // }
        vector<bool> visited(V,false);
       topoSort(adj,0,visited,topo);
        
        while(!topo.empty()) {
            int u = topo.top();
            //cout<<u<<endl;
            topo.pop();
            for(auto& v :adj[u]) {
                if(dist[u]+v.second<dist[v.first]) {
                    dist[v.first] = dist[u]+v.second;
                }
            }
        }
        
        for(int i  = 0;i<V;i++) {
            if(dist[i]==INT_MAX) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
