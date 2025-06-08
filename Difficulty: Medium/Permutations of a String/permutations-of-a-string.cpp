
class Solution {
  public:
  void solve(string& s,int sz, int index, set<string>& ans) {
      if(index>=sz) {
         ans.insert(s);
         return;
      }
      
      for(int j = index;j<sz;j++) {
          if(j>index && s[j]==s[j-1]) continue;
          swap(s[j],s[index]);
          solve(s,sz,index+1,ans);
          swap(s[j],s[index]);
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        int sz = s.length();
        int index = 0;
        set<string> ans;
        
        solve(s,sz,index,ans);
        vector<string> ans2(ans.begin(),ans.end());
        return ans2;
    }
};


