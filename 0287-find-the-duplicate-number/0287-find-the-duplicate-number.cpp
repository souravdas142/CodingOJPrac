class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_map<int,int> ump;
        int sz = nums.size();
        int i = 0;
        int ans = 0;
        while(i<sz) {

            ump[nums[i]]++;


            i++;
        }
        i = 0;
        while(i<sz) {
            if(ump[nums[i]]>1) {
                ans = nums[i];
                break;
            }


            i++;
        }
        return ans;
        
    }
};