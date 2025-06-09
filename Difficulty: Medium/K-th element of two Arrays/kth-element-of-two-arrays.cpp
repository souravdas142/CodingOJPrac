

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        if(n>m) return kthElement(b,a,k);
        int total = n+m;
        
        
        //int low = 0, high = k;
        int low = max(0,k-m), high = min(k,n);
        int l1 = -1;
        int l2 = -1;
        int r1 = -1;
        int r2 = -1;
        int ans = 0;
        
        while(low<=high) {
            int mid = low+(high-low)/2;
            r2 = k - mid;
            r1 = mid;
            l1 = r1-1;
            
            l2 = r2-1;
            
            
            int aleft = (l1<0)?INT_MIN:a[l1];
            int bleft = (l2<0)?INT_MIN:b[l2];
            int aright = (r1<n)?a[r1]:INT_MAX;
            int bright = (r2<m)?b[r2]:INT_MAX;
            
            
            
            if(aleft>bright) {
                high = mid-1;
            }
            else if(bleft>aright) {
                low = mid+1;
            }
            
            else {
                ans = max(aleft,bleft);
                break;
            }
            
            
            
        }
        
        return ans;
        
    }
};