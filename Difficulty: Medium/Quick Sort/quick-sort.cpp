//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends

class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        
        if(low>=high) return;
        
        int piviotPos = findPiviotPos(arr,low,high);
        
        quickSort(arr,low,piviotPos-1);
        quickSort(arr,piviotPos+1,high);
        
    }
    
    int findPiviotPos(vector<int>& arr, int low, int high) {
        int piviotPos = high;
        int sortPos = low;
        int i = low;
        while(i<piviotPos) {
            if(arr[i]<arr[piviotPos]) {
                swap(arr[i],arr[sortPos]);
                sortPos++;
            }
            i++;
        }
        
        swap(arr[sortPos],arr[piviotPos]);
        return sortPos;
    }


    
};


//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends