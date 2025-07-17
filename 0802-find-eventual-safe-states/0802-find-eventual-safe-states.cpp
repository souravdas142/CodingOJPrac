class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> ans;
        vector<vector<int> > rgraph(n);
        vector<int> indeg(n,0);
        queue<int> que;

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<graph[i].size();j++) {
                int node = graph[i][j];
                rgraph[node].push_back(i);
            }
        }

        for(int i = 0;i<n;i++) {
            for(auto a:rgraph[i]) {
                indeg[a]++;
            }
        }

        for(int i = 0;i<n;i++) {
            if(indeg[i]==0) que.push(i);
        }

        while(!que.empty()) {
            int node = que.front();
            que.pop();
            ans.push_back(node);
            for(auto a: rgraph[node]) {
                indeg[a]--;
                if(indeg[a]==0) que.push(a);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};