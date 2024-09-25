class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i  = 0, j = 0;
        int cntz = 0;
        int ans = 0;
        while(j<n) {
            if(nums[j]==0) cntz++;
            if(cntz<=k) {
                ans = max(ans,j-i+1);
            }
            else if(cntz>k) {

                if(nums[i]==0) {
                    cntz--;
                    
                }
                i++;

            }
            j++;
        } 
        return ans;
    }
};