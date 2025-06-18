class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,-1);
        int j = 0;
        while(j<n) {
            while(!st.empty() && st.top() >= arr[j]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[j] = st.top();
            }
            st.push(arr[j]);
            j++;
        }
        return ans;
    }
};