// User function Template for Java

class Solution {
    public double medianOf2(int a[], int b[]) {
        // Your Code Here
        
        int n = a.length;
        int m = b.length;
        if(n<m) {
            return medianOf2(b,a);
        }
        
        int mid = (n+m+1)/2;

        int low = 0;
        int high = Math.min(m,mid);
        double ans=0.0f;
        // debug(mid);
        // debug(high);
        
        while(low<=high) {
            int mid1 = low+(high-low)/2;
            int mid2 = mid-mid1;
            // debug(mid1);
            // debug(mid2);
            
            int l1 = (mid2-1<0)?Integer.MIN_VALUE:a[mid2-1];
            int l2 = (mid1-1<0)?Integer.MIN_VALUE:b[mid1-1];
            int r1 = (mid2>=n)?Integer.MAX_VALUE:a[mid2];
            int r2 = (mid1>=m)?Integer.MAX_VALUE:b[mid1];
            
          //  if(mid2==3) {
                // debug(l1);
                // debug(l2);
                // debug(r1);
                // debug(r2);
         //   }
            
            if(l1>r2) {
                low = mid1+1;
            }
            else if(l2>r1) {
                high = mid1-1;
            }
            else {
                double med = Math.max(l1,l2);
                if(((n+m)&1)==1) {
                    return med*1.0f;
                }
                med+=Math.min(r1,r2);
                ans = med/2.0f;
                break;
            }
            
            
        }
        
        return ans;
        
    }
}