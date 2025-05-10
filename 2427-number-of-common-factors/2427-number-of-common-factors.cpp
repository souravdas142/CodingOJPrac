class Solution {
public:
    int commonFactors(int a, int b) {

        int n = min(a,b);
        int cnt = 0;

        for(int i = 1;i*i<=n;i++) {
            if(a%i==0 && b%i==0) {
                cnt++;
                
                } 
                int p = n/i;
                cout<<i<<endl;
                if(p!=i && a%p==0 && b%p==0) {
                    cnt++;
                    cout<<p<<endl;
            }


        }
        return cnt;
        
    }
};