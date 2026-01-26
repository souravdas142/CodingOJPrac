class Solution {
  public:
  
   // Next Greater Element: Use STRICT inequality (<)
void ngec(vector<int>& arr, int n, vector<int>& nge) {
    stack<int> st;
    for (int j = n - 1; j >= 0; j--) {
        while (!st.empty() && arr[st.top()] < arr[j]) { // Changed <= to <
            st.pop();
        }
        nge[j] = st.empty() ? n : st.top();
        st.push(j);
    }
}

// Previous Greater Element: Keep NON-STRICT (<=)
void pgec(vector<int>& arr, int n, vector<int>& pge) {
    stack<int> st;
    for (int j = 0; j < n; j++) {
        while (!st.empty() && arr[st.top()] <= arr[j]) { // Keep <=
            st.pop();
        }
        pge[j] = st.empty() ? -1 : st.top();
        st.push(j);
    }
}

// Next Smaller Element: Use STRICT inequality (>)
void nsec(vector<int>& arr, int n, vector<int>& nse) {
    stack<int> st;
    for (int j = n - 1; j >= 0; j--) {
        while (!st.empty() && arr[st.top()] > arr[j]) { // Changed >= to >
            st.pop();
        }
        nse[j] = st.empty() ? n : st.top();
        st.push(j);
    }
}

// Previous Smaller Element: Keep NON-STRICT (>=)
void psec(vector<int>& arr, int n, vector<int>& pse) {
    stack<int> st;
    for (int j = 0; j < n; j++) {
        while (!st.empty() && arr[st.top()] >= arr[j]) { // Keep >=
            st.pop();
        }
        pse[j] = st.empty() ? -1 : st.top();
        st.push(j);
    }
}
  
    int subarrayRanges(vector<int>& arr) {
        // code here
        // nge
        // pge
        // nse
        // pse
        int n = arr.size();
        vector<int> nge(n,0), pge(n,0), nse(n,0), pse(n,0);
        
        ngec(arr,n,nge);
        pgec(arr,n,pge);
        nsec(arr,n,nse);
        psec(arr,n,pse);
        
        int j = 0;
        
        int ans = 0;
        
        while(j<n) {
            
            ans += (long long)arr[j] * (j - pge[j]) * (nge[j] - j);
            ans -= (long long)arr[j] * (j - pse[j]) * (nse[j] - j);
            
            j++;
        }
        
        int ans2 = (int)ans;
        
        return ans2;
        
    }
};