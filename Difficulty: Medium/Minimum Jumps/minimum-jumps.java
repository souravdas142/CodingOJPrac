class Solution {
    public int minJumps(int[] arr) {
        // code here
        int n = arr.length;
        if(arr[0]==0) return -1;
        
        int l = 1;
        int r = arr[0];
        int ans = 1;
    
        if(r>=n-1) return ans;
        
        while(l<n) {
            
            int maxi = 0;
            
           
            while(l<=r) {
                if(l+arr[l]>maxi) {
                    maxi = l+arr[l];
                }
                l++;
            }
            
            r = maxi;
            
            if(r<l) return -1;
            
            if(r>=n-1) return ans+1;
            ans+=1;
            
            
        }
        return ans;
    }
}