// User function Template for C++

class Solution {
  public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n) {
        // Write your code here
        
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        int i = 0, j = 0;
        int h = 1, v = 1;
        int ans = 0;
        
        while(i<m-1 && j<n-1) {
            if(x[i]>y[j]) {
                ans = ans + (x[i]*v);
                i++;
                h  = h+1;
            }
            else {
                ans = ans + (y[j]*h);
                j++;
                v = v+1;
            }
        }
        while(i<m-1) {
            ans = ans+(v*x[i]);
            i++;
        }
        while(j<n-1) {
            ans = ans+(h*y[j]);
            j++;
        }
        return ans;
        
    }
};
