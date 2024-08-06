class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //need to find the dip
        int sz = nums.size();
        int j = sz-1, dip_pos = 0;
        while(j>0) {
            if(nums[j]>nums[j-1]) {
                dip_pos = j-1;
                break;
            }
            j--;
        }
        if(dip_pos == 0) {
            sort(nums.begin(),nums.end());
            return;
        }
        j = sz-1;
        while(j>dip_pos) {
            if(nums[j]>nums[dip_pos]) {
                swap(nums[j],nums[dip_pos]);
                break;
            }

            j--;
        }

        sort(nums.begin()+dip_pos+1,nums.end());
        
    }
};