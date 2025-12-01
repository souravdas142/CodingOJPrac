class Solution {
public:
    bool check(int & ans, vector<int>& piles, int& h) {
        int maybe = 0;
        for(int &e: piles) {
            int x = ceil(((double)e)/((double)ans));
            maybe+=x;
            if(maybe>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = piles[0];
        for(auto& e: piles) high = max(e,high);

        while(low<high) {
            int mid = low+(high-low)/2;
            if(check(mid,piles,h)) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }

        return high;

    }
};