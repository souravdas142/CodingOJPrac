#include <iostream>
using namespace std;
#define ll long long
#define newln "\n"
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cout<<#x<<" = "<<x<<newln

void solve () {

        ll a,x,y,x1,x2; cin>>x>>y>>a;

        
        ll xlenghtreminder = x%a;
        ll ylengthreminder = y%a;
       // debug(xlenghtreminder);
       // debug(ylengthreminder);
        
        if(xlenghtreminder!=0) {
           x1 = ((y-ylengthreminder)/a);
        //   debug(x1);
        }
        if(ylengthreminder!=0) {
            x2 = (x/a)+1;
           // debug(x2);

        }
        
        x = x/a;
        y = y/a;
        
        int res = max(x,y)+x1+x2;
        cout<<res<<endl;

        
        
        
        

    
}

int main() {

    ll tc=1; //cin>>tc;
    while(tc--) {
        solve();
        
    }
    

    return 0;


}