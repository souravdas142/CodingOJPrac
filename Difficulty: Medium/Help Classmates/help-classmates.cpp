//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int> st;
        vector<int> ans;
        int i = n-1;
        while(i>=0) {
            
            while(!st.empty() && st.top()>=arr[i] ) {
                
                
                
                st.pop();
            }
            
            if(st.empty()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(st.top());
            }
            
            st.push(arr[i]);
            
            
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends