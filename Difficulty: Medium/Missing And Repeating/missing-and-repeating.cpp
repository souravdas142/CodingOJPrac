//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int>& arr, int n) {
        // code here
        unordered_map<int,int> ump;
        int i = 1;
        
        int sz= arr.size();
        sort(arr.begin(),arr.end());
        int dup = 0,mis = 0;

        while(i<sz) {
            
            if(arr[i]==arr[i-1]) {
                dup = arr[i];
            }
            if(arr[i]-arr[i-1]>1) {
                mis = arr[i]-1;
            }
            i++;
        }
        if(mis==0) {
            if(arr[0]>1) {
                mis = 1;
            }
            else {
                mis = sz;
            }
        }
        return {dup,mis};
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends