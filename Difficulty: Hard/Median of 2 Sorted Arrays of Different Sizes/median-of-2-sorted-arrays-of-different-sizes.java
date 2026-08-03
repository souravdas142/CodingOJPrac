class Solution {
    public double medianOf2(int a[], int b[]) {
        // Code Here
        int n = a.length;
        int m = b.length;
        if(m>n) {
            return medianOf2(b,a);
        }
        
        int med = (n+m+1)/2;

        
        int low = 0;
        int high = Math.min(med,m);
        double ans = 0.0f;
        
        while(low<=high) {
            int mid1 = low+(high-low)/2;
            int mid2 = med-mid1;
            
            int l1 = (mid2-1<0)?Integer.MIN_VALUE:a[mid2-1];
            int l2 = (mid1-1<0)?Integer.MIN_VALUE:b[mid1-1];
            int r1 = (mid2>=n)?Integer.MAX_VALUE:a[mid2];
            int r2 = (mid1>=m)?Integer.MAX_VALUE:b[mid1];
            
                        
           
            
            if(l2>r1)  {
                high = mid1-1;
            }
            else if(l1>r2) {
                low = mid1+1;
            }
            else if(l1<=r2 && l2<=r1) {
                double x = Math.max(l1,l2);
                double y = Math.min(r1,r2);
                
                if((m+n)%2==1) return x;
                ans = (x+y)/2.0f;
                break;
            }
            
        }
        
        
        return ans;
    }
}