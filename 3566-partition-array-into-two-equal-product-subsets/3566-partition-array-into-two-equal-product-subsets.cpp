class Solution {
public:
    bool check(vector<int>& nums, int n, int index, long long prod, vector<int>& ans,long long target) {
        if(prod>=target || index>=n) {

            if(prod!=target) return false;
            
            long long prod2 = 1;
            for(int i = 0;i<n;i++) {
                if(ans[i]==0) {
                    prod2*=nums[i];
                }
                if(prod2>target) return false;
            }
            if(prod2==target)return true;
            return false;
        }


        // take
        ans[index] = 1;
        prod*=nums[index];
        bool take = check(nums,n,index+1,prod,ans,target);
        if(take == true) return true;
        ans[index] = 0;
        prod = prod/nums[index];

        // not take

        bool not_take = check(nums,n,index+1,prod,ans,target);
        if(not_take == true) return true;
        
        return take&&not_take;


    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {

        int n = nums.size();
        for(int i = 0;i<n;i++) {
            if(target%nums[i]!=0) return false;
        }

        int index = 0;
        vector<int> ans(n,0);
        int prod = 1;

        return check(nums,n,index,prod,ans,target);
        
    }
};