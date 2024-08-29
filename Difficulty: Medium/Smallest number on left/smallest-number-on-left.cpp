//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        stack<int> st;
        int  i = 0;
        vector<int> ans;
        while(i<n) {
            
           
                while(!st.empty() && st.top()>=arr[i]) {
                    st.pop();
                }
                
                if(st.empty()) {
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(st.top());
                }
                
                st.push(arr[i]);
                i++;
            
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends