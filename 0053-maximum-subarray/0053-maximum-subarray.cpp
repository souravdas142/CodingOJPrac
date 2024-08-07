class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxi = numeric_limits<int>::min();
        int sum = 0;
        int j = 0;
        int sz = nums.size();
        while(j<sz) {

            int possible = sum+nums[j];
            maxi = max(maxi,possible);
            if(possible<0) {
                sum = 0;
            }
            else {
                sum = possible;
            }
            j++;
        }

        return maxi;
        
    }
};