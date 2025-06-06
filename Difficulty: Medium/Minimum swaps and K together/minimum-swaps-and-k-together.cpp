// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        
        int cnt =0;
        int maxCount = 0;
        int i = 0;
        int j = 0;
        int n = arr.size();
        
        while(j<n) {
            
            if(arr[j]<=k) {
                maxCount = max(maxCount,j-i+1);
                cnt++;
                
            }
            else {
                i = j+1;
                
            }
            j++;
        }
        
        return cnt-maxCount;
        
    }
};
