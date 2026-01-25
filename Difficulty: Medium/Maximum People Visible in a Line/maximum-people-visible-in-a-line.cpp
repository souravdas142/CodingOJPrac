class Solution {
  public:
  
    void findNge(vector<int>& nge, vector<int>& arr) {
        
        int n = arr.size();
        stack<int> st;
        
        int j = n-1;
        
        while(j>=0) {
            
            while(!st.empty() && arr[st.top()]<arr[j]) {
                st.pop();
            }
            
            if(st.empty()) {
                nge[j] = n;
            }
            else {
                nge[j] = st.top();
            }
            st.push(j);
            j--;
        }
        
        
        
        
    }
    
    void findPge(vector<int>& pge, vector<int>& arr) {
        int n = arr.size();
        
        stack<int> st;
        
        int j = 0;
        
        while(j<n) {
            while(!st.empty() && arr[st.top()]<arr[j]) {
                st.pop();
            }
            
            if(st.empty()) {
                pge[j] = -1;
            }
            else {
                pge[j] = st.top();
            }
            st.push(j);
            j++;
        }
    }
    
    int maxPeople(vector<int> &arr) {
        // code here
        // nge 
        // pge
        int n = arr.size();
        vector<int> nge(n,0);
        vector<int> pge(n,0);
        
        findNge(nge,arr);
        findPge(pge,arr);
        
        int ans = 0;
        
        for(int i = 0;i<n;i++) {
            ans = max(ans,nge[i]-pge[i]-1);
        }
        
        return ans;
        
    }
};