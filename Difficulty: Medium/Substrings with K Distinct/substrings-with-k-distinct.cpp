
#define ll long long


class Solution {
  public:
    ll solve(string& s, int k) {
        ll ans = 0;
        
        int n = s.size();
        int j = 0, i = 0;
        vector<int> ump(26,0);
        int cnt = 0;
        
        while(j<n) {
            
            if(ump[s[j]-'a']==0) {
                cnt++;
                
            };
            
            ump[s[j]-'a']++;
            
            while(cnt>k) {
                ump[s[i]-'a']--;
                if(ump[s[i]-'a']==0) {
                    cnt--;
                }
                i++;
                
            }
            
            ans += (j-i+1);
            
            
            
            j++;
        }
        
        
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here
        
        ll ans1 = solve(s,k);
        ll ans2 = solve(s,k-1);
        return (ans1-ans2);
        
    }
};