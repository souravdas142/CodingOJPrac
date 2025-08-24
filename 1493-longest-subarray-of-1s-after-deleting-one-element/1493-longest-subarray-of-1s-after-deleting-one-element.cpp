class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int ans = -1;

        int zero = 0;

        int i = 0, j = 0;
        while(j<n) {
            if(nums[j]==0) zero++;
            if(zero>1) {
                if(nums[i]==0) zero--;
                i++;
            }
            ans = max(ans,j-i);
            j++;
        }

        if(ans==n) return ans-1;
        return ans;
        
    }
};