class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<high) {
            int mid = low+(high-low)/2;
            
            if(nums[mid]>=nums[low]) { // sorted
                if(nums[low]<=target && nums[mid]>=target) {
                    high = mid;
                }
                else {
                    low = mid+1;
                }
            }
            else {
                if(nums[mid]<=target && nums[high]>=target) {
                    low = mid;
                }
                else {
                    high = mid;
                }
            }
            


        }

        if(nums[high]!=target) return -1;
        return high;

    
        
    }
};