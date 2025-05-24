class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        int i = 0;
        int j = 0;
        deque<int> dq;
        vector<int> ans;
        while(j<n) {
            while(j<k) {
                if(arr[j]<0) {
                   dq.push_back(arr[j]); 
                }
                if(j==k-1) {
                    
                    if(dq.size()>0)
                        ans.push_back(dq.front());
                    else
                        ans.push_back(0);
                    
                }
                if(j==n-1) return ans;
                j++;
                
            }
            
            
            if(dq.size() > 0 && arr[i]==dq.front()) {
                dq.pop_front();
            }
            i++;
            if(arr[j]<0)
                dq.push_back(arr[j]);
            if(dq.size()>0)
                ans.push_back(dq.front());
            else
                ans.push_back(0);
            j++;
            
            
        }
        return ans;
    }
};