#define ll long long
#define piv pair<ll,vector<ll>>
#define pi pair<ll,ll> 
#define mod ((ll)((1e9) + 7))

class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<ll,ll>>> adj(n);
        vector<ll> ways(n,0);
        ways[0] = 1;

        for(auto& vec: roads) {
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0],vec[2]});
        }

        ll start = 0, end = n-1;
        vector<ll> dist(n,LLONG_MAX);
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;

        dist[start] = 0;
        pq.push({0,start});

        while(!pq.empty()) {
            pair<ll,ll> u = pq.top();
            pq.pop();

            for(auto& vpr: adj[u.second]) {
                ll vdist = (u.first + vpr.second);
                if(vdist<=dist[vpr.first]) {
                    if(vdist<dist[vpr.first]) {
                        dist[vpr.first] = vdist;
                        ways[vpr.first] = ways[u.second];
                        pq.push({vdist,vpr.first});
                    }
                    else {
                        ways[vpr.first]= (ways[vpr.first] + ways[u.second])%mod;
                        
                    }
                    
                }
            }

        }

        return (ways[n-1]%mod);

       
    }
};