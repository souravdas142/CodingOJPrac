#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define newln "\n"
#define debug(x) cout<<#x<<" is: "<<x<<newln;
#define ll long long
//#define max 1e10-1

/*

   a^b {b<= 10^9; a<= 10^9}


*/

/* 
// loop
ll modExp(ll a, ll b, ll c = LONG_MAX) {
    ll ans = 1;
    ll x = a % c;
    b = b%c;
    while(b) {

        if(b&1) { // if b is odd 
            ans = ans*x;

        }
        x = x*x;
        b=b>>1;
        
    }
    return ans;

}
*/

ll modExp(ll a, ll b, ll c=LONG_MAX) {
    if (b == 0 ) return 1;
    if(b==1) return a;
    ll y;
    if(b&1) {
        y = a*modExp(a,b-1);

    }
    else {
        y = modExp(a,b>>1);
        y = y*y;
    }
    
    return y;


}

void solve() {

        ll a,b,c=0; cin>>a>>b;
        debug(a);
        ll ans = modExp(a,b);
        cout<<" modExp = "<<ans<<newln;
}

int main() {
    //fio;
    ll tc = 1; cin>>tc;
    debug(tc);
    while(tc--) {
        solve();
    }
    
    return 0;

}