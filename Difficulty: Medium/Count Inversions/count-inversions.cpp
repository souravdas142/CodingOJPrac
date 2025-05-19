//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


ostream& operator <<(ostream& print,const vector<int>& vec) {
    for(auto ele:vec) {
        print<<ele<<" ";
    }
    return print;
}

class Solution {
  public:
    // Function to count inversions in the array.
    void merge(vector<int>& arr, int &ans, int l, int mid, int r) {
        
        vector<int> arrl(arr.begin()+l,arr.begin()+mid+1);
        vector<int> arrr(arr.begin()+mid+1,arr.begin()+r+1);
    /*    
        cout<<endl<<"arrl = "<<arrl<<endl;
        cout<<"arrr = "<<arrr<<endl;
       
        cout<<"before sort arr = ";
        for(int i = l;i<=r;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
      */  
       
        int lsz = arrl.size();
        int rsz = arrr.size();
        int i = 0;
        int j = 0;
        int k = l;
        
        while(i<lsz && j<rsz) {
            if(arrl[i]>arrr[j]) {
                ans += (lsz-i);
                arr[k] = arrr[j];
                j++;k++;
            }
            else {
                arr[k++] = arrl[i++];
            }
        }
        
        while(i<lsz) {
            arr[k++] = arrl[i++];
        }
        
        while(j<rsz) {
            arr[k++] = arrr[j++];
        }
    /*    
        cout<<"after sort arr = ";
        for(int i = l;i<=r;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
      */  
        
    }
    void mergeSort(vector<int>& arr, int &ans, int l, int r, int n) {
        if(l>=r) return;
        int mid = l+(r-l)/2;
        mergeSort(arr,ans,l,mid,n);
        mergeSort(arr,ans,mid+1,r,n);
        merge(arr,ans,l,mid,r);
        
    }
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int count = 0;
        int n = arr.size();
        int l = 0;
        int r = n-1;
        mergeSort(arr,count,l,r,n);
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends