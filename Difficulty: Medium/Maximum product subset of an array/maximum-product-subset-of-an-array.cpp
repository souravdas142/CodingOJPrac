// User function Template for C++
#define ll long long
#define mod ((ll)(1e9+7))
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int n = arr.size();
        if(n==1 && arr[0]<0) return arr[0];
        int mini = INT_MIN;
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            if(arr[i]<0) {
                cnt++;
                mini = max(mini,arr[i]);
                
            }
        }
        
        
        
        long long prod = 1;
        bool isok = false;
        for(int i = 0;i<n;i++) {
            if(arr[i]==0) continue;
            if(cnt&1 && mini == arr[i] && mini<0) {
                mini = 0;
                continue;
            }
            prod = ((prod*arr[i]) % mod);
            isok = true;
        }
        if(!isok) return 0;
        return prod;
        
    }
};
