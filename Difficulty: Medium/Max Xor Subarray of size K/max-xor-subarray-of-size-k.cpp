class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int maxi = INT_MIN;
        int xored = 0;
        int j = 0;
        int i = 0;
        int n = arr.size();
        while(j<n) {
            
            while(j<k) {
                xored^=arr[j];
                j++;
                if(j==k) {
                    maxi = max(maxi,xored);
                    break;
                }
               
                
            }
            if(j>=n) break;
            
            xored^=arr[j];
            xored^=arr[i];
            maxi = max(maxi,xored);
            i++;
            j++;
            
        }
        return maxi;
    }
};