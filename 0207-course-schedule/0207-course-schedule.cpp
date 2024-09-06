class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        
        vector<vector<int> > graph(numCourses);
        int n = preq.size();
        for(int i = 0;i<n;i++) {
            graph[preq[i][1]].push_back(preq[i][0]);
        }
        vector<int> indeg(numCourses);
        for(int i= 0;i<numCourses;i++) {
            for(int a:graph[i]) {
                indeg[a]++;
            }
        }

        queue<int> que;
        for(int i = 0;i<numCourses;i++) {
            if(indeg[i]==0) que.push(i);
        }

        int cnt = 0;

        while(!que.empty()) {
            int node = que.front();
            que.pop();
            cnt++;

            for(auto a: graph[node]) {
                indeg[a]--;
                if(indeg[a]==0) que.push(a);
            }
        }
        if(cnt == numCourses) return true;
        return false;

    }
};