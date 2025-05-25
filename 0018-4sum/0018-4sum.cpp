class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
    vector<vector<int> > ans;
    int sz = nums.size();
    int i = 0,j = 1, k = 2, l = sz-1;
    for(int i = 0;i<sz;) {
        
        for(int j = i+1;j<sz;) {

            int k = j+1,l = sz-1;
            
            while(k<l) {
            
                long long sum = nums[i]+nums[j];
                sum+=nums[k]+nums[l];
                
                if(sum == target) {
                  vector<int> tmp = {nums[i], nums[j], nums[k], nums[l]};
                  ans.push_back(tmp);
                  k++;l--;
                  while(k<l && nums[k]==nums[k-1]) k++;
                  while(k<l && nums[l]==nums[l+1]) l--;
                }
                else if(sum<target) {
                    k++;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    
                }
                else if(sum>target) {
                    l--;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }
            j++;
            while(j<sz && nums[j]==nums[j-1]) j++;
        }
        i++;
        while(i<sz && nums[i]==nums[i-1]) i++;
        
    }

    return ans; 
    }
};