#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ln "\n"
#define debug(x) cout<<#x<<" is: "<<ln;

void solution(long long x) {
    long long res = 0;


    while(x) { //x = 123
               //
        res+= x%10;
        x=x/10;
        if(x)
            res=res*10;
        
    }
    
    cout<<res<<ln;

}


int main() {
    fio;
    long long t;
    cin>>t;
    while(t--) {
        long long x; cin>>x;
        solution(x);
    }
    
    return 0;
    
}
