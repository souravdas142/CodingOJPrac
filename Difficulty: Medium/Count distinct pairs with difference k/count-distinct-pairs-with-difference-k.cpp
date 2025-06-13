class Solution {
  public:
    int TotalPairs(vector<int> nums, int k) {
        // Code here
        
        unordered_map<int,int> ump;
        
        int j = 0;
        
        int n = nums.size();
        
        int ans = 0;
        
        set<vector<int> > st;
        
        while(j<n) {
            int need = k+nums[j];
            if(ump.find(need) != ump.end()) {
                vector<int> tmp = {nums[j],need};
                sort(tmp.begin(),tmp.end());
                st.insert(tmp);
            }
            need = nums[j] - k;
            if(ump.find(need) != ump.end()) {
                ans+=ump[need];
                vector<int> tmp = {nums[j],need};
                sort(tmp.begin(),tmp.end());
                st.insert(tmp);
            }
            ump[nums[j]]++;
            j++;
        }
        
        return st.size();
        
    }
};