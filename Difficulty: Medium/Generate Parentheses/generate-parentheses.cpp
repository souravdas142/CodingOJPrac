//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{   private:
    void solve(int n,int left,int right,string res,vector<string>& ans) {
        if(right>=n) {
            ans.push_back(res);
            return;
        }
        if(left<n) {
            res.push_back('(');
            solve(n,left+1,right,res,ans);
            res.pop_back();
        }
        
        if(right<n && left>right) {
            res.push_back(')');
            solve(n,left,right+1,res,ans);
            res.pop_back();
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string res;
        int left = 0;
        int right = 0;
        solve(n,left,right,res,ans);
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends