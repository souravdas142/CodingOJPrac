class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        vector<int> comp(high-low+1,0);
        
        int k = high-low+1;
        int n = arr.size();
        
        for(auto &e: arr) {
            int x = e-low;
            if(x>=0 && x<k) {
                comp[x]=1;
            }
        }
        int i =0;
        vector<int> ans;
        while(i<k) {
            if(!comp[i]) {
                ans.push_back(i+low);
            }
            i++;
        }
        
        return ans;
    }
};