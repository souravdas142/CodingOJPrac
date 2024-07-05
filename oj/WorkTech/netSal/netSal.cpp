#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llf double
#define newln "\n"

class Solutions {
    private:

        void solve(int x,int y,int n) {

            int m = n/x;
             m = m*x;  // divisible by x;
            if(m+y<=n) cout<<m+y<<endl;
            else {
                int k = x-y;
                cout<<m-k<<endl;

            }


        }
        
        
            


    public:

        void solve () {
            
            ll tc = 1;
            cin>>tc;
            while(tc--) {
                int x,y,n; cin>>x>>y>>n;
                solve(x,y,n);
            }


        }
};

int main () {
    Solutions sol;
    sol.solve();
    return 0;
}