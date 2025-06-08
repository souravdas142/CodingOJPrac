#define ll long long

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        ll preProd = 1;
        ll sufProd = 1;

        ll ans = INT_MIN;
        
        for(int i = 0;i<n;i++) {

                preProd *= nums[i];

                sufProd *= nums[n-i-1];
            
                ans = max(ans,max(preProd,sufProd));
                if(preProd == 0) preProd = 1;
                if(sufProd == 0) sufProd = 1;
        }

        return ans;
        
    }
};