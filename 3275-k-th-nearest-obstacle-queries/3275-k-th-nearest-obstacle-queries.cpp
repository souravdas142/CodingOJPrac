class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {

        int n = queries.size();
        priority_queue<int> max_heap;
        vector<int> ans;

        for(int i = 0;i<n;i++) {
            int dist = abs(queries[i][0]) + abs(queries[i][1]);
            max_heap.push(dist);
            if(max_heap.size()==k) {

                ans.push_back(max_heap.top());
            }
            else if(max_heap.size()>k) {
                
                max_heap.pop();
                ans.push_back(max_heap.top());
            }
            else {
                ans.push_back(-1);
            }
        }


        return ans;
    }
};