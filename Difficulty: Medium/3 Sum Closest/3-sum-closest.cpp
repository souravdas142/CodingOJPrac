// User function Template for C++

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        // code here
        vector<int>& nums = arr;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        
        int ans = 0;
        for(int i = 0 ;i<n;i++) {
            int  j = i+1, k = n-1;
            while(j<k) {
                int sum = nums[i]+nums[j]+nums[k];
                

                if(abs(target-sum)<diff) {
                    diff = abs(target-sum);
                    ans = sum;
                }

                if(diff==abs(target-sum)) {
                    ans = max(ans,sum);
                }
                
                if(sum>target) {
                    k--;
                }
                else {
                    j++;
                }
                
                
                
            }   
        }

        return ans;
    }
};