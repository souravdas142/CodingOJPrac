class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       unordered_map<int,int> ump;
       int n = nums.size();
       int cnt = 0;
       int j = 0;
       int sum = 0;
       while(j<n) {

            sum+=nums[j];
            if(sum==goal) cnt++;
            int need = sum-goal;
            if(ump.count(need)==1) {
                cnt+=ump[need];
            }


            ump[sum]++;

            j++;
       } 

       return cnt;

    }
};