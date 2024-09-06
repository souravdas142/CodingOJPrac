class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int> > graph(numCourses);
        vector<int> ans;
        vector<int> indeg(numCourses);
        queue<int> que;

        int n = preq.size();

        for(int i = 0;i<n;i++) {
            graph[preq[i][1]].push_back(preq[i][0]);
        }

        for(int i  =0;i<numCourses;i++) {
            for(auto a:graph[i]) {
                indeg[a]++;
            }
        }

        for(int i = 0;i<numCourses;i++) {
            if(indeg[i]==0) que.push(i);
        }


        while(!que.empty()) {
            int node = que.front();
            que.pop();
            ans.push_back(node);

            for(auto a:graph[node]) {
                indeg[a]--;
                if(indeg[a]==0) que.push(a);
            }
        }

        if(ans.size()==numCourses) return ans;
        return {};
    }
};