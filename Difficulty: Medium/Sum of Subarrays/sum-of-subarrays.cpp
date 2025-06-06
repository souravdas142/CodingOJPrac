// User function template for C++

#define MOD 1000000007
#define ll long long

class Solution {
  public:
    long long subarraySum(vector<int>& arr) {
        
        ll n = arr.size();
        ll i = 0;
        ll sum = 0;
        ll total_sum = 0;
        ll prev_sum = 0;
        
        while(i<n) {
            sum = (prev_sum+(arr[i]*(i+1)))%MOD;
            total_sum = (total_sum + sum) % MOD;
            prev_sum = sum;
            i++;
        }
        
        return (total_sum%MOD);
        
    }
};