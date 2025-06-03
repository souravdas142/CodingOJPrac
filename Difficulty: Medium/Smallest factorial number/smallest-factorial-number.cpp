
class Solution {
  public:
    bool is_possible(int x, int n) {
        // n = x/5 + x/(5^2)... 0
        int ans = 0;
        int p = 5;
        while(x/p!=0) {
            ans+=(x/p);
            p *= 5;
            if(ans>=n) return true;
        }
        if(ans>=n) return true;
        return false;
    }
    int findNum(int n) {
        // complete the function here
        int low = 1;
        int high = INT_MAX;
        int ans = 0;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(is_possible(mid,n)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};