class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n<2) return n;

        unordered_map<int,int> look;
        for(int ele:nums) {
            look.insert({ele,1});
        }
        int maxi = 1;
        for(auto mit:look) {
            int x = mit.first;
            if(mit.second==0) continue;
            look[mit.first] = 0;
            int cnt = 1;
            int inc = x+1;
            while(look.find(inc)!=look.end()) {
                look[inc] = 0;
                inc += 1;
                cnt++;
                
            }
            int dec = x-1;
            while(look.find(inc)!=look.end()) {
                look[dec] = 0;
                inc -= 1;
                cnt++;
                
            }
            maxi = max(maxi,cnt);
            cnt = 0;

        }

        return maxi;
        
    }
};