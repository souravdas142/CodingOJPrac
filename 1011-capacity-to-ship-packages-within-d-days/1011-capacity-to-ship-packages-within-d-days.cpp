class Solution {
public:
    bool is_possible(vector<int>& weights,int ship, int days) {
        int i = 0;
        int n = weights.size();
        long long wt = 0;
        
        while(i<n) {
            if(wt+weights[i]<=ship) {
                wt+=weights[i];
                
            }
            else {
                days--;
                if(days==0 && i<n) return false;
                wt = weights[i];
            }
            i++;
        }
        if(wt) days--;
        if(days<0) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int high = 0;
        int low = INT_MIN;
        for(auto e: weights) {
            high+=e;
            low = max(low,e);
        }

        while(low<high) {
            int mid = low+(high-low)/2;

            if(is_possible(weights,mid,days)) {
                high = mid;
            }
            else {
                low = mid+1;
            }

        }
        return high;
    }
};