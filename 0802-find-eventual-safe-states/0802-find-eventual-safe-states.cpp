#define vvi vector<vector<int> >
#define vi vector<int>


class Solution {
    bool detectCycle(vvi& graph, vi& visited, vi& pathvisited,int node) {
        
        visited[node] = 1;
        pathvisited[node] = 1;

        for(auto a:graph[node]) {
            if(!visited[a]) {
                
                if(detectCycle(graph,visited,pathvisited,a)==true) return true;

            }
            else if(pathvisited[a]==1) {
                return true;
            }
        }
        pathvisited[node] = 0;
        return false;
    } 
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        vector<int> ans;

        for(int i= 0;i<n;i++) {
            detectCycle(graph,visited,pathvisited,i);
                
            
        }

        for(int i = 0;i<n;i++) {
            if(pathvisited[i]==0) {
                ans.push_back(i);
            }
        }

        return ans;
        
    }
};