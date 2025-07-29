#define graph_t vector<vector<int>>
#define visit_t vector<bool>
#define vi vector<int>
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        graph_t adj(V);
        vi indeg(V,0),ans;
        for(auto& vec: edges) {
            adj[vec[0]].push_back(vec[1]);
            indeg[vec[1]]++;
        }
        queue<int> que;
        
        for(int i  = 0;i<V;i++) {
            if(indeg[i]==0) {
                que.push(i);
            }
        }
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            ans.push_back(u);
            for(auto& v: adj[u]) {
                indeg[v]--;
                if(indeg[v]==0) {
                    que.push(v);
                }
            }
        }
        // cout<<ans.size()<<endl;
        if(ans.size()!=V) return true;
        return false;
    }
};