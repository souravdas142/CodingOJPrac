class Solution {
public:
    string longestPrefix(string pat) {

        int len = pat.length();
        if(len == 1) return "";
        int maxPrefix = 0;
        vector<int> ft(len+1,0);

        for(int i = 2;i<=len;i++) {

            int j = ft[i-1];

            while(true) {

                if(pat[j]==pat[i-1]) {
                    ft[i] = j+1;
                    break;
                }
                else {

                    if(j==0) {
                        ft[i] = 0;
                        break;
                    }
                    
                    j = ft[j];
                
                }
            }
            maxPrefix = max(maxPrefix,ft[i]);
        }
        
        cout<<endl;
        for(auto i:ft) {
            cout<<i<<endl;
        }
        cout<<endl;
        

        return string(pat.begin(),pat.begin()+maxPrefix);
        
    }
};