#define  ll long long
#define mod ((ll)(1e9)+7)

class Solution {
public:
    int specialTriplets(vector<int>& nums) {

        unordered_map<int,int> suffix,prefix;
        for(auto e: nums) {
            suffix[e]++;
        }
        int ans = 0;
        int n = nums.size();
        
        for(int i= 0;i<n;i++) {
            suffix[nums[i]]--;
            int x = nums[i]*2;
            int xInSuffix = 0;
            int xInPrefix = 0;
            if(suffix.find(x)!=suffix.end()) {
                xInSuffix = suffix[x];
            }
            if(prefix.find(x)!=prefix.end()) {
                xInPrefix = prefix[x];
            }
            ans = (ans%mod+((xInPrefix%mod*xInSuffix%mod)%mod))%mod;
            prefix[nums[i]]++;
        }
        return ans;
        
    }
};