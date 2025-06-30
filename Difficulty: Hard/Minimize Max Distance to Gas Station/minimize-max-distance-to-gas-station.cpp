class Solution {
  public:
    bool checkPossible(vector<int>& stations, int maxStations, double dist) {
        int station = 0; 
        
        int n =stations.size();
        
        for(int i = 1;i<n;i++) {
            long double diff = stations[i]-stations[i-1];
            station = station+ floor(diff/dist);
            if(station>maxStations) return false;
            
        }
        return true;
    }
    
    /*
    
    
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
    
    */
    
    
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        
        long double low = INT_MAX;
        long double high = INT_MIN;
        int n = stations.size();
        
        for(int i = 1;i<n;i++) {
            
            //low = min((int)low,stations[i]-stations[i-1]);
            high = max(high,((long double)stations[i]-stations[i-1]));
        }
        
        low = 0;
        
        double ans = high;
        
        while(high-low>1e-7) {
            
            double mid = low+(high-low)/2.0f;
            
            //cout<<mid<<endl;
            
            if(checkPossible(stations,k,mid)) {
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