//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    
	    //cout<<endl;
	    //for(int i = 0;i<n;i++) cout<<arr[i]<<" ";
	    //cout<<endl;
	    
	    int cnt = 0;
	    for(int j = n-1;j>=0;j--) {
	        int target = arr[j];
	        int i = 0,k = j-1;
	        while(i<k) {
	            if(arr[i]+arr[k]==target) {
	                cnt++;
	                i++;k--;
	            }
	            else if(arr[i]+arr[k]>target) {
	                k--;
	            }
	            else if(arr[i]+arr[k] < target) {
	                i++;
	            }
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends