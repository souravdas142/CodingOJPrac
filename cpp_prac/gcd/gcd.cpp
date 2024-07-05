#include <bits/stdc++.h>
using namespace std;
#define newln "\n"
#define debug(x) cout<<#x<<" is: "<<x<<newln;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

ll gcd(ll a, ll b) {
    
    debug(a);
    debug(b);
    if(a%b==0) return b;
    if(a==b) return a;
    if(a%b==1 || b%a == 1) return 1;

    if(a>b) {
        if(b%a==0) 
            return a;
        return gcd(a-b,b);
    }
    return gcd(b-a,a);


}


void solve() {

    ll a,b; cin>>a>>b;
    ll res = gcd(a,b);
    cout<<"gcd("<<a<<","<<b<<") is: "<<res<<newln;
    
    ll lcm = (res*9)% LONG_LONG_MAX;
    lcm = lcm/gcd(res,9);

    cout<<"lcm is: "<<lcm<<newln;


    
}

int main() {
    fio;
    ll tc=1; cin>>tc;
    while(tc--) {
        solve();
    }

    

    return 0;
}