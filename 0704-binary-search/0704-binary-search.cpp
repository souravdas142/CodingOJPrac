class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int left = 0, right = sz - 1;

        while(left<right) {
            int mid = left+ (right-left)/2;
            if(nums[mid]>=target) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        if(nums[right]!=target) return -1;
        return right;
        
    }
};