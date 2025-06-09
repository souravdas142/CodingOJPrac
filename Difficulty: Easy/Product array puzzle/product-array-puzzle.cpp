// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        long long prod = 1;
        int cntz = 0;
        int zpos = -1;
        int n = arr.size();
        
        for(int i = 0;i<n;i++) {
            if(arr[i]) {
                prod*=arr[i];
            }
            else {
                cntz++;
                zpos = i;
                if(cntz>1) break;
            }
        }
        
        vector<int> ans(arr.size(),0);
        
        if(cntz > 1) return ans;
        if(cntz==1) {
            ans[zpos] = prod;
            return ans;
        }
        
        for(int i = 0;i<n;i++) {
            ans[i] = prod/arr[i];
        }
        
        
        
        return ans;
        
        
    }
};
