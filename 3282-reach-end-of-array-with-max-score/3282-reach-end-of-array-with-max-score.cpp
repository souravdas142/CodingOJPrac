#define ll long long
ostream& operator<<(ostream& prll,vector<ll>& vec) {
    prll<<endl;
    for(auto a:vec) {
        prll<<a<<" ";
    }
    prll<<endl;
    return prll;
}

class Solution {
    void calcnge(vector<ll>& nge,vector<int>& nums,ll n) {
        stack<ll> st;
        ll i= n-1;
        while(i>=0) {

            while(!st.empty() && nums[i]>=nums[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                nge.push_back(-1);
            }
            else {
                nge.push_back(st.top());
            }
            st.push(i);
            i--;

        }
        reverse(nge.begin(),nge.end());
    }
public:
    long long findMaximumScore(vector<int>& nums) {

        ll n = nums.size();

        vector<ll> nge;

        calcnge(nge,nums,n);
       // cout<<nge<<endl;
        long long ans = 0;
        ll i = 0;
        while(i<n) {
            ll j = nge[i];

            if(j<0) {
                ans+=((n-i-1)*nums[i]);
                i = n;
            }
            else {
                ans+=((j-i)*nums[i]);
                i = j;
            }

            //ans+=((j<0)?(n-i)*nums[i]:( (j-i)*nums[i] ));

        }

        return ans;

        
    }
};