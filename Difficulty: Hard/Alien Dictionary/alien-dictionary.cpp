//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    
  void dictorder(string& str1, string& str2 ,pair<char,char>& ans) {
      int i = 0,j = 0;
      int asz = str1.length(), bsz = str2.length();
      
      ans.first = 'a' -1;
      ans.second = 'a' - 1;
      
      bool flag = false;
      while(i<asz && j<bsz) {
          if(str1[i]!=str2[j]) {
              flag = true;
              ans.first = str1[i];
              ans.second = str2[j];
              return;
              //break;
          }
          i++;j++;
      }
      if(i<asz) {
          ans.first = str1[i];
      }
      if(j<bsz) {
          ans.second = str2[j];
      }
  }
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<vector<int> > graph(k);
        
        
        
        for(int i = 1;i<n;i++) {
            
            pair<char,char> order;
            dictorder(dict[i-1],dict[i],order);
            
            if(order.first>='a' && order.second>='a')
                graph[order.first-'a'].push_back(order.second-'a');
            
            
            
        }
        
        
        vector<int> indeg(k);
        
        for(int i = 0;i<k;i++) {
            for(auto a:graph[i]) {
                indeg[a]++;
            }
        }
        queue<int> que;
        for(int i = 0;i<k;i++) {
            if(indeg[i]==0) que.push(i);
        }
        string ans;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            ans+=(node+'a');
            for(auto a:graph[node]) {
                indeg[a]--;
                if(indeg[a]==0) que.push(a);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends