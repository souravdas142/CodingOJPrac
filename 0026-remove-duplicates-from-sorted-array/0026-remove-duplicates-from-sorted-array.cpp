class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int num = nums[0];
        int n = nums.size();
        int total=1;
        int places = 0;


        for(int i = 1;i<n;i++) {
            if(nums[i]!=nums[places]) {
                nums[places+1] = nums[i];
                places++;
                total++;
            }
        }

        return total;

        
    }
};