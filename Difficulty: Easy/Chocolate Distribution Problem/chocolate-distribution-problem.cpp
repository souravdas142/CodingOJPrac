class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        
        sort(a.begin(),a.end());
        int j = m-1;
        int i = 0;
        int ans = INT_MAX;
        
        int n = a.size();
        while(j<n) {
            ans = min(ans,(a[j]-a[i]));
            j++;
            i++;
        }
        
        return ans;
        
    }
};