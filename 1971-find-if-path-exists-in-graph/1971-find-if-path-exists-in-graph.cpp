#define vvi vector<vector<int> >
#define vb vector<bool> 

class Solution {
private:
    bool bfs(vvi& adjlist,vb& visited,int source, int destination) {
        visited[source] = true;
        deque<int> dq;
        dq.push_back(source);

        while(!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            for(int v:adjlist[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    dq.push_back(v);
                    if(v == destination) return true;
                }
            }

        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        int sz = edges.size();
        if(sz==0) return true;

        if(source==destination) return true;

        vector<vector<int> > adjlist(n);



        for(int i = 0;i<sz;i++) {
            adjlist[edges[i][0]].push_back(edges[i][1]);
        }

        vector<bool> visited(n,false);

        return bfs(adjlist,visited,source,destination);
        
    }
};