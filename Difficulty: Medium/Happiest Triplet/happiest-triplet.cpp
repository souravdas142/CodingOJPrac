
#define debug(a,b,c) cout<<#a<<" = "<<a<<#b<<" = "<<b<<#c<<" = "<<c<<endl;

class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        
        int n = a.size();
        
        int i = 0, j = 0, k = 0;
        int ansmini = INT_MAX;
        int anssum = 0;
        vector<int> ans(3,-1);
        
        while(i<n && j<n && k<n) {
            int maxi = max(a[i],max(b[j],c[k]));
            int mini = min(a[i],min(b[j],c[k]));
            
            // int detectMini = -1;
            // int detectMiniPos = -1;
            
            // if(a[i]<b[j] && a[i]<c[k]) {
            //     detectMini=0;
            //     detectMiniPos=i;
            // }
            // else if(b[j]<c[k] && b[j]<a[i]) {
            //     detectMini=1;
            //     detectMiniPos=j;
            // }
            // else if(c[k]<a[i] && c[k]<b[j]) {
            //     detectMini=2;
            //     detectMiniPos=k;
            // }
            
            if(maxi-mini==ansmini) {
                if(a[i]+b[j]+c[k]<anssum) {
                    anssum = a[i]+b[j]+c[k];
                    ans={a[i],b[j],c[k]};
                }
            }
            else if(maxi-mini<ansmini) {
                anssum=a[i]+b[j]+c[k];
                ans={a[i],b[j],c[k]};
                ansmini = maxi-mini;
            }
            
            // debug(ans[0],ans[1],ans[2]);
            // cout<<anssum<<endl;
            
            // if(detectMini==0) i++;
            // else if(detectMini==1) j++;
            // else if(detectMini==2) k++;
            
            if(mini==a[i]) i++;
            else if(mini==b[j]) j++;
            else if(mini==c[k]) k++;
        }
        
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};

/*

9 12 15 18
8 10 13 17
5 11 14 16


*/