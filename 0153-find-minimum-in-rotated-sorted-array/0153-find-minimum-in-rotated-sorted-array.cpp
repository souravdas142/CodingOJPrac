class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<high) {
            int mid = low+(high-low)/2;

            if(nums[mid]>= nums[low] && nums[mid]>=nums[high]) {
                low =mid+1;
            }
            else if(nums[mid]>nums[high]) {
                high = mid;
            }
            else {
                high = mid;
            }
        }

        return nums[high];
        
    }
};