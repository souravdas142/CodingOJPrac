#define vvpi vector<vector<pair<int,int>>> 
#define ppi pair<int,pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vvpi adj(n);
        for(auto& vec: flights) {
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        vector<int> cost(n,INT_MAX);
        cost[src] = 0;
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq; // stop dest, cost
        pq.push({0,{src,0}});

        while(!pq.empty()) {
            ppi u = pq.top();
            pq.pop();
            int ustops = u.first;
            int udest = u.second.first;
            int ucost = u.second.second;

            for(auto vdest: adj[udest]) {
                if(ucost+vdest.second < cost[vdest.first] && ustops<=k) {
                    cost[vdest.first] = ucost+vdest.second;
                    pq.push({ustops+1,{vdest.first,ucost+vdest.second}});
                }
            }

        }

        if(cost[dst]==INT_MAX) return -1;
        return cost[dst];
 
    }
};