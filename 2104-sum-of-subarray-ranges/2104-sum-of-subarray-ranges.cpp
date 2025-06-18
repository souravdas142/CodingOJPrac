#define ll long long

ostream& operator<<(ostream& print, vector<int>& arr) {
    for(auto e: arr) {
        print<<e<<" ";
    }
    return print;
}

class Solution {

    void pse(vector<int>& nums, vector<int>& psePos, int n) {
        stack<int> st;
        int j = 0;
        while(j<n) {
            while(!st.empty() && nums[st.top()]>nums[j]) {
                st.pop();
            }
            if(!st.empty()) {
                psePos[j] = st.top();
            }
            st.push(j);
            j++;
        }
        
    }

    void nse(vector<int>& nums, vector<int>& nsePos, int n) {
        stack<int> st;
        int j = n-1;
        while(j>=0) {
            while(!st.empty() && nums[st.top()]>=nums[j]) {
                st.pop();
            }
            if(!st.empty()) {
                nsePos[j] = st.top();
            }
            st.push(j);
            j--;
        }
    }

    void pge(vector<int>& nums, vector<int>& pgePos, int n) {
        stack<int> st;
        int j = 0;
        while(j<n) {
            while(!st.empty() && nums[st.top()]<nums[j]) {
                st.pop();
            }
            if(!st.empty()) {
                pgePos[j] = st.top();
            }
            st.push(j);
            j++;
        }
    }

    void nge(vector<int>& nums, vector<int>& ngePos, int n) {
        stack<int> st;
        int j = n-1;
        while(j>=0) {
            while(!st.empty() && nums[st.top()]<=nums[j]) {
                st.pop();
            }
            if(!st.empty()) {
                ngePos[j] = st.top();
            }
            st.push(j);
            j--;
        }
    }

public:

    ll sumOfLargest(vector<int>& nums,int n) {
        vector<int> pgePos(n,-1),ngePos(n,n);
        pge(nums,pgePos,n);
        nge(nums,ngePos,n);
        vector<int> psePos(n,-1),nsePos(n,n);
        pse(nums,psePos,n);
        nse(nums,nsePos,n);
        ll ans1 = 0;
        ll ans2 = 0;
        ll ans = 0;
        int j = 0;
        while(j<n) {
            int prevLen = j-pgePos[j];
            int nextLen = ngePos[j] - j;
            int prevLen2 = j - psePos[j];
            int nextLen2 = nsePos[j]-j;
            ans2 =  (prevLen2*nextLen2*nums[j]);
            ans1 = (prevLen*nextLen*nums[j]);
            ans+=(ans1-ans2);
            j++;
        }
        return ans;

    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        ll sumlarge = sumOfLargest(nums,n);
  

        ll ans = sumlarge;

        return ans;
        
    }
};