class Solution {
  public:
  
    int solve(vector<pair<int,int>>& train) {
        
        int ans = 0;
        
        int n = train.size();
        sort(train.begin(),train.end(),[](auto& a, auto& b)->bool{
            
           if(a.second == b.second) return a.first > b.first;
           return a.second < b.second;
            
        });
        
        int start = train[0].first, end = train[0].second;
        ans = 1;
        
        for(int i = 1;i<n; i++) {
            
            if(train[i].first >= end) {
                start = train[i].first;
                end = train[i].second;
                ans++;
            }
            
        }
        
        
        
        
        return ans;
    }
  
    int maxStop(int train, int plat, vector<vector<int>> &trains) {
        // code here
        unordered_map<int,vector<pair<int,int>>> tsch;
        
        int n = trains.size();
        for(int i = 0;i<n;i++) {
            tsch[trains[i][2]].push_back({trains[i][0],trains[i][1]});
        }
        
        int ans = 0;
        
        for(auto& pf: tsch) {
            ans += solve(pf.second);
        }
        return ans;
    }
};