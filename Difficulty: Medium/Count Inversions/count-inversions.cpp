//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void merge(ll arr[],ll &ans,int left,int mid,int right) {
        
        ll a = left;
        ll lend = mid;
        ll rf = mid+1;
        
        vector<ll> res(right-left+1,0);
        ll resi = 0;
        
        while(left<=lend && rf<=right) {
            
            if(arr[left]>arr[rf]) {
                res[resi] = arr[rf];
                ans+= (lend-left+1);
                rf++; resi++;
            }
            else if(arr[left]<=arr[rf]) {
                res[resi]=arr[left];
                left++; resi++;
            }
        }
        while(left<=lend) {
            res[resi] = arr[left];
            resi++; left++;
        }
        while(rf<=right) {
            res[resi] = arr[rf];
            resi++;rf++;
        }
        for(ll x:res) {
            arr[a++] = x;
        }
    }
    
    void msort(ll arr[],ll &ans,int left,int right) {
        if(left>=right) return;
        ll mid = left+(right-left)/2;
        msort(arr,ans,left,mid);
        msort(arr,ans,mid+1,right);
        
        merge(arr,ans,left,mid,right);
        
    }
    
    long long int inversionCount(long long arr[], int n) {
        
        ll ans = 0;
        msort(arr,ans,0,n-1);
        return ans;
        
    }
};







//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends