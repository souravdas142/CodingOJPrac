class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        vector<int> cntd(4);
        int n = arr.size();
        
        int j = 0;
        while(j<n) {
            cntd[((arr[j]/5)-1)]++;
            int ferot = arr[j]-5;
          
            if(ferot>=10 && cntd[1]>0) {
                cntd[1]--;
                ferot-=10;
            }
            if(ferot<=5*cntd[0]) {
                cntd[0]-=(ferot/5);
                ferot = 0;
            }
            
            if(ferot>0) return false;
            j++;
        }
        return true;
    }
};