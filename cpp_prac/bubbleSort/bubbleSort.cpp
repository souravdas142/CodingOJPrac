#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&,bool);

ostream& operator << ( ostream& ccout,const vector<int>& arr) {
    for(auto &i :arr) {
        ccout<<i<<" ";
    }
    return ccout;
}

void solve(vector<int>& arr,bool asscending) {

    cout<<arr<<endl;
    bubbleSort(arr,asscending);
    cout<<arr<<endl;

}

int main() {
    
    int tc; cin>>tc;
    while(tc--) {
        
        int size; cin>>size;
        vector<int> arr(size,0);
        for(int &inp:arr) cin>>inp;

        solve(arr,true);
    }

    return 0;
}


void bubbleSort(vector<int>& arr,bool asscending) {

    for (int i =0;i<arr.size();i++) {
        bool flag = false;
        for(int j = 0;j<arr.size()-1-i;j++) {
            if(arr[j]>arr[j+1]) {
                arr[j] +=arr[j+1];
                arr[j+1] = arr[j]-arr[j+1];
                arr[j] = arr[j]-arr[j+1];
                flag = true;

            }
        }
        if(!flag) break;
    }



}