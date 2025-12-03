class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return;
        int j = n-1;
        int dip = j-1;
        while(j>0) {
            if(nums[dip]<nums[j]) break;
            dip--;
            j--;
        }

        if(dip == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }

        j = n-1;
        while(j>dip) {

            if(nums[j]>nums[dip]) {
                swap(nums[j],nums[dip]);
                reverse(nums.begin()+dip+1,nums.end());
                return;
            }

            j--;
        }
        
    }
};