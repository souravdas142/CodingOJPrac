class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int i = 1;
        
        int sum = arr[0];
        int ans = sum;
        
        while(i<n) {
            if(sum<0) sum = 0;
            sum+=arr[i];
            ans = max(ans,sum);
            i++;
        }
        
        return ans;
    }
};