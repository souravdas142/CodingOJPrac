#define ll long long



class Solution {
  public:
  
  
    ll solve(vector<int>& arr,int n, int k) {
        
        int i = 0, j = 0;
        int cnt = 0;
        ll ans = 0;
        
        while(j<n) {
            if(arr[j]&1) cnt++;
            
            while(cnt>k) {
                if(arr[i]&1) cnt--;
                i++;
            }
            
            ans += (j-i+1);
            
            j++;
            
        }
        
        return ans;
    }
    
    
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        ll ans1 = solve(arr,n,k);
        ll ans2 = solve(arr,n,k-1);
        
        int ans = ans1-ans2;
        return ans;
    }
};