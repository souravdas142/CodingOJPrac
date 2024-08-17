#define uvi unordered_map<int,vector<int> >
#define vi vector<int>

class Solution {
    void freq(vi& right,vi& left,int& maxi,int& mini,int k,int l) {
        
        for(int i= 0;i<26;i++) {
            int a = right[i]-left[i];
            if( a>0) maxi = max(maxi,a);
            if(a>0) mini = min(mini,a);
        }
        if(mini == 501) mini = maxi;
        
    }
public:
    int beautySum(string s) {

        ios_base::sync_with_stdio(false); cin.tie(nullptr);

        unordered_map<int,vector<int> > prefixCounter;
        int len = s.length();
        prefixCounter[0] = vector<int>(26,0);
        
        for(int i = 1;i<=len;i++) {
            prefixCounter[i] = prefixCounter[i-1];
            prefixCounter[i][s[i-1]-'a']++;       
        }
        int sum = 0;   
        for(int i = 0;i<=len;i++) {
            for(int j = i+1;j<=len;j++) {
                int maxi = 0, mini = 501;
                freq(prefixCounter[j],prefixCounter[i],maxi,mini,i,j);
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};