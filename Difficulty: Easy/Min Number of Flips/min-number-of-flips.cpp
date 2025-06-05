#include <bits/stdc++.h>
using namespace std;

int minFlips(string s) {
    int n = s.size();
    int i = 0;
    char flip = '0';
    int cnt1 = 0;
    while(i<n) {
        if(flip!=s[i]) {
            cnt1++;
        }
        flip = '0'+(1-(flip-'0'));
        
        i++;
    }
    
    int cnt2 = 0;
    flip = '1';
    i = 0;
        while(i<n) {
        if(flip!=s[i]) {
            cnt2++;
        }
        flip = '0'+(1-(flip-'0'));
        
        i++;
    }
    
    return min(cnt1,cnt2);
}