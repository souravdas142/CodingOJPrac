class Solution {
public:
    int jump(vector<int>& nums) {

        int jump = 0;
        int l = 0, r = 0;
        int n = nums.size();

        while(r<n-1) {
            int maxi = INT_MIN;
            while(l<=r) {
                maxi = max(maxi,l+nums[l]);
                l++;
            }
            r = maxi;
            jump++;
            
        }
        return jump;
        
    }
};