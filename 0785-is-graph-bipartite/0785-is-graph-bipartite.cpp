class Solution {

    bool bfs(vector<vector<int> >& adjlist, vector<int>& isColored,int source) {

        isColored[source]  = 0;
        deque<int> dq;
        dq.push_back(source);

        while(!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            int n = adjlist[u].size();
            for(int i = 0;i<n;i++) {
                
                int v = adjlist[u][i];
                int newColor = 1-isColored[u];
                if(isColored[v]==-1) {
                    isColored[v] = newColor;
                    dq.push_back(v);
                }
                else {
                    if(newColor != isColored[v] ) {
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
       for(int i= 0;i<n;i++ ) {
            if(isColored[i]==-1) {
                if(bfs(graph,isColored,i)==false) return false;
            }
       } 

       return true;
    }
};