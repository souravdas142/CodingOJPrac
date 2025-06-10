#define pi pair<int,int>


class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = profit.size();
        vector<pi> deadprofit(n);
        int maxdeadline = 0;
        for(int i= 0;i<n;i++) {
            deadprofit[i] = {profit[i],deadline[i]};
            maxdeadline = max(maxdeadline,deadline[i]);
        }
        
        int cnt = 0;
        int maxProfit = 0;
        
        sort(deadprofit.begin(),deadprofit.end(),[](pi a, pi b) -> bool {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        });
        
        
        set<int,greater<int> > mark;
        for(int i = maxdeadline;i>=1;i--) {
            mark.insert(i);
        }
      
        
        for(int i = 0;i<n && !mark.empty();i++) {
            
            int deadline = deadprofit[i].second;
            auto nextBestAvailableSlot = mark.lower_bound(deadline);
            if(nextBestAvailableSlot!=mark.end()) {
                maxProfit+=deadprofit[i].first;
                cnt++;
                mark.erase(nextBestAvailableSlot);
            }
            
            
            
        }
        
        return {cnt,maxProfit};
    }
};