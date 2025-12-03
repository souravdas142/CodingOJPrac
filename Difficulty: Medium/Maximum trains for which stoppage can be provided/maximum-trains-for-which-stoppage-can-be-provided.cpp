
void printVector(vector<pair<int,int>>& p) {
    for(auto &e: p) {
        cout<<e.first<<" "<<e.second<<endl;
    }
    
}

class Solution {
  public:
    int solve(vector<pair<int,int>>& trains) {
        if (trains.empty()) return 0;
        sort(trains.begin(),trains.end(),[](auto& a, auto& b)->bool {
            return a.second<b.second;
        });
        int n = trains.size();
       
        
        
        
        
        int arr = trains[0].first, dep = trains[0].second;
        int ans = 1;
        int j = 1;
        
        while(j<n) {
            if(trains[j].first>=dep) {
                ans++;
                arr = trains[j].first;
                dep = trains[j].second;
            }
            j++;
        }
        //printVector(trains);
        // cout<<ans<<endl;
        return ans;
    }
    
    int maxStop(int train, int plat, vector<vector<int>> &trains) {
        // code here
        int n = trains.size();
        int m = plat;
        unordered_map<int,vector<pair<int,int>>> trains2;
        
        for(auto& train: trains) {
            trains2[train[2]].push_back({train[0],train[1]});
        }
        
        int ans = 0;
        
        
        for(auto& pr: trains2) {
            ans+=solve(pr.second);
        }
        
        return ans;
    }
};