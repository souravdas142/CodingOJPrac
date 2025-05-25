class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        int i = 0,j = 0,k = 0,l = n-1;
        
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;

        while(i<n) {
            j=i+1;
            while(j<n) {
                k = j+1;
                
                
                l = n-1;

                while(k<l) {
                    long long tsum = nums[i]+nums[j];
                    tsum+=(nums[k]+nums[l]);
                  

                    if(tsum == target) {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(tsum<target) {
                        k++;
                        while(k<l && nums[k]==nums[k-1]) k++;
                    
                    }
                    else if(tsum>target) {
                        l--;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    
                   
                    

                }

                j++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i<n && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};