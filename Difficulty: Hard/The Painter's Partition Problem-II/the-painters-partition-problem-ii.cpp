// User function template for C++

class Solution {
  public:
    int is_possible(vector<int>& arr, int n, int maxTime,int painters) {
        int sum = 0;
        int painter = 1;
        for(int i = 0;i<n;i++) {
            sum+=arr[i];
            if(sum>maxTime) {
                painter++;
                sum = arr[i];
            }
            if(painter>painters) return false;
        }
        if(painter>painters) return false;
        return true;
    }
    
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int low = INT_MIN;
        int high = 0;
        int sum = 0;
        for(auto e: arr) {
            sum+=e;
            low = max(low,e);
        }
        high = sum;
        
        int ans = 0;
        
        while(low<=high) {
            int mid = low+(high - low)/2;
            
            if(is_possible(arr,n,mid,k)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        // return minimum time
        return ans;
    }
};