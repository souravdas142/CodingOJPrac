class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {

        int sz = nums.size();
        //if(size== 1) return 0;

        int i = 0,j = i+1;
        int mini = nums[sz-1] - nums[0];

        while(j<sz) {
            int high = max(nums[sz-1]-k,nums[i]+k);
            int low = min(nums[0]+k,nums[j]-k);
            int gap = high - low;
            mini = min(mini,gap);
            i = j;
            j = j+1;
        }

        return mini;

        
    }
};