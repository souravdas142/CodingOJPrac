class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        deque<int> dq;
        vector<int> ans;
        int i = 0;
        while(j<n) {

           while(!dq.empty() && dq.back()<nums[j]) {
                dq.pop_back();
           }
           dq.push_back(nums[j]);

           if(j>=k-1) {
            ans.push_back(dq.front());
            if(nums[i]==dq.front())
                dq.pop_front();
            i++;
           }
           


            j++;
        }

        return ans;
        
    }
};