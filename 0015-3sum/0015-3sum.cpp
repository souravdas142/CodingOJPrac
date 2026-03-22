class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int target  = 0;
        vector<vector<int>> ans;
        while(i<n) {
            int j = i+1;
            int k = n-1;
            int need = target-nums[i];
            
            while(j<k) {
                if(need == nums[j]+nums[k]) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(k>j && nums[k]==nums[k+1]) k--;
                    while(j<k && nums[j]==nums[j-1]) j++;


                }
                else if(nums[j]+nums[k] > need) {
                    k--;
                    while(k>j && nums[k]==nums[k+1]) k--;
                }
                else if(nums[j]+nums[k] < need) {
                    j++;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }
            }


            i++;
            while(i<n && nums[i]==nums[i-1]) i++;
        }

        return ans;
    }
};