#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define newln "\n"
#define debug(x) cout<<newln<<#x<<" = "<<x<<newln

void solve() {

    string pattern; cin>>pattern;
    string text; 
    cin.ignore();
    getline(cin,text);
    stringstream ss(text);
    string s;
    vector<string> vs;
    while(getline(ss,s,' ')) {
        vs.push_back(s);
    }
    
    int psz = pattern.length();
    int vsz = vs.size();
    if(psz!=vsz) {
        cout<<"false"<<newln;
        return;
    }
    
    unordered_map<char,set<string> > ump;
    
    for(int i = 0;i<psz;i++) {
        ump[pattern[i]].insert(vs[i]);
        if(ump[pattern[i]].size()>1) {
            cout<<"false"<<newln;
            return;
        }
    }
    
    cout<<"true"<<newln;
    return;

}


int main() {

    
    ll tc = 1;
    cin>>tc;
    while(tc--) {


        solve();

    }


    return 0;
}