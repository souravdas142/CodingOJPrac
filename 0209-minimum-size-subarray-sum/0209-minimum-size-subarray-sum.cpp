class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;

        int i = 0,j = 0;
        int sz = nums.size();
        int sum = 0;
        while(j<sz) {
            sum+=nums[j];
            
            while(sum>=target && i<=j) {
                ans = min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;

        }
       

        if(ans == INT_MAX) ans = 0;
        return ans;
        
    }
};