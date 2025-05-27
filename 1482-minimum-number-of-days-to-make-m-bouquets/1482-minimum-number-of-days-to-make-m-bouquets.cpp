class Solution {
public:
    bool check_possible(vector<int>& days, int ans,int m, int k) {
        int n = days.size();
        int cnt = 0;
        int i = 0;
        while(i<n) {
            int dys = days[i];
            
            if(ans>=dys) {
                cnt++;
                if(cnt>1 && ans<days[i-1]) break;
                if(cnt==k) {
                    m--;
                    cnt=0;
                }
                if(m==0) return true;
            }
            i++;
        }

        return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n =bloomDay.size();
        int high = INT_MIN;
        int low = INT_MAX;
        for(auto dy:bloomDay) {
            high = max(high,dy);
            low = min(low,dy);

        }
        bool is_possible = false;
        while(low<high) {
            int mid = low+(high-low)/2;
            
            if(check_possible(bloomDay,mid,m,k)) {
                high = mid;
                is_possible = true;
            }
            else {
                low = mid+1;
            }
        }
        if(check_possible(bloomDay,high,m,k)) {
            return high;
        }
        return -1;
        
        
    }
};