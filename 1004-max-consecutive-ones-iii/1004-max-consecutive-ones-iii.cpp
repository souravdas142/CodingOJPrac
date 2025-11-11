class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zero = 0;
        int j = 0;
        int i = 0;
        int ans = INT_MIN;
        while(j<n) {
            
            if(nums[j]==0) zero++;

            if(zero>k) {
                if(nums[i]==0) zero--;
                i++;
            }

            if(zero<=k)
                ans = max(ans,j-i+1);

            j++;
        }

        return ans;
    }
};