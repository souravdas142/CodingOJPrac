#define ll long long

class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        ll ans = 0;
        int i = 0, j=n-1;
        int k = j-1;
        while(i>=0 && j>i+1) {
            ans+=nums[k];
            j = k-1;
            i+=1;
            k = j-1;
        }

        return ans;

    }
};