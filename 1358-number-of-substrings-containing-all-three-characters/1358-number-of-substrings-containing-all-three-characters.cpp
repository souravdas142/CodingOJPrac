class Solution {
public:
    int numberOfSubstrings(string s) {

        int n  = s.length();
        int i = 0,j = 0;
        vector<int> mp(3,0);
        int ans = 0;
        while(j<n) {
            if(s[j]-'a' >=0 && s[j]-'a'<3) mp[s[j]-'a']++;
            if(mp[0]>=1 && mp[1]>=1 && mp[2]>=1) {
                ans+=(n-1-j);
            }
            while(mp[0]>=1 && mp[1]>=1 && mp[2]>=1) {
                ans++;
                if(s[i]-'a' >=0 && s[i]-'a'<3) mp[s[i]-'a']--;
                i++;

            }
            j++;
        }
        return ans;
    }
};