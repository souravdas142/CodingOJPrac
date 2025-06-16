class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0;i<n;i++) {
            nums.push_back(nums[i]);
        }
        int m = n;
        n +=n;
        vector<int> ans(n,-1);
        stack<int> st;
        nums.pop_back();
    
        

        int j = n-1;
        while(j>=0) {
          
            while(!st.empty() && st.top()<=nums[j]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[j] = st.top();
                
            }
            st.push(nums[j]);
            j--;

        }


        return vector<int> (ans.begin(),ans.begin()+m);



    }
};