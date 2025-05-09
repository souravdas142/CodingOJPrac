//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  void merge(vector<int>& arr,int l, int mid, int r) {
      int fl = l, fr = mid, sl=mid+1, sr=r;
      int of = fr, os = sl;
      //cout<<"index = "<<of<<" "<<fl<<" "<<os<<" "<<fr<<endl;
      while(of>=fl && os<=sr) {
          if(arr[of]>arr[os]) {
              swap(arr[of],arr[os]);
              //cout<<"ok"<<endl;
          }
          else {
              break;
          }
          //cout<<of<<endl;
          
          of--;os++;
      }
      sort(arr.begin()+fl,arr.begin()+fr);
      sort(arr.begin()+sl,arr.begin()+sr);
  }
  
  
  void merge2(vector<int>& arr, int l, int mid, int r) {
      int sz = r-l+1;
      vector<int> dummy(sz,0);
      int j=l,k=mid+1;
      int i = 0;
      
      while(j<=mid &&k<=r ) {
          
          if(arr[j]<arr[k]) {
              dummy[i++] = arr[j];
              j++;
          }
          else {
              dummy[i++] = arr[k];
              k++;
          }
      }
      
      while(j<=mid) {
          dummy[i++] = arr[j];
          j++;
      }
      while(k<=r) {
          dummy[i++] = arr[k];
          k++;
      }
      
      for(int m = l;m<=r;m++) {
          arr[m]=dummy[m-l];
      }
      
  }
  
  void mergeSort(vector<int>& arr, int l,int r) {
      if(l>=r) return;
      int mid = l+(r-l)/2;
      //cout<<l<<endl<<mid<<endl<<r<<endl;
      mergeSort(arr,l,mid);
      mergeSort(arr,mid+1,r);
      merge2(arr,l,mid,r);
  }
  
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends