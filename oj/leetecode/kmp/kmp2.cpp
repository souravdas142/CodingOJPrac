#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define newln "\n"
#define debug(x) cout<<#x<<" = "<<x<<newln;

void buildft(const string& pattern,vector<int>& vft) {
    
    // say vft[i] for i length the best candidate to match with

    vft[0] = vft[1] = 0;
    int ptsz = pattern.size();
    for(int i = 2;i<ptsz;i++) {
        
        // we want to check for the current(ith) length we can expand from the i-1 lengths candidate 
        int j = vft[i-1];
        
        while(true) {
            if(pattern[j]==pattern[i-1]) { // if i is lenght, then the last char present of lenght i is i-1;
                vft[i] = j+1;
                break;
            
            }
            else {
                if(j==0) {
                   vft[i]=0;
                   break; 
                }
                j = vft[j];

            }
        }
    }



}


void solve() {
    string txt,pattern;
    cin>>txt>>pattern;
    int txtsz = txt.size(), ptsz = pattern.size();
    vector<int> vft(ptsz+1,0);

    buildft(pattern,vft);
    
    cout<<__LINE__<<newln;

    int i = 0,j = 0;
    
    while(true) {
        
        if(j == txtsz) {
            // we traverse the txt but couldn't find

            cout<<pattern<<" is not found"<<newln;
            break;
        }
        
        
        if(pattern[i]==txt[j]) {
            i++;j++;

            if(i==ptsz) {
                
                cout<<pattern<<" is found at pos "<<(j-i+1)<<newln;
                debug(i);
                debug(j);
                // if you want to continue for the next match commentout the below line
                // TODO:
                //break;
            }
        }
        else {
           // we can't even expand the candidate the we have to move forward for the next char on the txt 
           // and the searching pattern resets back to 0
            if(i==0) {
                j++;
            }
            else {

                // if we unable to match with the current char-{pattern,txt} check the next best candidate
                i = vft[i];
            }


        }



        
    }
    
}

int main () {
    
    int tc = 1;
    cin>>tc;

    while(tc--) {
        solve();
    }

    return 0;
}