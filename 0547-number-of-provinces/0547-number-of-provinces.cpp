class Solution {
    void bfs(int start, vector<vector<int> >& adjlist, vector<bool>& visited) {
        
        visited[start] = true;
        deque<int> dq;
        dq.push_back(start);

        while(!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            
            for(auto v: adjlist[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    dq.push_back(v);
                }
            }

        }

    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int> > adjlist(n);
        vector<bool> visited(n,false);

        for(int u = 0;u<n;u++) {
            for(int v = 0;v<n;v++) {
                if(isConnected[u][v]) {
                    adjlist[u].push_back(v); 
                }
            }
        }
        int cnt = 0;
        for(int u = 0;u<n;u++) {
            if(!visited[u]) {
                cnt++;
                bfs(u,adjlist,visited);
            }
        }

        return cnt;
        
    }
};