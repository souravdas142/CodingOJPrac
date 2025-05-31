class Solution {
public:
    int myAtoi(string s) {

        int is_neg = 1;

        int i = 0;
        int n = s.length();

        while(s[i]==' ') {
            i++;
        }
        //cout<<i<<endl;
        if(s[i]=='-' || s[i]=='+') {
            if(s[i]=='-')
                is_neg = -1;
            i++;
        }
        
        //cout<<i<<is_neg<<endl;
        long long num = 0;

        while(s[i]>='0' && s[i]<='9') {
            num = (num*10)+(s[i]-'0');
            if(num*is_neg>INT_MAX) return INT_MAX;
            if(num*is_neg<INT_MIN) return INT_MIN;
            //cout<<"num = "<<num<<endl;
            i++;
        }

        

        return (num*is_neg);
        
    }
};