class Solution {
    public int minJumps(int[] arr) {
        // code here
        int n = arr.length;
        int i = 0;
        int l = 1;
        int r = arr[i];
        int steps = 1;
        if(r>=n-1) return steps;
        if(r==0) return -1;
        
        while(r<=n) {
            

            int nextPos = l;
            while(l<=r && l<n) {
                if(l+arr[l]>=nextPos+arr[nextPos]) {
                    nextPos = l;
                }
                l++;
            }
            
            r = Math.max(r,nextPos+arr[nextPos]);
            if(r<l) return -1;
            steps+=1;
            if(r>=n-1) return steps;
            
            
            
            
            
        }
        
        return steps;
        
    }
}