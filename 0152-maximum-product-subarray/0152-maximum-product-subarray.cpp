class Solution {
public:
     int maxProduct(vector<int>& nums) {

        int prod = nums[0];
        int sz = nums.size();
        

        int pref = 1,suf = 1;

        for(int i  = 0;i<sz;i++) {

            if(pref == 0) pref =1;
            if(suf == 0) suf =1;
            pref = pref*nums[i];
            suf = suf*nums[sz-i-1];
            prod = max(prod,max(pref,suf));

        }
        return prod;
        
    }
};