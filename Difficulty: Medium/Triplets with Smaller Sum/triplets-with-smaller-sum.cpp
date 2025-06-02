class Solution {

  public:
    long long countTriplets(int n, long long x, long long arr[]) {
        // Your code goes here
        
        sort(arr,arr+n);
        long long  cnt = 0;
        for(int i = 0;i<n-2;i++) {
            int j = i+1,k = n-1;
            
            
            while(j<k) {
               int sum = arr[i]+arr[j]+arr[k];
               if(sum<x) {
                   cnt+=(k-j);
                   j++;
               }
               else {
                   k--;
               }
            }
        }
        
        return cnt;
        
    }
};