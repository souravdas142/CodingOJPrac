class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        unordered_map<int,int> prefixSum;
        int cnt = 0;
        int j = 0;
        int sum = 0;
        while(j<sz) {

            
            sum+=nums[j];
            if(sum == k) cnt++;
            int need = sum-k;
            if(prefixSum.count(need)) {
                cnt+=prefixSum[need];
            }
           // else if(!prefixSum.count(need)) {
                prefixSum[sum]++;
           // }

            j++;
        }

        return cnt;
        
    }
};