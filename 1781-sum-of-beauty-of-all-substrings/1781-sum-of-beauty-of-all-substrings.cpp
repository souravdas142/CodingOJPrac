#define uvi unordered_map<int,vector<int> >
#define vi vector<int>

class Solution {
    void freq(vi& right,vi& left,int& maxi,int& mini,int k,int l) {
        if(k==1 && l==5)
            cout<<"freq = i,j = "<<k<<","<<l<<" -> ";
        for(int i= 0;i<26;i++) {
            int a = right[i]-left[i];
            if(k==1 && l==5) {
                cout<<a<<" ";
            }
            if( a>0) maxi = max(maxi,a);
            if(a>0) mini = min(mini,a);
        }
        if(k==1 && l==5) cout<<endl;
        cout<<"before mini = "<<mini<<endl;
        if(mini == 501) mini = maxi;
        cout<<"maxi = "<<maxi<<" mini = "<<mini<<endl;
    }
public:
    int beautySum(string s) {

        unordered_map<int,vector<int> > prefixCounter;
        int len = s.length();
        prefixCounter[0] = vector<int>(26,0);
        
        for(int i = 1;i<=len;i++) {
            prefixCounter[i] = prefixCounter[i-1];
            prefixCounter[i][s[i-1]-'a']++;
            
        }

        int sum = 0;

        
        cout<<endl;
        for(auto pr:prefixCounter) {
            cout<<pr.first<<" -> ";
            for(auto i:pr.second) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        
      
        for(int i = 0;i<=len;i++) {
            for(int j = i+1;j<=len;j++) {
                int maxi = 0, mini = 501;
                cout<<"i = "<<i<<" j = "<<j<<endl;
                string dup(s.begin()+i,s.begin()+j);
                cout<<dup<<endl;
                freq(prefixCounter[j],prefixCounter[i],maxi,mini,i,j);
                sum+=(maxi-mini);
            }
            cout<<"\n";
        }

        return sum;
    }
};