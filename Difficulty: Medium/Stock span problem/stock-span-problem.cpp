class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        // pse
        
        int n = arr.size();
        int i  = 0;
        
        stack<int> st;
        st.push(i);
        vector<int> ans;
        ans.push_back(1);
        i++;
 
        while(!st.empty() && i<n ) {
            while(!st.empty() && arr[st.top()]<=arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                ans.push_back(i+1);
            }
            else {
                ans.push_back(i-st.top());
            }
            st.push(i);
            
            i++;
            
            
        }
        
        return ans;
        
    }
};