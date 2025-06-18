#define mod ((int)(1e9 +7))

ostream& operator<<(ostream& print, vector<int>& arr) {
    for(auto e: arr) {
        print<<e<<" ";
    }
    return print;
}

class Solution {
public:
    void pse(vector<int>& arr, int n, vector<int>& psePos) {
        stack<int> st;
        int j = 0;

        while(j<n) {
            while(!st.empty() && arr[st.top()]> arr[j]) {
                st.pop();
            }
            if(!st.empty()) {
                psePos[j] = st.top();
            }
            st.push(j);
            j++;
        }
    }
    void nse(vector<int>& arr, int n, vector<int>& nsePos) {
        stack<int> st;
        int j = n-1;
        while(j>=0) {
            while(!st.empty() && arr[st.top()]>=arr[j]) {
                st.pop();
            }
            if(!st.empty()) {
                nsePos[j] = st.top();
            }
            st.push(j);
            j--;
        }

    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> psePos(n,-1),nsePos(n,n);
        pse(arr,n,psePos);
        nse(arr,n,nsePos);


        cout<<arr<<endl<<psePos<<endl<<nsePos<<endl;

        // calculate individual Contribution of each

        int j = 0;
        while(j<n) {

            int leftLenIncludingCur = j - psePos[j];
            int rightLenIncludingCur = nsePos[j]-j;

            ans = (ans + (leftLenIncludingCur * rightLenIncludingCur * arr[j]) % mod) % mod;
            j++;
            
        }

        return ans;

        
    }
};