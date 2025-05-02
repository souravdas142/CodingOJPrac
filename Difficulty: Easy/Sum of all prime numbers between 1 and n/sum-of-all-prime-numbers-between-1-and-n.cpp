//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

//#define maxl (1e5 + 1)

class Solution {
  public:
    int prime_Sum(int n) {
        
        int maxl = n;
        // Code here
        vector<int> sieve((maxl>>5)+1,0);
        // 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0
        
        
        int block = 0, pos = 0;
        
        
        int sum = 0;
        if(n>=2) sum=2;
        
        for (int i = 3;i<=maxl;i+=2) {
            if(!(sieve[i>>5]&(1<<(i&31)))) {
                sum+=i;
                for(long long j = 1LL *i*i;j<=maxl;j+=(i<<1)) {
                    block = j>>5;
                    pos = j&31;
                    sieve[block]|=(1<<pos);
                }
            }
            
        }
        return sum;
        
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.prime_Sum(n);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends