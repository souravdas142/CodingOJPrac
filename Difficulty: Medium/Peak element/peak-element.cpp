class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        int prev = INT_MIN;
        int n = arr.size();
        if(n==1) return 0;
        for(int i  = 0;i<n-1;i++) {
            
            if(arr[i]>prev && i+1<n && arr[i]>arr[i+1]) return i;
            
            prev = arr[i];
        }
        
        return (arr[n-1]>arr[n-2])?n-1:n;
        
    }
};