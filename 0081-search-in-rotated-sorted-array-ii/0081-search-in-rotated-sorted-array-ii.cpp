class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<high) {
            int mid = low+(high-low)/2;

            if(nums[mid]==target) return true;
            if(low!=mid && mid!=high && nums[low]==nums[mid] && nums[mid] == nums[high]) {
                low++; high--;
            }
            else if(nums[mid]>=nums[low]) { // sorted  on the left side
                if(nums[low]<= target && nums[mid]>=target) {
                    high = mid;
                }
                else {
                    low = mid+1;
                }
            }
            else { // sorted on right side
                if(nums[mid]<=target && nums[high]>=target) {
                    low = mid;
                }
                else {
                    high = mid;
                }
            }

        }
        if(nums[high]!=target) return false;
        return true;
        
    }
};