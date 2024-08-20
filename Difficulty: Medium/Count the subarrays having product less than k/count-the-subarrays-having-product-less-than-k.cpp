//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

#define ll long long
class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        int i = 0,j = 0;
        ll ans = 0;
        ll prod = 1;
        while(j<n) {
            prod*=nums[j];
            while(i<=j && prod>=k) {
                prod=prod/nums[i];
                i++;
            }
            ll len = (j-i)+1;
            ans+=len;
            
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends