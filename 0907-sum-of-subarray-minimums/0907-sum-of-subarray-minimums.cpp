#define mod ((int)(1e9 +7))

ostream& operator<<(ostream& print,vector<int>& arr) {
    print<<endl;
    for(auto a:arr) print<<a<<" ";
    print<<endl;
    return print;
}

class Solution {
    void nge(vector<int>& arr,vector<int>& ans,int n) {
        stack<int> st;
        int i = n-1;
        while(i>=0) {

            while(!st.empty() && arr[st.top()]<=arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(st.top());
            }

            st.push(i);

            i--;
        }
        reverse(ans.begin(),ans.end());
    }

    void pse(vector<int>& arr,vector<int>& ans,int n) {
        stack<int> st;
        int i = 0;
        while(i<n) {
            while(!st.empty() && arr[st.top()]>arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(st.top());
            }
            st.push(i);

            i++;
        }
    }

    void nse(vector<int>& arr, vector<int>& ans,int n) {
        stack<int> st;
        int i  = n-1;
        while(i>=0) {

            while(!st.empty() && arr[st.top()]>=arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                ans.push_back(n);
            }
            else {
                ans.push_back(st.top());
            }
            st.push(i);

            i--;
        }
        reverse(ans.begin(),ans.end());
    }


   
public:
    int sumSubarrayMins(vector<int>& arr) {

        int sz = arr.size();
        
        vector<int> vnse,vpse;
        pse(arr,vpse,sz);
        nse(arr,vnse,sz);

        //cout<<vpse<<endl;
        //cout<<vnse<<endl;

        int ans = 0;
        for(int i = 0;i<sz;i++) {
            int nc = vnse[i]-i;
            int pc = i-vpse[i];
            
            
            ans = (ans + (pc * nc * 1LL * arr[i]) % mod) % mod;
        }

        return (ans%mod);
    }
};