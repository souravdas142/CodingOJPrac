class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        // code here
        auto comp = [](vector<int>& a, vector<int>&b)->bool {
            return a[0]>b[0];
            
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(comp) > pq(comp);
        
        for(int i = 0;i<k;i++) {
            pq.push(arr[i]);
        }
        
        vector<int> ans;
        
        while(!pq.empty()) {
            ans.push_back(pq.top()[0]);
            vector<int> temp = pq.top();
            pq.pop();
            temp.erase(temp.begin());
            if(temp.size()>0)
                pq.push(temp);
        }
        
        return ans;
        
        
    }
};