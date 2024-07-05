#include <bits/stdc++.h>
using namespace std;
#define newln "\n"
#define debug(x) cout<<#x<<" is "<<x<<newln;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int searchKey(vector<int>& arr,int key,int low,int high) {
    //vector<int> arr = {1,3, 7, 9, 10 ,15,17}; high  = 6,low = 0
    /// return -1 if not found
    int mid = (high+low)/2;
    debug(low);
    debug(high);
    debug(mid);
    if(high<low) return -1;
    if(key==arr[mid]) 
        return mid;
    else if(key<arr[mid])
        return searchKey(arr,key,low,mid-1);
    else if(key>arr[mid])
        return searchKey(arr,key,mid+1,high);



    
}

int main() {
    fio;
    vector<int> arr = {1,3, 7, 9, 10 ,15,17};
    int key = 5;
    cin>>key;
    debug(key);
    int pos = searchKey(arr,key,0,arr.size()-1);
    cout<<__LINE__<<endl;
    cout<<"found key at pos: "<<pos<<" Key is : "<<key<<"Value is : "<<arr[pos]<<endl;
    return 0;
}