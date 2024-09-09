class Solution {
private:
    bool isPossible(vector<int>& buspos,int n,int m, int possibleAns) {
        int i = 1;
        int lastPos = 0;
        m--;
        while(i<n) {

            if(buspos[i]-buspos[lastPos]>=possibleAns) {
                m--;
                lastPos = i;
                if(m==0) return true;
            }

            i++;
        }

        return false;
    }
public:
    int maxDistance(vector<int>& buspos, int m) {

        sort(buspos.begin(),buspos.end());
        int n  = buspos.size();
        int low = buspos[0], high = buspos[n-1];

        while(low<=high) {
            int mid = low+(high-low)/2;

            if(isPossible(buspos,n,m,mid)) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }

        }
        return high;
        
    }
};