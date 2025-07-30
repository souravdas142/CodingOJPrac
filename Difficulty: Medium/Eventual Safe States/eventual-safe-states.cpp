// User function Template for C++
#define graph_t vector<vector<int>>
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        graph_t revadj(V);
        vector<int> indeg(V,0),ans;
        
        for(int u  = 0;u<V;u++) {
            for(auto& v:adj[u]) {
                revadj[v].push_back(u);
                indeg[u]++;
            }
        }
        
        queue<int> que;
        
        for(int i = 0;i<V;i++) {
            if(indeg[i]==0) {
                que.push(i);
            }
        }
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            ans.push_back(u);
            for(auto& v: revadj[u]) {
                indeg[v]--;
                if(indeg[v]==0) {
                    que.push(v);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
