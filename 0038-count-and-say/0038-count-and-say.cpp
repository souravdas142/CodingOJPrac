class Solution {

    void solve(string s, int n,int inc, string &ans) {
        if(inc>=n-1) {
            ans = s;
            return;
        }
    
        string res = "";
        int sz = s.length();
        int cnt =1;
        char curch = s[0];
        for(int i = 1;i<sz;i++) {

            if(s[i]==s[i-1]) cnt++;
            else {
                res+=to_string(cnt);
                res.push_back(curch);
                curch = s[i];
                cnt=1;
            } 

        }

        res+=to_string(cnt);
        res.push_back(curch);
        cout<<s<<" = "<<res<<endl;
        solve(res, n,inc+1,ans);

    }
public:
    string countAndSay(int n) {

        string s = to_string(1);
        if(n==1) return s;
        string ans = "";
        int inc = 0;

        solve(s,n,inc,ans);


        return ans;
        
    }
};