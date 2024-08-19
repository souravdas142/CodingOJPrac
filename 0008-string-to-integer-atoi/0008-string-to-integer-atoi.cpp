class Solution {
public:
    int myAtoi(string s) {

        // ignore leading whitespace and leading zeros
        int len = s.length();
        int i = 0; int sign = 1;
        while(i<len && s[i]==' ') i++;
        if(i<len && s[i]=='-') {
            sign = -1;
            i++;
        }
        else if(i<len && s[i]=='+') {
            i++;
        }
        while(i<len && s[i]=='0') i++;
        int j = i;
        long ans = 0;
        cout<<i<<endl;
        while(i<len && s[i]>='0' && s[i]<='9') {

            ans=((ans*10)+(s[i]-'0'));
            cout<<ans<<endl;
            if(ans>INT_MAX && sign==-1) return INT_MIN;
            else if(ans>INT_MAX && sign==1) return INT_MAX;

            i++;
        }

        return (ans*sign);

        


        
    }
};