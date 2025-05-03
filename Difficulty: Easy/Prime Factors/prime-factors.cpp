//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define Max 1e6

bool isSpf=false;
vector<int> spf(Max+1,0);


class Solution {
  public:
  
    void makeSpf() {
        isSpf = true;
        
        for(int i = 0;i<=Max;i++) spf[i]=i;
        
        for(int i = 4;i<=Max;i+=2) {
            spf[i]=2;
        }
        
        for(int i = 3;i*i<=Max;i+=2) {
            for(int j = i*i;j<=Max;j+=(2*i)) {
                if(spf[j]==j) {
                    spf[j] = i;
                }
            }
        }
    }
    vector<int> AllPrimeFactors(int N) {
        // Code here
        
        vector<int> ans;
        
        if(isSpf==false) {
            makeSpf();
        }
        
        while(N!=1) {
            int next = spf[N];
            if(ans.size()==0) ans.push_back(next);
            if(ans.size()>=1 && ans.back()!=next)
                ans.push_back(next);
            N=N/next;
            
        }
        
        return ans;
        

        
        
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends