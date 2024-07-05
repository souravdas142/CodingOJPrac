#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define newln "\n"
#define debug(x) cout<<newln<<#x<<" = "<<x<<newln

template<typename t1>
ostream& operator<<(ostream& print, vector<t1>& vec) {

    print<<newln;
    for(t1 a:vec) {
        print<<a<<" ";
    }
    print<<newln;

    return print;
}

int buildFailureTable(const string& pattern, vector<int>& ft) {

    // for length 0,1 the best candidate will be 0
    ft[0] =0; ft[1] = 0; 
    int patsz = pattern.size();
    
    
    for(int i = 2;i<patsz;i++) {
        
        int j = ft[i-1];
        while(true) {
            if(pattern[j]==pattern[i-1]) {
                ft[i] = j+1;
                cout<<"ft = "<<ft[i]<<endl;
                break;
            }
            
            if(j==0) {
                ft[i] =0;
                cout<<"ft = "<<ft[i]<<endl;
                break;
            }

            j = ft[j];

        }
        
    } 
    
    return 0;

    
}

int kmpMatch(const string& txt,const string& pattern, const vector<int>& ft) {
    
    int txtsz = txt.size();

    int j = 0;

    for(int i = 0;i<txtsz; i++) {
        
        if(txt[i]==pattern[j]) {
            
        }



        
    }




    return -1;
}

void solve() {
    string txt,pattern; cin>>txt>>pattern;
    vector<int> ft(pattern.size()+1,0);
    buildFailureTable(pattern,ft);
    cout<<"FailureTable:-----------"<<newln<<ft<<endl;
    int pos = kmpMatch(txt,pattern,ft);
    if(pos!=-1) {
        cout<<"Pattern: "<<pattern<<" matched at pos: "<<pos<<newln;
    } else {
        cout<<"Pattern: "<<pattern<<" not matched"<<newln;
        
    }
}

int main() {
    
    ll tc=1;
    cin>>tc;
    
    while(tc--) {
        solve();
    }
    
    return 0; 
    
}