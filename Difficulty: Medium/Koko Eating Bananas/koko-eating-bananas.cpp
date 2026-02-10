class Solution {
  public:
  
    bool check(vector<int>& arr, int n, int k, int s) {
        int ans = 0;
        
        for(auto& e: arr) {
            ans+= ceil((float)e/(float)s);
            if(ans>k) return false;
        }
        return true;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int high = INT_MIN;
        int n = arr.size();
        for(auto& e: arr) {
            high = max(high,e);
        }
        
        while(low<high) {
            int mid = low+(high-low)/2;
            
            if(check(arr,n,k,mid)) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        
        return high;
    }
};