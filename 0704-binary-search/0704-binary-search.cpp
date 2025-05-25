class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0, high = n-1;
        while(low<high) {
            int mid = low+(high-low)/2;
            if(target>nums[mid]) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        } 
        if(high >=0 && high<n && nums[high]==target) return high;
        return -1;       
    }
};