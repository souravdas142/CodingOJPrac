class Solution {

public:
    bool check_possible(int mid, vector<int>& piles, int h) {
        int n = piles.size();
        int i = 0;
        long long cnt=0;
        while(i<n) {
            long long time = ceil((double)piles[i] / mid);

            //cout<<"piles["<<i<<"] = "<<piles[i]<<" / "<<mid<<" = "<<time<<endl;
            cnt+=time;
            i++;
        }
        if(cnt>h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        int high = 0;
        for(auto e:piles) {
            high = max(high,e);
        }
        int low = 1;

        while(low<high) {
            int p_ans = low+(high-low)/2;
            
            if(check_possible(p_ans,piles,h)) {
                high = p_ans;
            }
            else {
                low = p_ans+1;
            }
        }

        return high;
        
    }
};