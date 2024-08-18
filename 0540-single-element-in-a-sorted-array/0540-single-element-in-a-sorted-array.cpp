class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int sz = nums.size();
        int left = 0, right = sz - 1;
        if(sz==1) return nums[0];
        while(left<=right) {
            int mid = left+(right-left)/2;

            if((mid&1 && nums[mid]==nums[mid-1]) || (!(mid&1) && nums[mid]==nums[mid+1])  ) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }

        }

        return nums[left];
        
    }
};