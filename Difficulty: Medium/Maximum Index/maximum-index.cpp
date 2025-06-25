class Solution {
  public:
    // arr[]: input array
    // Function to find the maximum index difference.
    int maxIndexDiff(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int> prefix(n,-1);
        prefix[0] = arr[0];
        
        for(int i = 1;i<n;i++) {
            prefix[i] = min(prefix[i-1],arr[i]);
        }
        
        int l = n-1, r = n-1;
        int maxDiff = 0;
        
        while(l>=0 && r>=0) {
            if(prefix[l]<=arr[r]) {
                maxDiff = max(maxDiff,r-l);
                l--;
            }
            else {
                r--;
            }
            
        }
        return maxDiff;
    }
};