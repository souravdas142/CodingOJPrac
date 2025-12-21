class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>> vpi;
        int n = start.size();
        for(int i = 0;i<n;i++) {
            vpi.push_back({start[i],finish[i]});
            
        }
        sort(vpi.begin(),vpi.end(),[](auto& a, auto& b)->bool{
            return a.second<b.second;
        });
        int starti = vpi[0].first, endi = vpi[0].second;
        int cnt = 1;
        
        for(int i = 1;i<n;i++) {
            if(vpi[i].first <= endi) {
                continue;
            }
            else {
                endi = vpi[i].second;
                starti = vpi[i].first;
                cnt++;
            }
        }
        return cnt;
    }
};