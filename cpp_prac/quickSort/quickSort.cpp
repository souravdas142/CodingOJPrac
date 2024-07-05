#include <bits/stdc++.h>
using namespace std;
#define newln "\n"
#define debug(x) cout<<#x<<" is: "<<x<<newln;
#define ll long long
#define ull unsigned long long
#define fio ios_base::sync_with_stdio(nullptr); cin.tie(nullptr);

void solve(vector<ll>& arr,ll sz);
ll extractPiviotLoc(vector<ll> & arr,ll low, ll sz);
void quickSort(vector<ll>& arr,ll low,ll high);

template<typename t1>
ostream& operator <<(ostream& ccout,const vector<t1> arr) {
    


    for(const t1 &i:arr) {
        ccout<<i<<" ";
    }
    return ccout;
}

int main() {
    ll tc; cin>>tc;
    while (tc--) {
        ll sz; cin>>sz;
        vector<ll> arr(sz,0);
        for(ll &i:arr) cin>>i;
        solve(arr,sz);
    }

    return 0;


}


void solve(vector<ll>& arr,ll sz) {
    if (!arr.size() || arr.size() != sz) return;
    
    cout<<arr<<endl;
    quickSort(arr,0,arr.size()-1);
    cout<<"Solution: "<<arr<<endl;
}

void quickSort(vector<ll>& arr,ll low,ll high) {
    
    if(low<high) {
        ll piviot = extractPiviotLoc(arr,low,high);
        

        
        quickSort(arr,low,piviot-1);
        quickSort(arr,piviot+1,high);
    }



}

void __swap(ll& ele1,ll& ele2) {
    
    ll tmp1=ele1,tmp2=ele2;
    tmp1+=tmp2;
    tmp2 = tmp1-tmp2;
    tmp1 = tmp1-tmp2;
    ele1=tmp1;
    ele2=tmp2;


}

ll extractPiviotLoc(vector<ll>& arr,ll low,ll high) {
    int piviot = high;

    debug(piviot);
    int sortedIndex = low-1;
    for(int i = low ;i<high;i++) {
        if(arr[i]>arr[piviot]){
            __swap(arr[i],arr[++sortedIndex]);
        }
    }
    
    __swap(arr[++sortedIndex],arr[piviot]);

    return sortedIndex;
}