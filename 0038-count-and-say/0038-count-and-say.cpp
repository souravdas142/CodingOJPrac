class Solution {
public:
    string rle(int k, int n, string ans) {
        //cout<<"k = "<<k<<endl;
        if(k>=n) {
            
            return ans;
        }

        int m = ans.size();
        int i = 0, j = 0;
        int cnt = 0;
        string res = "";
        while(j<m) {
            if(ans[i]==ans[j]) {
                cnt++;
            }
            else {
                res+=to_string(cnt);
                res+=ans[i];
                i = j;
                cnt = 1;
                
            }
            
            j++;
        }

        res+=(to_string(cnt));
        res+=ans[i];

        cout<<res<<endl;
        return rle(k+1,n,res);
    }
    string countAndSay(int n) {

        if(n==1) return "1";
      
        int i = 1;
        string ans = "1";

        return rle(i,n,ans);
        
    }
};