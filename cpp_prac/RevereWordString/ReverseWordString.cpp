#include <bits/stdc++.h>
using namespace std;
#define newln "\n"
#define dbg(x) cout<<#x<<" is: "<<newln;
#define fio ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long

void solve(const string& str) {
    
    cout<<"Resolving : "<<str<<endl;
    
    int size = str.length();
    int prev = size-1;
    while(size--) {
        if(str[size]==' ') { // delim
            cout<<str.substr(size+1,(prev-size))<<" ";
            prev=size;
        }
    }
    cout<<str.substr(size+1,(prev-size))<<" ";
    
    

    
}

int main () {
    fio
        

    ll tc; cin>>tc;
    while (tc--) {
        string s; 
        getline(cin>>ws,s);
        solve(s);
    }
    
    return 0;
    

}

