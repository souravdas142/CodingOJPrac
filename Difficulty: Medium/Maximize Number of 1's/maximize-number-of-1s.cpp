class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        
        int ans = 0;
        
        int cnt = 0;
        
        while(j<n) {
            if(arr[j]==0) cnt++;
            
            if(cnt>k) {
                if(arr[i]==0) cnt--;
                i++;
            }
            
            if(cnt<=k)
                ans = max(ans,j-i+1);
            
            j++;
        }
        
        return ans;
    }
};
