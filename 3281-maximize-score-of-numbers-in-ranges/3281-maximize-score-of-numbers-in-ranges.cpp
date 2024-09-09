#define ll long long
class Solution {
private:
    ll checkPossible (vector<int>& start,ll d,ll n,ll mid) {
        ll m = n;
        m--;
        ll i = 1;
        ll lastpos_llerm = start[0];
        while(i<n) {
            ll nxtPossible = max(lastpos_llerm+mid,(ll)start[i]);
            if((nxtPossible>start[i]+d)) {
                return false;
            }
            lastpos_llerm = nxtPossible;

            i++;
        }

        return true;
    }
public:
    ll maxPossibleScore(vector<int>& start, ll d) {

        sort(start.begin(),start.end());
        ll n = start.size();
        ll low = 0, high = start[n-1] + d;

        while(low<=high) {

            ll mid = low+(high-low)/2;
            if(checkPossible(start,d,n,mid)) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return high;
        
    }
};