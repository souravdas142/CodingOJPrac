#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define newln "\n"
#define debug(x) cout<<" "<<#x<<" = " <<x<<newln

class Solutions {

    public:

        int  solve() {
            
            vector<int> axis(3,0);
            for(int &i:axis) cin>>i;
            
            int ans = __INT_MAX__;
            for(int i = 0;i<3;i++) {

                int a = axis[i];
                int x = abs(axis[0]-a);
                int y = abs(axis[1]-a);
                int z = abs(axis[2]-a);
                ans = min(ans,x+y+z);

            }
            return ans;
       }

};

int main () {

    Solutions s;
    ll tc = 1;
    cin>>tc;
    while(tc--) {
        cout<<s.solve()<<endl;
    }


    return 0;
}