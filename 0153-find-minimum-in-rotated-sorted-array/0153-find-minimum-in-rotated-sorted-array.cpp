class Solution {
public:
    int findMin(vector<int>& nums) {

        int sz = nums.size();
        
        if(nums[0]<=nums[sz-1]) return nums[0];
         int left = 0, right = sz - 1;
         while(left<right) {

            int mid = left+(right-left)/2;

            if(nums[mid]<nums[right]) {
                right = mid-1;
            }
            else if(nums[mid]>nums[right]) {
                left = mid+1;
            }

         }
         cout<<left<<" "<<right<<endl;
         return nums[left];
    }
};