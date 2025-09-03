#define pi pair<int,int>

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> ump;
        for(auto& e: nums) ump[e]++;
        int cnt = 0;
        while(!ump.empty()) {
            int prev = 0;
            for(auto& e: ump) {
                if(cnt>0 && abs(e.first-prev)!=1) return false;
                prev = e.first;
                cnt++;
                e.second--;
                if(e.second==0) {
                    ump.erase(e.first);
                }
                if(cnt==k) {
                    cnt=0;
                    break;
                }
            }
        }

        if(cnt>0) return false;
        return true;
    }
};