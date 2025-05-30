class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        int m = b.size();
        if(n>m) return kthElement(b,a,k);
        
        int low = max(0,k-m), high = min(k,n);
        
        int med = k;
        
        while(low<=high) {
            int mid1 = low+(high-low)/2;
            int mid2 = med-mid1;
            
            int l1 = (mid1-1<0)?INT_MIN:a[mid1-1];
            int l2 = (mid2-1<0)?INT_MIN:b[mid2-1];
            int r1 = (mid1<n)?a[mid1]:INT_MAX;
            int r2 = (mid2<m)?b[mid2]:INT_MAX;
            
            if(l1>r2) {
                high = mid1-1;
            }
            else if(l2>r1) {
                low = mid1+1;
            }
            else {
                return max(l1,l2);
            }
            
            
        }
        return 0;
        
    }
};