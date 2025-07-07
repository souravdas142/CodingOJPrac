// User function Template for C++
#define vi vector<int>

class Solution {
  public:
    int maxEqualSum(int n1, int n2, int n3, vi &s1, vi &s2,vi &s3) {
        
       
        
        
        int f1 = 0;
        int mini = INT_MAX;
        for(auto e:s1) f1+=e;
        mini = min(mini,f1);
        int f2 = 0;
        for(auto e:s2) f2+=e;
        mini = min(mini,f2);
        int f3=0;
        for(auto e:s3) f3+=e;
        mini = min(mini,f3);
        
        int i = 0, j = 0, k = 0;
        
        int ans = 0;
        
        while(i<n1 && j<n2 && k<n3) {
           
           if(f2==f3 && f1 == f2) return f1;
           
            if(mini == 0) return 0;
            
            if(f1>min(f2,f3)) {
                f1-=s1[i];
                i++;
            }
            else if(f2>min(f1,f3)) {
                f2-=s2[j];
                j++;
            }
            else if(f3>min(f1,f2)) {
                f3 -= s3[k];
                k++;
            }
            
            mini = min(mini,min(f1,min(f2,f3)));
            
            
        }
        
        return 0;
        
    }
};