class Solution {

    bool bfs(vector<vector<int> >& adjlist,vector<int>& isColored,int node) {

        isColored[node] = 0;
        deque<pair<int,int> > dq;
        dq.push_back({node,-1});

        while(!dq.empty()) {

            pair<int,int> u = dq.front();
            dq.pop_front();
            int sz = adjlist[u.first].size();

            for(int i = 0;i<sz;i++) {
                
                int v = adjlist[u.first][i];
                int newColor = 1-isColored[u.first];
                if(isColored[v]==-1) {
                    dq.push_back({v,u.first});
                    isColored[v] = newColor;
                }   
                else if(u.second!=v) {
                    if(isColored[v]!=newColor) {
                        return false;
                    }
                }

            }

        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> isColored(n,-1);

        for(int i = 0;i<n;i++) {
            if(isColored[i]==-1) {
                if(bfs(graph,isColored,i)==false) return false;
            }
        }
        
        return true;
    }
};