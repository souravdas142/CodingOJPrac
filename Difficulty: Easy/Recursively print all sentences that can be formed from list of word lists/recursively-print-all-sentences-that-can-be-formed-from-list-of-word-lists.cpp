// User function Template for C++
#define vvs vector<vector<string> >
#define vs vector<string>
class Solution {
  public:
  
    void solve(vvs& list, int n, vvs& ans, vs res,string s, int index) {
        if(index>=n) {
            ans.push_back(res);
            return;
        }
        vs partsOfSpeech = list[index];
        int k = partsOfSpeech.size();
        for(int i = 0;i<k;i++) {
            res.push_back(partsOfSpeech[i]);
            solve(list,n,ans,res,s,index+1);
            res.pop_back();
        }
    }
  
    vector<vector<string>> sentences(vector<vector<string>>& list) {
        // Write your code here
        vvs ans;
        vs res;
        string s="";
        int index = 0;
        int n = list.size();
        solve(list,n,ans,res,s,index);
        return ans;
    }
};
