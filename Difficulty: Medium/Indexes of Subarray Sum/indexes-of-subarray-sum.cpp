class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        unordered_map<int,int> prefixSum;
        int sum = 0;
        
        
        int j  = 0;
        while(j<n) {
            sum+= arr[j];
            
            if(sum == target) return {1,j+1};
            
            int need = (sum-target);
            if(prefixSum.find(need)!=prefixSum.end()) {
                return {prefixSum[need]+1+1,j+1};
            }
            
            prefixSum[sum] = j;
            
            
            j++;
        }
        return {-1};
    }
};