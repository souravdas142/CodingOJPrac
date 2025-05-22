// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        long long maxprefix = 1;
        long long maxsufix = 1;
        long long maxi = INT_MIN;
        
        int i = 0;
        while(i<n) {
            maxprefix = maxprefix*arr[i];
            
            maxsufix = maxsufix*arr[n-i-1];
            
            maxi = max(maxi,max(maxprefix,maxsufix));
            if(maxprefix==0) maxprefix = 1;
            if(maxsufix ==0) maxsufix = 1;
            i++;
            
        }
        
        return maxi;
        
    }
};