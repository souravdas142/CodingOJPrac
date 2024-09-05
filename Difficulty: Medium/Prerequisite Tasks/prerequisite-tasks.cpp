//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	    // Code here
	    
	    vector<int> indegree(N,0);
	    vector<vector<int> > adjlist(N);
	    
	    for(int i = 0;i<P;i++) {
	        
	        adjlist[pre[i].second].push_back(pre[i].first);
	    }
	    
	    for(int i = 0;i<N;i++) {
	        for(auto a: adjlist[i]) {
	            indegree[a]++;
	        }
	    }
	    
	    queue<int> que;
	    
	    for(int i= 0;i<N;i++) {
	        if(indegree[i]==0) que.push(i);
	    }
	    
	    int cnt = 0;
	    while(!que.empty()) {
	        int node = que.front();
	        que.pop();
	        cnt++;
	        
	        for(auto a:adjlist[node]) {
	        
	            indegree[a]--;
	            if(indegree[a]==0) que.push(a);
	        }
	        
	        
	        
	        
	    }
	    
	    if(cnt==N) return true;
	    return false;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends