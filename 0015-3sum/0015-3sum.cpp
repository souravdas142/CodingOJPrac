#define vvi vector<vector<int> > 
#define vi vector<int>
#define si set<vi> 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        int target = 0;
        sort(nums.begin(),nums.end());
        vvi ans;
        // lets set the first pointer
        // but first lets set traversing method
        int j = 0;
        while(j<sz) {

            /// lets set the second pointer to j+1
            int i = j+1;
            /// lets set the 3rd pointer to the last
            int k = sz-1;
            while(i<k) {
                int get = nums[j]+nums[i]+nums[k];
                if(get == target) {
                    ans.push_back(vector<int>({nums[i],nums[j],nums[k]}));
                    i++;k--;
                    
                    while(i<k && nums[i-1]==nums[i]) i++;
                    while(i<k && nums[k+1]==nums[k]) k--;
                }
                else if(get>target) {
                    k--;
                    while(i<k && nums[k+1]==nums[k]) k--;
                }
                else if(get<target){
                    i++;
                    while(i<k && nums[i-1]==nums[i]) i++;
                }
            }

            j++;
            while(j<sz && nums[j-1]==nums[j]) j++;

        }

        return ans;
    }
};