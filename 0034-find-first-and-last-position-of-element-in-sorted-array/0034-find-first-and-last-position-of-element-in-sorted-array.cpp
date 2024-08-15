class Solution {
    int lb(vector<int>& nums,int target) {
        int sz = nums.size();
        int left = 0, right = sz-1;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(nums[mid]>=target) {
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        if(left <sz && left>=0 && nums[left] == target) 
            return left;
        return -1;
    }
    int up(vector<int>& nums,int target) {
        int sz = nums.size();
        int left = 0, right = sz-1;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(nums[mid]>target) {
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        if(left-1>=0 && left-1<sz && nums[left-1]==target)
            return left-1;
        
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.size() == 1 && nums[0]==target) return {0,0};
        int lbv = lb(nums,target);
        if (lbv==-1) return {-1,-1};
        int upv = up(nums,target);

        return {lbv,upv};
        
    }
};