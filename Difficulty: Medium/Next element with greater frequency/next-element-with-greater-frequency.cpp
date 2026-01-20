class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> freq;
        
        for(auto &e: arr) freq[e]++;
        
        vector<pair<int,int>> vpi(n);
        for(int i = 0;i<n;i++) {
            vpi[i] = {freq[arr[i]],arr[i]};
            //cout<<vpi[i].first<<" "<<vpi[i].second<<endl;
        }
        
        /// NGE
        
        stack<pair<int,int>> st;
        st.push(vpi[n-1]);
        vector<int> ans(n,0);
        ans[n-1] = -1;
        int i = n-2;
        //cout<<n<<" "<<i<<endl;
        while(!st.empty()) {
            int freqNow = vpi[i].first;
            
            while(!st.empty() && freqNow >= st.top().first) {
                //cout<<i<<" "<<freqNow<<" "<<st.top().first<<endl;
                st.pop();
            }
            
            
            
            if(st.empty()) {
                ans[i] = -1;
            }
            else {
                //cout<<i<<" after "<<st.top().first<<endl;
                ans[i] = st.top().second;
            }
            
            st.push(vpi[i]);
            i--;
            if(i<0) break;
            
        }
        
        return ans;
    }
};
