class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int ln = left.size();
        int rn = right.size();
        
        int maxl = INT_MIN;
        int minl = INT_MAX;
        
        for(auto& e: left) {
            maxl = max(maxl,e);
        }
        
        for(auto& e: right) {
            minl = min(minl,e);
        }
        
        return max(maxl-0,n-minl);
    }
};