#define graph_t vector<vector<int>>


class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> pre) {
        // code here
        graph_t adj(n);
        vector<int> indeg(n,0);
        for(auto& vec: pre) {
            adj[vec[1]].push_back(vec[0]);
            indeg[vec[0]]++;
        }
        
        vector<int> ans;
        queue<int> que;
        
        for(int i = 0;i<n;i++) {
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
        if(n!=ans.size()) return {};
        return ans;
    }
};