#define ll long long
#define mod ((int)(1e9+7))

class Solution {
  public:
    int maxValue(vector<int> &arr) {
        // Complete the function
        sort(arr.begin(),arr.end());
        ll ans = 0;
        int n = arr.size();
        for(int i = n-1;i>=0;i--) {
            ans = (ans + 1LL * i * arr[i])%mod;
        }
        return ans;
    }
};