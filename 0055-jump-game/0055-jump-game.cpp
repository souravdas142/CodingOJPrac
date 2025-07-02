class Solution {
public:
    bool canJump(vector<int>& nums) {

        
        int maxRight = 0;
        int n = nums.size();
        if(n<=1) return true;
        for(int i = 0;i<n;i++) {
            if(i>=maxRight) return false;
            maxRight = max(maxRight,nums[i]+i);
            
        }

        return true;
        
    }
};