#include <bits/stdc++.h>
using namespace std;

void printv(const vector<int>& arr) {
    
    for(auto& e: arr) {
        cout<<e<<" ";
    }
    cout<<endl;
}

class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    void merge(vector<int>& arr, int start, int mid, int end, int& ans) {
        int k = end-start+1;
        vector<int> tmp(k,0);
        int i = start, j = mid, m = mid+1, n = end, l = 0;
        int cnt = 0;
        while(i<=j && m<=n) {
            if(arr[i]<=arr[m]) {
                tmp[l] = arr[i];
                i++;
                //cnt++;
            }
            else {
                tmp[l] = arr[m];
                m++;
                cnt++;
            }
            l++;
        }
        
        while(i<=j) {
            tmp[l++] = arr[i++];
        }
        
        while(m<=n) {
            tmp[l++] = arr[m++];
            
        }
        
        l = 0;
        
        while(l<k) {
            arr[start++] = tmp[l++];
        }
        
        ans+=cnt;
        
    }
    
    void mergeSort(vector<int>& arr, int start, int end, int& ans) {
        if(start>=end) return;
        int mid = start+(end-start)/2;
        // mergeSort left
        mergeSort(arr,start,mid,ans);
        mergeSort(arr,mid+1,end,ans);
        
        merge(arr,start,mid,end,ans);
    }
    int implMergeSort(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        mergeSort(arr,0,n-1,ans);
        return ans;
    }
    int minSwaps(vector<int>& arr) {
        // Code here
		//

		printv(arr);
        
        int ans =  implMergeSort(arr);
		cout<<"after\n";
		printv(arr);
		cout<<"after end \n";

		return ans;
		
       
    }
};

int main() {


	Solution prblm;

	int n; cin>>n;
	vector<int> arr(n,0);
	for(auto& e: arr) cin>>e;

	int ans = prblm.minSwaps(arr);

	cout<<ans<<endl;
	

	return 0;
}
