class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        while(i<n && j<n) {
            while(j<n && i<n && nums[i]%2!=0) {
                
                if(nums[j]%2==0) {
                    swap(nums[j],nums[i]);
                    break;
                }
                j+=2;
            }
            i+=2;
        }
        return nums;
    }
    
};