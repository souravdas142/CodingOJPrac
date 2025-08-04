// User function Template for C++

#define pi pair<int,int>

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        unordered_map<int,int> dist;
        dist[start]  = 0;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,start});
        sort(arr.begin(),arr.end());
        
        while(!pq.empty()) {
            pi u = pq.top();
            pq.pop();
            if(u.second==end) break;
            for(int i = 0;i<n;i++) {
                int x = (u.second*arr[i])%100000;
                // if(x<=end) {
                    if(dist.find(x)==dist.end()) {
                        pq.push({u.first+1,x});
                        dist[x] = u.first+1;
                    }
                    else {
                        if(u.first+1 < dist[x]) {
                            pq.push({u.first+1,x});
                            dist[x] = u.first+1;
                        }
                    }
                // }
                // else {
                //     break;
                // }
            }
            
        }
        
        if(dist.find(end)!=dist.end()) return dist[end];
        return -1;
    }
};
