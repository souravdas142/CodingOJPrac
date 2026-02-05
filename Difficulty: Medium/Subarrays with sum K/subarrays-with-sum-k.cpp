class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> ump;
        int n = arr.size();
        int j = 0;

        int sum = 0;
        int ans = 0;

        while(j<n) {
            sum+=arr[j];
            int x = sum-k;
            if(sum==k) ans++;
            if(ump.find(x)!=ump.end()) {
                ans+=ump[x];
            }
            
            ump[sum]++;
            j++;
        }
        
        return ans;
    
    }
};