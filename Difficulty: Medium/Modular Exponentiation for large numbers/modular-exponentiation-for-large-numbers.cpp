//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution {
  public:
    long long int PowMod(long long int x, long long int n, long long int M) {
        // Code here
        ll ans = 1;
        while(n!=0) {
            
            if(n&1) {
                ans = (ans*x)%M;
            }
          
                x = (x*x)%M;
            
            n=n>>1;
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends