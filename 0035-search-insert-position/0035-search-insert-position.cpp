class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int sz = nums.size();
        int left = 0 , right =sz - 1;
        if(target>nums[sz-1]) return sz;
        while(left<right) {
            int mid = left+(right-left)/2;
            if(nums[mid]>=target) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return right;
    }
};