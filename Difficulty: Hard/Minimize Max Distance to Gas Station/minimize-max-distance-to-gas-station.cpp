class Solution {
  public:
  
    bool is_possible(vector<int>& stations,int n, double maxdiff,int k) {
        int cnt = 0;
       
        for(int i = 1;i<n;i++) {
            long double diff = stations[i]-stations[i-1];
            
                cnt = cnt+floor((diff/maxdiff));
            
            if(cnt>k) return false;
        }
        if(cnt>k) return false;
        return true;
        
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        long double low = 0;
        long double high = INT_MIN;
        for(int j = 1;j<n;j++) {
            high = max(high,((long double)stations[j]-stations[j-1]));
        }
        long double ans = high;
        while(high-low>1e-7) {
            double mid = low+(high-low)/2.0;
            
            if(is_possible(stations,n,mid,k)) {
                ans = mid;
                high = mid;
            }
            else {
                low = mid;
            }
        }
        
        return round(ans*100)/100;
    }
};