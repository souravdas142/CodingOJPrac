class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int dip = -1;
        int i = n-2;
        while(i>=0) {
            if(nums[i]<nums[i+1]) {
                dip = i;
                break;
            }
            i--;
        }

        if(dip<0) {
            return reverse(nums.begin(),nums.end());
        }
        //cout<<dip<<endl;
        int j = n-1;
        while(j>dip) {
            if(nums[j]>nums[dip]) {
                swap(nums[dip],nums[j]);
                break;
            }
            j--;
        }

        reverse(nums.begin()+dip+1,nums.end());
        
    }
};