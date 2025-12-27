class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> ump;
        for(int i = n-1;i>=0;i--) {
            if(ump.find(nums[i])!=ump.end()) {
                int x = (i/3)+1;
                return x;
            }
            else {
                ump[nums[i]] = false;
            }
        }
        return 0;
    }
};