class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        long long result  = mp[s[0]];
        cout<<"result = "<<result<<"\n";
        for(int i = 1;i<s.length();i++) {
                result += mp[s[i]];
                if((s[i]=='V' && s[i-1]=='I') || (s[i]=='X' && s[i-1]=='I')) {
                    result = result-mp[s[i-1]]-mp[s[i]];
                    if(s[i]=='V') result+=4;
                    if(s[i]=='X') result+=9;
                }
                else if((s[i]=='L' && s[i-1]=='X') || (s[i]=='C' && s[i-1]=='X')) {
                    result = result-mp[s[i-1]]-mp[s[i]];
                    if(s[i]=='L') result+=40;
                    if(s[i]=='C') result+=90;
                }
                else if((s[i]=='D' && s[i-1]=='C') || (s[i]=='M' && s[i-1]=='C')) {
                    result = result-mp[s[i-1]]-mp[s[i]];
                    if(s[i]=='D') result+=400;
                    if(s[i]=='M') result+=900;
                }
                cout<<"result = "<<result<<"\n";

        }
        return result;

        
    }
};