class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++) {
            int cntz = 0, cntone = 0;
            for(int j = i;j<n;j++) {
                if(nums[j]==0) cntz++;
                else cntone++;
                if(cntz==cntone) {
                    ans = max(ans,cntz+cntone);
                }
            }
        }
        return ans;
        
    }
};