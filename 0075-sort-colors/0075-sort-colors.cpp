class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cntz = 0,cnt1 = 0, cnt2 = 0;
        int sz = nums.size();

        for(int i= 0;i<sz;i++) {
            if(nums[i]==0) cntz++;
            else if(nums[i]==1) cnt1++;
            else if(nums[i]==2) cnt2++;
        }

        for(int i= 0;i<sz;i++) {
            if(cntz>0) {
                nums[i]=0;
                cntz--;
            }
            else if(cnt1>0) {
                nums[i]=1;
                cnt1--;
            }
            else if(cnt2>0) {
                nums[i]  = 2;
                cnt2--;
            }
        }
        
    }
};