class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int sz = nums.size();
        int element = nums[0];
        int cnt = 1;

        int i = 1;
        while(i<sz) {
            if(element==nums[i]) {
                cnt++;
            }
            else {
                cnt--;
                if(cnt==0) {
                    element = nums[i];
                    cnt=1;
                }
            }

            i++;
        }
        return element;
        
    }
};