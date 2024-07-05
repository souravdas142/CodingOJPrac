#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define newln "\n"
#define debug(x) cout<<#x<<" is: "<<x<<newln

ostream& operator << (ostream& print,const vector<ll> vec) {
    for(auto i:vec) {
        print<<i<<" ";
    }
    
    return print;
}

void merge(vll& arr,vll& left,vll& right) {
    ll l = 0;
    ll r = 0;
    ll k = 0;

    while(l<left.size() && r<right.size()) {
        if(left[l] > right[r]) {
            arr[k++] = left[l++];
        } else if (right[r] > left[l]) {
            arr[k++] = right[r++];
        }

    }
    
    while (l<left.size()) {
        arr[k++] = left[l++];
    }
    while (r<right.size()) {
        arr[k++] = right[r++];
    }
    
    cout<<"Merge: ";
    debug(arr);

}

void mergeSort(vll& arr,ll size) {
    
    debug(arr);
    if(size>1) {
        ll mid  = size/2;

        vector<ll> mergeSortLeft(arr.begin(),arr.begin()+mid);
        vector<ll> mergeSortRight(arr.begin()+mid,arr.end());
        
        debug(mergeSortLeft);
        debug(mergeSortRight);
        
        mergeSort(mergeSortLeft,mergeSortLeft.size());
        mergeSort(mergeSortRight,mergeSortRight.size());
        
        merge(arr,mergeSortLeft,mergeSortRight);
    }

}

void solve() {
    ll size; cin>>size;
    vector<ll> arr(size);
    
    for(ll& a:arr) cin>>a;
    
    cout<<arr<<newln;
    mergeSort(arr,size);
    cout<<arr<<newln;


}

int main() {
    
    ll tc=1;
    cin>>tc;
    while (tc--) {
        solve();
    }
    return 0;

}