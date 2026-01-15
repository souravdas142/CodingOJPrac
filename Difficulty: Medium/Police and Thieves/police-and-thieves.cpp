class Solution {
  public:
    
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        
        auto comp = [](int& a, int& b)-> bool {
          return a>b;  
        };
        
        queue<int> pqt,pqp;
        int n = arr.size();
        for(int i = 0;i<n;i++) {
            if(arr[i]=='T') pqt.push(i);
            else pqp.push(i);
        }
        
        int ans = 0;
        
        while((!pqp.empty()) && (!pqt.empty()) ) {
            int p = pqp.front();
            if(abs(p-pqt.front())<=k) {
                pqt.pop();
                pqp.pop();
                ans++;
            }
            else if(p<pqt.front()) {
                pqp.pop();
            }
            else if(pqt.front()<p) {
                pqt.pop();
            }
        }
        return ans;
    }
};