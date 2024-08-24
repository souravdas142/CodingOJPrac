class Solution {
    int bfs(int &start,vector<bool> visited,vector<vector<int> >& adjlist) {

        int cnt = 1;
        int townJudge = start;

        visited[start] = true;
        deque<int> dq;
        dq.push_back(start);
        while(!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            
            
            for(auto v:adjlist[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    cnt++;
                    
                    dq.push_back(v);
                }
            }
            if(cnt>1) break;
        }

        if(cnt>1) return -1;
        return townJudge;

    }
public:
    int findJudge(int n, vector<vector<int>>& trust) {

       int sz = trust.size();
        vector<vector<int> > adjlist(n+1);

        for(int i = 0;i<sz;i++) {
           
            adjlist[trust[i][0]].push_back(trust[i][1]);

        }

        vector<bool> visited(n+1,false);

        for(int u = 1;u<=n;u++) {
            if(!visited[u]) {
                int ans = bfs(u,visited,adjlist);
                if(ans>-1) return ans;
            }
        }

        return -1;

        
    }
};