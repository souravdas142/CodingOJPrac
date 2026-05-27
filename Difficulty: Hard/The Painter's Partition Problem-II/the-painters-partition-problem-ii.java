class Solution {
    public boolean check(int[] arr, int k, int time) {
        int n = arr.length;
        int i = 0;
        int sum = 0;
        int p  = 1;
        while(i<n) {
            if(arr[i]>time) return false;
            if(sum+arr[i]>time) {
                sum = 0;
                p += 1;
            }
            
            sum+=arr[i];
            
            if(p>k) return false;
            i++;
            
        }
        return true;
    }
    public int minTime(int[] arr, int k) {
        // code here
        int n = arr.length;
        int high = 0;
        for(int a: arr) high+=a;
        
        int low = 0;
        
        while(low<high) {
            int mid = low+(high-low)/2;
            if(check(arr,k,mid)) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        return high;
    }
}
