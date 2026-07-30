class Solution {
    public int maxOnes(int arr[], int k) {
        // code here
        
        int ans = 0;
        
        int n = arr.length;
        
        int j = 0;
        int i = 0;
        int cnt = 0;
        
        while(j<n) {
            if(arr[j]==0) {
                cnt++;
            }
            
            if(cnt>k) {
                if(arr[i]==0) {
                    cnt--;
                }
                i++;
            }
            
            if(cnt<=k) {
                ans = Math.max(ans,j-i+1);
            } 
            j++;
        }
        
        return ans;
        
    }
}