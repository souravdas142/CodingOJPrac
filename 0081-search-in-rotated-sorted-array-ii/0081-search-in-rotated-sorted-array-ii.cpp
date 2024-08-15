class Solution {
public:
    bool search(vector<int>& nums, int target) {
        

        int sz = nums.size();
        if(sz == 0) return false;
        if(sz == 1 && nums[0]==target) return true;
        int left = 0, right = sz - 1;

        while(left<=right) {
            int mid = left+(right-  left)/2;
            if(target == nums[mid]) return true;
            if(nums[left]==nums[mid] && nums[mid] == nums[right]) {
                left++; right--;
            }
            else if(nums[left]<=nums[mid]) { // sorted
                if(target>=nums[left] && target<=nums[mid]) {
                    right = mid;
                }
                else {
                    left = mid+1;
                }
            }
            else { //sorted

                if(target>=nums[mid] && target<=nums[right]) {
                    left = mid+1;
                }
                else {
                    right = mid;
                }

            }
        }

       return false;
        
    }
};